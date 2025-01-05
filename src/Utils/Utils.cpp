#include "Utils.h"

namespace VK {
    namespace Utils {
        Utils::Utils(QObject *parent)
            : QObject{parent} {


        }

        Utils::~Utils() {

        }

        void Utils::checkLink(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/utils.checkLink?access_token=%1%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Utils::Finished);
        }

        void Utils::deleteFromLastShortened(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/utils.deleteFromLastShortened?access_token=%1%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Utils::Finished);
        }

        void Utils::getLastShortenedLinks(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/utils.getLastShortenedLinks?access_token=%1%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Utils::Finished);
        }

        void Utils::getLinkStats(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/utils.getLinkStats?access_token=%1%2&v=5.199").arg(access_token).arg(scopes));
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

        void Utils::getShortLink(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/utils.getShortLink?access_token=%1%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Utils::Finished);
        }

        void Utils::resolveScreenName(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/utils.resolveScreenName?access_token=%1%2&v=5.199").arg(access_token).arg(scopes));
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
