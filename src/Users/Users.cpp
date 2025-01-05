
#include "Users.h"

namespace VK {
    namespace Users {
        Users::Users(QObject *parent)
            : QObject{parent}
        {


        }

        Users::~Users() {

        }

        void Users::get(const QString &access_token, const QString &scopes) {
            QUrl link(QString("https://api.vk.com/method/users.get?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Users::Finished);
        }

        void Users::getFollowers(const QString &access_token, const QString &scopes) {
            QUrl link(QString("https://api.vk.com/method/users.getFollowers?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Users::Finished);
        }

        void Users::getSubscriptions(const QString &access_token, const QString &scopes) {
            QUrl link(QString("https://api.vk.com/method/users.getSubscriptions?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Users::Finished);
        }

        void Users::report(const QString &access_token, const QString &scopes) {
            QUrl link(QString("https://api.vk.com/method/users.report?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Users::Finished);
        }

        void Users::search(const QString &access_token, const QString &scopes) {
            QUrl link(QString("https://api.vk.com/method/users.search?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Users::Finished);
        }

        void Users::Finished() {
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
