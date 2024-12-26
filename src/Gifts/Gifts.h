#ifndef GIFTS_H
#define GIFTS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

namespace VK {
    namespace Gifts {
        class Gifts : public QObject {
            Q_OBJECT
            public:
                explicit Gifts(QObject *parent = nullptr);

                ~Gifts();

                void get(const QString &access_token, const QString &scopes);

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

#endif // GIFTS_H
