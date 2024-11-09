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

            void getFriends(const QString &access_token, const QString &owner_id, const QString &count, const QString fields);
            void getSubscription(const QString &access_token, const QString &owner_id);
            void getSubscriptions(const QString &access_token, const QString fields, const QString &count);
            void isDon(const QString &access_token, const QString &owner_id);

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
