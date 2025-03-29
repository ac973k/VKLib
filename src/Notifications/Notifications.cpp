#include "Notifications.h"

namespace VK {
    namespace Notifications {
        Notifications::Notifications(QObject *parent)
            : QObject{parent} {

        }

        Notifications::~Notifications() {

        }

        void Notifications::get(const QString &access_token, const QString &scopes) {
            QUrl link(QString("https://api.vk.com/method/notifications.get?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Notifications::Finished);
        }

        void Notifications::markAsViewed(const QString &access_token) {
            QUrl link(QString("https://api.vk.com/method/notifications.markAsViewed?access_token=%1&v=5.199").arg(access_token));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Notifications::Finished);
        }

        void Notifications::sendMessage(const QString &access_token, const QString &scopes) {
            QUrl link(QString("https://api.vk.com/method/notifications.sendMessage?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Notifications::Finished);
        }

        void Notifications::Finished() {
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
