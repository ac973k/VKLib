#include "Status.h"

namespace VK {
    namespace Status {
        Status::Status(QObject *parent)
            : QObject{parent} {


        }

        Status::~Status() {

        }

        void Status::getUser(const QString &access_token, const QString &user_id)
        {
            QUrl link(QString("https://api.vk.com/method/status.get?access_token=%1&user_id=%2&v=5.131").arg(access_token).arg(user_id));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Status::Finished);
        }

        void Status::getGroup(const QString &access_token, const QString &group_id)
        {
            QUrl link(QString("https://api.vk.com/method/status.get?access_token=%1&group_id=%2&v=5.131").arg(access_token).arg(group_id));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Status::Finished);
        }

        void Status::set(const QString &access_token, const QString &text, const QString &group_id)
        {
            QUrl link(QString("https://api.vk.com/method/status.set?access_token=%1&text=%2&group_id=%3&v=5.131").arg(access_token).arg(text).arg(group_id));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Status::Finished);
        }

        void Status::Finished() {
            QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
            if (!reply) {
                return;
            }

            if (reply->error() != QNetworkReply::NoError) {
                result = reply->errorString();
                qDebug() << "Error:" << result;
                emit Completed(result);
                reply->deleteLater();
                return;
            }

            result = reply->readAll();
            emit Completed(result);
            reply->deleteLater();
        }
    }
}
