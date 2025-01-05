#ifndef STATUS_H
#define STATUS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

namespace VK {
    namespace Status {
        class Status : public QObject {
                Q_OBJECT

            public:
                explicit Status(QObject *parent = nullptr);
                ~Status();

                void get(const QString &access_token, const QString &scopes);
                void set(const QString &access_token, const QString &scopes);

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

#endif // STATUS_H
