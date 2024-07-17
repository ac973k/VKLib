#include "Account.h"

namespace VK {
    namespace Account {
        Account::Account(QObject *parent)
            : QObject{parent}
        {

        }

        Account::~Account() {

        }

        void Account::ban(const QString &access_token, const QString &owner_id) {
            QUrl link(QString("https://api.vk.com/method/account.ban?access_token=%1&owner_id=%2&v=5.131").arg(access_token).arg(owner_id));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::banFinished);
        }

        void Account::banFinished() {
            QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
            if (!reply) {
                return;
            }

            if (reply->error() != QNetworkReply::NoError) {
                result = reply->errorString();
                qDebug() << "Error:" << result;
                emit banCompleted(result);
                reply->deleteLater();
                return;
            }

            result = reply->readAll();
            emit banCompleted(result);
            reply->deleteLater();
        }

        void Account::changePassword(const QString &access_token, const QString &restore_sid, const QString &change_password_hash, const QString &old_password, const QString &new_password) {
            QUrl link(QString("https://api.vk.com/method/account.changePassword?access_token=%1&restore_sid=%2&change_password_hash=%3&old_password=%4&new_password=%5&v=5.131")
                          .arg(access_token)
                          .arg(restore_sid)
                          .arg(change_password_hash)
                          .arg(old_password)
                          .arg(new_password));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::changePasswordFinished);
        }

        void Account::changePassword(const QString &access_token, const QString &old_password, const QString &new_password) {
            QUrl link(QString("https://api.vk.com/method/account.changePassword?access_token=%1&old_password=%2&new_password=%3&v=5.131")
                          .arg(access_token)
                          .arg(old_password)
                          .arg(new_password));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::changePasswordFinished);
        }

        void Account::changePasswordFinished() {
            QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
            if (!reply) {
                return;
            }

            if (reply->error() != QNetworkReply::NoError) {
                result = reply->errorString();
                qDebug() << "Error:" << result;
                emit changePasswordCompleted(result);
                reply->deleteLater();
                return;
            }

            result = reply->readAll();
            emit changePasswordCompleted(result);
            reply->deleteLater();
        }

        void Account::getActiveOffers(const QString &access_token) {
            QUrl link(QString("https://api.vk.com/method/account.getActiveOffers?access_token=%1&v=5.131").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::getActiveOffersFinished);
        }

        void Account::getActiveOffers(const QString &access_token, const QString &offset, const QString &count) {
            QUrl link(QString("https://api.vk.com/method/account.getActiveOffers?access_token=%1&offset=%2&count=%3&v=5.131").arg(access_token).arg(offset).arg(count));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::getActiveOffersFinished);
        }

        void Account::getActiveOffersFinished() {
            QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
            if (!reply) {
                return;
            }

            if (reply->error() != QNetworkReply::NoError) {
                result = reply->errorString();
                qDebug() << "Error getting info:" << result;
                emit getActiveOffersCompleted(result);
                reply->deleteLater();
                return;
            }

            result = reply->readAll();
            emit getActiveOffersCompleted(result);
            reply->deleteLater();
        }

        void Account::getAppPermissions(const QString &access_token, const QString &user_id) {
            QUrl link(QString("https://api.vk.com/method/account.ggetAppPermissions?access_token=%1&user_id=%2&v=5.131").arg(access_token).arg(user_id));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::getAppPermissionsFinished);
        }

        void Account::getAppPermissionsFinished() {
            QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
            if (!reply) {
                return;
            }

            if (reply->error() != QNetworkReply::NoError) {
                result = reply->errorString();
                qDebug() << "Error getting info:" << result;
                emit getAppPermissionsCompleted(result);
                reply->deleteLater();
                return;
            }

            result = reply->readAll();
            emit getAppPermissionsCompleted(result);
            reply->deleteLater();
        }

        void Account::getBanned(const QString &access_token, const QString &offset, const QString &count) {
            QUrl link(QString("https://api.vk.com/method/account.getBanned?access_token=%1&offset=%2&count=%3&v=5.131").arg(access_token).arg(offset).arg(count));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::getBannedFinished);
        }

        void Account::getBanned(const QString &access_token) {
            QUrl link(QString("https://api.vk.com/method/account.getBanned?access_token=%1&v=5.131").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::getBannedFinished);
        }

        void Account::getBannedFinished() {
            QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
            if (!reply) {
                return;
            }

            if (reply->error() != QNetworkReply::NoError) {
                result = reply->errorString();
                qDebug() << "Error getting info:" << result;
                emit getBannedCompleted(result);
                reply->deleteLater();
                return;
            }

            result = reply->readAll();
            emit getBannedCompleted(result);
            reply->deleteLater();
        }



        void Account::getProfileInfo(const QString &access_token) {
            QUrl link(QString("https://api.vk.com/method/account.getProfileInfo?access_token=%1&v=5.131").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::getProfileInfoFinished);
        }

        void Account::getProfileInfoFinished() {
            QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
            if (!reply) {
                return;
            }

            if (reply->error() != QNetworkReply::NoError) {
                result = reply->errorString();
                qDebug() << "Error getting info:" << result;
                emit getProfileInfoCompleted(result);
                reply->deleteLater();
                return;
            }

            result = reply->readAll();
            emit getProfileInfoCompleted(result);
            reply->deleteLater();
        }
    }
}
