#ifndef DONUT_H
#define DONUT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

namespace VK {
    namespace Donut {
        class Donut : public QObject {
            Q_OBJECT
            public:
            explicit Donut(QObject *parent = nullptr);

            ~Donut();

            void getFriends(const QString &access_token, const QString &scopes);
            void getSubscription(const QString &access_token, const QString &scopes);
            void getSubscriptions(const QString &access_token, const QString &scopes);
            void isDon(const QString &access_token, const QString &scopes);

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

#endif // DONUT_H
