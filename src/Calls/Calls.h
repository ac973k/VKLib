#ifndef CALLS_H
#define CALLS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

namespace VK {
    namespace Calls {
        class Calls : public QObject {
            Q_OBJECT

            public:
                explicit Calls(QObject *parent = nullptr);

                ~Calls();

                void forceFinish(const QString &access_token, const QString &scopes);
                void start(const QString &access_token, const QString &scopes);

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

#endif // CALLS_H
