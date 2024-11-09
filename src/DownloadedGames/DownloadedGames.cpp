#include "DownloadedGames.h"

namespace VK {
    namespace DownloadedGames {
        DownloadedGames::DownloadedGames(QObject *parent)
            : QObject{parent} {

        }

        DownloadedGames::~DownloadedGames()
        {

        }

        void DownloadedGames::getPaidStatus(const QString &access_token, const QString &user_id)
        {
            QUrl link(QString("https://api.vk.com/method/downloadedGames.getPaidStatus?access_token=%1&user_id=%2&v=5.199").arg(access_token).arg(user_id));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &DownloadedGames::Finished);
        }

        void DownloadedGames::Finished() {
            QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
            if (!reply) {
                return;
            }

            if (reply->error() != QNetworkReply::NoError) {
                result = reply->errorString();
                qDebug() << "Error:" << result;
                emit Completed(result);
                reply->deleteLater();
                return;
            }

            result = reply->readAll();
            emit Completed(result);
            reply->deleteLater();
        }

    }
}
