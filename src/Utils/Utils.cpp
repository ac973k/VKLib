#include "Utils.h"

namespace VK {
    namespace Utils {
        Utils::Utils(QObject *parent)
            : QObject{parent} {


        }

        Utils::~Utils() {

        }

        void Utils::checkLink(const QString &access_token, const QString &url)
        {
            QUrl link(QString("https://api.vk.com/method/utils.checkLink?access_token=%1&url=%2&v=5.199").arg(access_token).arg(url));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Utils::Finished);
        }

        void Utils::deleteFromLastShortened(const QString &access_token, const QString &key)
        {
            QUrl link(QString("https://api.vk.com/method/utils.deleteFromLastShortened?access_token=%1&key=%2&v=5.199").arg(access_token).arg(key));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Utils::Finished);
        }

        void Utils::getLastShortenedLinks(const QString &access_token, const QString &count)
        {
            QUrl link(QString("https://api.vk.com/method/utils.getLastShortenedLinks?access_token=%1&count=%2&v=5.199").arg(access_token).arg(count));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Utils::Finished);
        }

        void Utils::getLinkStats(const QString &access_token, const QString &key, const QString &interval, const QString &intervals_count, const QString &extended)
        {
            QUrl link(QString("https://api.vk.com/method/utils.getLinkStats?access_token=%1&key=%2&interval=%3&intervals_count=%4&extended=%5&v=5.199")
                          .arg(access_token)
                          .arg(key)
                          .arg(interval)
                          .arg(intervals_count)
                          .arg(extended));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Utils::Finished);
        }

        void Utils::getServerTime(const QString &access_token)
        {
            QUrl link(QString("https://api.vk.com/method/utils.getServerTime?access_token=%1&v=5.199").arg(access_token));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Utils::Finished);
        }

        void Utils::getShortLink(const QString &access_token, const QString &url, const QString &priv)
        {
            QUrl link(QString("https://api.vk.com/method/utils.getShortLink?access_token=%1&url=%2&priv=%3&v=5.199").arg(access_token).arg(url).arg(priv));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Utils::Finished);
        }

        void Utils::resolveScreenName(const QString &access_token, const QString &screen_name)
        {
            QUrl link(QString("https://api.vk.com/method/utils.resolveScreenName?access_token=%1&screen_name=%2&v=5.199").arg(access_token).arg(screen_name));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Utils::Finished);
        }

        void Utils::Finished() {
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
