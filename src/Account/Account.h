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


            void getProfileInfo(const QString &access_token);

        private:
            QNetworkAccessManager networkManager;
            QString result;

        signals:
            void banCompleted(const QString &result);
            void changePasswordCompleted(const QString &result);
            void getActiveOffersCompleted(const QString &result);
            void getAppPermissionsCompleted(const QString &result);
            void getBannedCompleted(const QString &result);


            void getProfileInfoCompleted(const QString &result);
        private slots:
            void banFinished();
            void changePasswordFinished();
            void getActiveOffersFinished();
            void getAppPermissionsFinished();
            void getBannedFinished();


            void getProfileInfoFinished();
        };
    }
}

#endif // ACCOUNT_H
