#include "Photos.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include <QHttpMultiPart>
#include <QFile>
#include <QDebug>

namespace VK {
    namespace Photos {
        Photos::Photos(QObject *parent)
            : QObject{parent} {

        }

        Photos::~Photos() {

        }

        QStringList Photos::getWallUploadServerSync(const QString &accessToken, const QString &groupId) {
            this->accessToken = accessToken;
            this->groupId = groupId;

            // Step 1: Get upload URL
            QUrl url(QString("https://api.vk.com/method/photos.getWallUploadServer?group_id=%1&access_token=%2&v=5.131").arg(groupId).arg(accessToken));
            qDebug() << "url with token: " << url;
            QNetworkRequest request(url);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Photos::onGetWallUploadServer);

            eventLoop.exec(); // Wait for the network request to complete
            return result;
        }

        void Photos::onGetWallUploadServer() {
            QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
            if (!reply) {
                eventLoop.quit();
                return;
            }

            if (reply->error() != QNetworkReply::NoError) {
                qDebug() << "Error getting upload URL:" << reply->errorString();
                reply->deleteLater();
                eventLoop.quit();
                return;
            }

            QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
            QJsonObject response = doc.object().value("response").toObject();
            uploadUrl = response.value("upload_url").toString();
            qDebug() << "Upload URL received:" << uploadUrl;
            reply->deleteLater();

            // Step 2: Upload image
            QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
            QHttpPart imagePart;
            imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/png"));
            imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"photo\"; filename=\"" + filename + "\""));
            QFile *file = new QFile(imagePath);
            if (!file->open(QIODevice::ReadOnly)) {
                qDebug() << "Error opening file for upload:" << file->errorString();
                delete file;
                delete multiPart;
                eventLoop.quit();
                return;
            }
            imagePart.setBodyDevice(file);
            file->setParent(multiPart); // Ensure file is deleted with multiPart
            multiPart->append(imagePart);

            QNetworkRequest requestUpload((QUrl(uploadUrl)));
            QNetworkReply *uploadReply = networkManager.post(requestUpload, multiPart);
            connect(uploadReply, &QNetworkReply::finished, this, &Photos::onUploadImageFinished);
            multiPart->setParent(uploadReply); // Ensure multiPart is deleted with reply
        }

        void Photos::onUploadImageFinished()
        {
            QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
            if (!reply) {
                eventLoop.quit();
                return;
            }

            if (reply->error() != QNetworkReply::NoError) {
                qDebug() << "Error uploading image:" << reply->errorString();
                reply->deleteLater();
                eventLoop.quit();
                return;
            }

            QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
            QJsonObject response = doc.object();
            qDebug() << "Upload response:" << response;

            // Extracting the server, photo, and hash values
            if (response.contains("server") && response.contains("photo") && response.contains("hash")) {
                server = QString::number(response.value("server").toInt());
                photo = response.value("photo").toString();
                hash = response.value("hash").toString();
                qDebug() << "Image uploaded. Server:" << server << " Photo:" << photo << " Hash:" << hash;

                // Step 3: Save photo
                QUrl url(QString("https://api.vk.com/method/photos.saveWallPhoto?group_id=%1&photo=%2&server=%3&hash=%4&access_token=%5&v=5.131")
                             .arg(groupId)
                             .arg(photo)
                             .arg(server)
                             .arg(hash)
                             .arg(accessToken));
                qDebug() << "Save photo URL:" << url.toString();
                QNetworkRequest request(url);
                QNetworkReply *savePhotoReply = networkManager.get(request);
                connect(savePhotoReply, &QNetworkReply::finished, this, &Photos::onSavePhotoFinished);
            } else {
                qDebug() << "Missing expected fields in upload response.";
                eventLoop.quit();
            }

            reply->deleteLater();
        }

        void Photos::onSavePhotoFinished()
        {
            QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
            if (!reply) {
                eventLoop.quit();
                return;
            }

            if (reply->error() != QNetworkReply::NoError) {
                qDebug() << "Error saving photo:" << reply->errorString();
                reply->deleteLater();
                eventLoop.quit();
                return;
            }

            QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
            QJsonObject responseObject = doc.object();
            QJsonArray responseArray = responseObject.value("response").toArray();
            if (!responseArray.isEmpty()) {
                QJsonObject response = responseArray.first().toObject();
                QString photoId = QString::number(response.value("id").toInt());
                QString ownerId = QString::number(response.value("owner_id").toInt());

                if (!photoId.isEmpty() && !ownerId.isEmpty()) {
                    result << photoId << ownerId;
                    qDebug() << "Photo saved. Photo ID:" << photoId << " Owner ID:" << ownerId;
                } else {
                    qDebug() << "Error: save photo response does not contain photo_id or owner_id.";
                    qDebug() << "Full response:" << doc.toJson(QJsonDocument::Indented);
                }
            }

            eventLoop.quit();
            reply->deleteLater();
        }
    }
}
