#ifndef STREAMING_H
#define STREAMING_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

namespace VK {
    namespace Streaming {
        class Streaming : public QObject {
            Q_OBJECT

            public:
                explicit Streaming(QObject *parent = nullptr);
                ~Streaming();

                void getServerUrl(const QString &access_token);
                void getStats(const QString &access_token, const QString &scopes);
                void getStem(const QString &access_token, const QString &scopes);

            private:
                QNetworkAccessManager networkManager;
                QString result;

            signals:
                void completed(const QString &result);

            private slots:
                void Finished();
        };
    }
}

#endif // STREAMING_H
