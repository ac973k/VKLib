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
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::changePassword(const QString &access_token, const QString &old_password, const QString &new_password) {
            QUrl link(QString("https://api.vk.com/method/account.changePassword?access_token=%1&old_password=%2&new_password=%3&v=5.131")
                          .arg(access_token)
                          .arg(old_password)
                          .arg(new_password));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getActiveOffers(const QString &access_token) {
            QUrl link(QString("https://api.vk.com/method/account.getActiveOffers?access_token=%1&v=5.131").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getActiveOffers(const QString &access_token, const QString &offset, const QString &count) {
            QUrl link(QString("https://api.vk.com/method/account.getActiveOffers?access_token=%1&offset=%2&count=%3&v=5.131").arg(access_token).arg(offset).arg(count));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getAppPermissions(const QString &access_token, const QString &user_id) {
            QUrl link(QString("https://api.vk.com/method/account.ggetAppPermissions?access_token=%1&user_id=%2&v=5.131").arg(access_token).arg(user_id));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getBanned(const QString &access_token, const QString &offset, const QString &count) {
            QUrl link(QString("https://api.vk.com/method/account.getBanned?access_token=%1&offset=%2&count=%3&v=5.131").arg(access_token).arg(offset).arg(count));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getBanned(const QString &access_token) {
            QUrl link(QString("https://api.vk.com/method/account.getBanned?access_token=%1&v=5.131").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getCounters(const QString &access_token)
        {
            QUrl link(QString("https://api.vk.com/method/account.getCounters?access_token=%1&v=5.131").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getCounters(const QString &access_token, const QString &filter)
        {
            QUrl link(QString("https://api.vk.com/method/account.getCounters?access_token=%1&filter=%2&v=5.131").arg(access_token).arg(filter));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getInfo(const QString &access_token)
        {
            QUrl link(QString("https://api.vk.com/method/account.getInfo?access_token=%1&v=5.131").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getInfo(const QString &access_token, const QString &fields)
        {
            QUrl link(QString("https://api.vk.com/method/account.getCounters?access_token=%1&fields=%2&v=5.131").arg(access_token).arg(fields));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getProfileInfo(const QString &access_token) {
            QUrl link(QString("https://api.vk.com/method/account.getProfileInfo?access_token=%1&v=5.131").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::getPushSettings(const QString &access_token, const QString &device_id)
        {
            QUrl link(QString("https://api.vk.com/method/account.getPushSettings?access_token=%1&device_id=%2&v=5.131").arg(access_token).arg(device_id));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::registerDevice(const QString &access_token, const QString &device_model, const QString &device_year, const QString &device_id, const QString &system_version, const QString &settings)
        {
            QUrl link(QString("https://api.vk.com/method/account.registerDevice?access_token=%1&device_model=%2&device_year=%3&device_id=%4&system_version=%5&settings=%6&v=5.131")
                          .arg(access_token)
                          .arg(device_model)
                          .arg(device_year)
                          .arg(device_id)
                          .arg(system_version)
                          .arg(settings));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::saveProfileInfo(const QString &access_token, const QString &fields)
        {
            // fileds строка в которую добавляются значения из https://dev.vk.com/ru/method/account.saveProfileInfo
            // Пример строки: Нам нужно изменить только имя и пол, то строка будет такого вида: "&first_name=Сергей&sex=2
            QUrl link(QString("https://api.vk.com/method/account.saveProfileInfo?access_token=%1" + fields + "&v=5.131").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::setInfo(const QString &access_token, const QString &name, const QString &value)
        {
            QUrl link(QString("https://api.vk.com/method/account.setInfo?access_token=%1&name=%2&value=%3&v=5.131").arg(access_token).arg(name).arg(value));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::setOffline(const QString &access_token)
        {
            QUrl link(QString("https://api.vk.com/method/account.setOffline?access_token=%1&v=5.131").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::setOnline(const QString &access_token)
        {
            QUrl link(QString("https://api.vk.com/method/account.setOnline?access_token=%1&v=5.131").arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::setPushSettings(const QString &access_token, const QString &device_id, const QString &settings, const QString &key, const QString &value)
        {
            QUrl link(QString("https://api.vk.com/method/account.setPushSettings?access_token=%1&device_id=%2&settings=%3&key=%4&value=%5&v=5.131")
                          .arg(access_token)
                          .arg(device_id)
                          .arg(settings)
                          .arg(key)
                          .arg(value));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::setSilenceMode(const QString &access_token, const QString &device_id, const QString &time, const QString &peer_id, const QString &sound)
        {
            QUrl link(QString("https://api.vk.com/method/account.setSilenceMode?access_token=%1&device_id=%2&time=%3&peer_id=%4&sound=%5&v=5.131")
                          .arg(access_token)
                          .arg(device_id)
                          .arg(time)
                          .arg(peer_id)
                          .arg(sound));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::unban(const QString &access_token, const QString &owner_id)
        {
            QUrl link(QString("https://api.vk.com/method/account.unban?access_token=%1&owner_id=%2&v=5.131").arg(access_token).arg(owner_id));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }

        void Account::unregisterDevice(const QString &access_token, const QString &device_id)
        {
            QUrl link(QString("https://api.vk.com/method/account.unregisterDevice?access_token=%1&device_id=%2&v=5.131").arg(access_token).arg(device_id));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Account::Finished);
        }
    }
}
