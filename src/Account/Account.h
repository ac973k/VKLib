#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

namespace VK {
    namespace Account {
        class Account : public QObject
        {
            Q_OBJECT

        public:
            explicit Account(QObject *parent = nullptr);
            ~Account();

            void ban(const QString &access_token, const QString &owner_id);
            void changePassword(const QString &access_token, const QString &restore_sid, const QString &change_password_hash, const QString &old_password, const QString &new_password);
            void changePassword(const QString &access_token, const QString &old_password, const QString &new_password);
            void getActiveOffers(const QString &access_token);
            void getActiveOffers(const QString &access_token, const QString &offset, const QString &count);
            void getAppPermissions(const QString &access_token, const QString &user_id);
            void getBanned(const QString &access_token, const QString &offset, const QString &count);
            void getBanned(const QString &access_token);
            void getCounters(const QString &access_token);
            void getCounters(const QString &access_token, const QString &filter);
            void getInfo(const QString &access_token);
            void getInfo(const QString &access_token, const QString &fields);
            void getProfileInfo(const QString &access_token);
            void getPushSettings(const QString &access_token, const QString &device_id);
            void registerDevice(const QString &access_token, const QString &device_model, const QString &device_year, const QString &device_id, const QString &system_version, const QString &settings);
            void saveProfileInfo(const QString &access_token, const QString &fields);
            void setInfo(const QString &access_token, const QString &name, const QString &value);
            void setOffline(const QString &access_token);
            void setOnline(const QString &access_token);

        private:
            QNetworkAccessManager networkManager;
            QString result;

        signals:
            void Completed(const QString &result);

        private slots:
            void Finished();
        };
    }
}

#endif // ACCOUNT_H
