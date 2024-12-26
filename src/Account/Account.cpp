#include "Account.h"

namespace VK {
    namespace Account {
        Account::Account(QObject *parent)
            : QObject{parent}
        {

        }

        Account::~Account() {

        }

        void Account::ban(const QString &access_token, const QString &scopes) {
            QUrl link(QString("https://api.vk.com/method/account.ban?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::Finished() {
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

        void Account::changePassword(const QString &access_token, const QString &scopes) {
            QUrl link(QString("https://api.vk.com/method/account.changePassword?access_token=%1&%2&v=5.199")
                          .arg(access_token)
                          .arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getActiveOffers(const QString &access_token) {
            QUrl link(QString("https://api.vk.com/method/account.getActiveOffers?access_token=%1&v=5.199").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getActiveOffers(const QString &access_token, const QString &scopes) {
            QUrl link(QString("https://api.vk.com/method/account.getActiveOffers?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getAppPermissions(const QString &access_token, const QString &scopes) {
            QUrl link(QString("https://api.vk.com/method/account.ggetAppPermissions?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getBanned(const QString &access_token, const QString &scopes) {
            QUrl link(QString("https://api.vk.com/method/account.getBanned?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getBanned(const QString &access_token) {
            QUrl link(QString("https://api.vk.com/method/account.getBanned?access_token=%1&v=5.199").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getCounters(const QString &access_token)
        {
            QUrl link(QString("https://api.vk.com/method/account.getCounters?access_token=%1&v=5.199").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getCounters(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/account.getCounters?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getInfo(const QString &access_token)
        {
            QUrl link(QString("https://api.vk.com/method/account.getInfo?access_token=%1&v=5.199").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getInfo(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/account.getCounters?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getProfileInfo(const QString &access_token) {
            QUrl link(QString("https://api.vk.com/method/account.getProfileInfo?access_token=%1&v=5.199").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getPushSettings(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/account.getPushSettings?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::registerDevice(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/account.registerDevice?access_token=%1&%2&v=5.199")
                          .arg(access_token)
                          .arg(scopes));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::saveProfileInfo(const QString &access_token, const QString &scopes)
        {
            // fileds строка в которую добавляются значения из https://dev.vk.com/ru/method/account.saveProfileInfo
            // Пример строки: Нам нужно изменить только имя и пол, то строка будет такого вида: "&first_name=Сергей&sex=2
            QUrl link(QString("https://api.vk.com/method/account.saveProfileInfo?access_token=%1&%2&v=5.199").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::setInfo(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/account.setInfo?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::setOffline(const QString &access_token)
        {
            QUrl link(QString("https://api.vk.com/method/account.setOffline?access_token=%1&v=5.199").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::setOnline(const QString &access_token)
        {
            QUrl link(QString("https://api.vk.com/method/account.setOnline?access_token=%1&v=5.199").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::setPushSettings(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/account.setPushSettings?access_token=%1&%2&v=5.199")
                          .arg(access_token)
                          .arg(scopes));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::setSilenceMode(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/account.setSilenceMode?access_token=%1&%2&v=5.199")
                          .arg(access_token)
                          .arg(scopes));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::unban(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/account.unban?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::unregisterDevice(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/account.unregisterDevice?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }
    }
}
