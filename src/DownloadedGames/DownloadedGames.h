#ifndef DOWNLOADEDGAMES_H
#define DOWNLOADEDGAMES_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

namespace VK {
    namespace DownloadedGames {
        class DownloadedGames : public QObject {
            Q_OBJECT
            public:
                explicit DownloadedGames(QObject *parent = nullptr);

                ~DownloadedGames();

                void getPaidStatus(const QString &access_token, const QString &user_id);

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

#endif // DOWNLOADEDGAMES_H
