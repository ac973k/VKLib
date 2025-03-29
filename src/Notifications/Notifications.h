#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

namespace VK {
    namespace Notifications {
        class Notifications : public QObject {
            Q_OBJECT
            public:
                explicit Notifications(QObject *parent = nullptr);
                ~Notifications();

                void get(const QString &access_token, const QString &scopes);
                void markAsViewed(const QString &access_token);
                void sendMessage(const QString &access_token, const QString &scopes);

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



#endif // NOTIFICATIONS_H
