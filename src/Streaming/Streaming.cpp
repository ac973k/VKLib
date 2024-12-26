#include "Streaming.h"

namespace VK {
    namespace Streaming {
        Streaming::Streaming(QObject *parent)
            : QObject{parent} {

        }
        Streaming::~Streaming() {

        }

        void Streaming::getServerUrl(const QString &access_token) {
            QUrl link(QString("https://api.vk.com/method/streaming.getServerUrl?access_token=%1&v=5.199").arg(access_token));
            qDebug() << "full url: " << link;

            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Streaming::Finished);
        }

        void Streaming::getStats(const QString &access_token, const QString &scopes) {
            QUrl link(QString("https://api.vk.com/method/streaming.getStats?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;

            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Streaming::Finished);
        }

        void Streaming::getStem(const QString &access_token, const QString &scopes) {
            QUrl link(QString("https://api.vk.com/method/streaming.getStem?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;

            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Streaming::Finished);
        }

        void Streaming::Finished() {
            QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
            if (!reply) {
                return;
            }

            if (reply->error() != QNetworkReply::NoError) {
                result = reply->errorString();
                qDebug() << "Error:" << result;
                emit completed(result);
                reply->deleteLater();
                return;
            }

            if (reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() != 200) {
                result = QString("HTTP Error: %1").arg(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt());
                qDebug() << result;
                emit completed(result);
                reply->deleteLater();
                return;
            }

            result = reply->readAll();
            emit completed(result);
            reply->deleteLater();
        }
    }
}
