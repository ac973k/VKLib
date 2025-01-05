#ifndef USERS_H
#define USERS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

namespace VK {
    namespace Users {
        class Users : public QObject
        {
            Q_OBJECT
            public:
                explicit Users(QObject *parent = nullptr);
                ~Users();

                void get(const QString &access_token, const QString &scopes);
                void getFollowers(const QString &access_token, const QString &scopes);
                void getSubscriptions(const QString &access_token, const QString &scopes);
                void report(const QString &access_token, const QString &scopes);
                void search(const QString &access_token, const QString &scopes);

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

#endif // USERS_H
