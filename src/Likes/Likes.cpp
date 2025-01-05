#include "Likes.h"

namespace VK {
    namespace Likes {
        Likes::Likes(QObject *parent)
            : QObject{parent} {

        }

        Likes::~Likes()
        {

        }

        void Likes::add(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/likes.add?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Likes::Finished);
        }

        void Likes::del(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/likes.delete?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Likes::Finished);
        }

        void Likes::getList(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/likes.getList?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Likes::Finished);
        }

        void Likes::isLiked(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/likes.isLiked?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Likes::Finished);
        }

        void Likes::Finished() {
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
