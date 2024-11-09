#ifndef STREAMING_H
#define STREAMING_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

namespace VK {
    namespace Streaming {
        class Streaming : public QObject {
            Q_OBJECT

            public:
                explicit Streaming(QObject *parent = nullptr);
                ~Streaming();

                void getServerUrl(const QString &access_token);
                void getStats(const QString &access_token, const QString &type, const QString &interval, const QString &start_time, const QString &end_time);
                void getStem(const QString &access_token, const QString &word);

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
