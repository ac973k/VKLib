#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

namespace VK {
    namespace Account {
        class Account : public QObject
        {
            Q_OBJECT

        public:
            explicit Account(QObject *parent = nullptr);
            ~Account();

            void ban(const QString &access_token, const QString &scopes);
            void changePassword(const QString &access_token, const QString &scopes);
            void getActiveOffers(const QString &access_token);
            void getActiveOffers(const QString &access_token, const QString &scopes);
            void getAppPermissions(const QString &access_token, const QString &scopes);
            void getBanned(const QString &access_token, const QString &scopes);
            void getBanned(const QString &access_token);
            void getCounters(const QString &access_token);
            void getCounters(const QString &access_token, const QString &scopes);
            void getInfo(const QString &access_token);
            void getInfo(const QString &access_token, const QString &scopes);
            void getProfileInfo(const QString &access_token);
            void getPushSettings(const QString &access_token, const QString &scopes);
            void registerDevice(const QString &access_token, const QString &scopes);
            void saveProfileInfo(const QString &access_token, const QString &scopes);
            void setInfo(const QString &access_token, const QString &scopes);
            void setOffline(const QString &access_token);
            void setOnline(const QString &access_token);
            void setPushSettings(const QString &access_token, const QString &scopes);
            void setSilenceMode(const QString &access_token, const QString &scopes);
            void unban(const QString &access_token, const QString &scopes);
            void unregisterDevice(const QString &access_token, const QString &scopes);

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
