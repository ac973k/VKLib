#include "Stats.h"

namespace VK {
    namespace Stats {
        Stats::Stats(QObject *parent)
            : QObject{parent} {


        }

        Stats::~Stats() {

        }

        void Stats::get(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/stats.get?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Stats::Finished);
        }

        void Stats::getPostReach(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/stats.getPostReach?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Stats::Finished);
        }

        void Stats::trackVisitor(const QString &access_token)
        {
            QUrl link(QString("https://api.vk.com/method/stats.trackVisitor?access_token=%1&v=5.199").arg(access_token));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Stats::Finished);
        }

        void Stats::Finished() {
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
