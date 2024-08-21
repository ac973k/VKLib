#include "Donut.h"

namespace VK {
    namespace Donut {
        Donut::Donut(QObject *parent)
            : QObject{parent} {

        }

        Donut::~Donut() {

        }

        void Donut::getFriends(const QString &access_token, const QString &owner_id, const QString &count, const QString fields)
        {
            QUrl link(QString("https://api.vk.com/method/donut.getFriends?access_token=%1&owner_id=%2&count=%3&fields=%4&v=5.131").arg(access_token).arg(owner_id).arg(count).arg(fields));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Donut::Finished);
        }

        void Donut::getSubscription(const QString &access_token, const QString &owner_id)
        {
            QUrl link(QString("https://api.vk.com/method/donut.getSubscription?access_token=%1&owner_id=%2&v=5.131").arg(access_token).arg(owner_id));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Donut::Finished);
        }

        void Donut::getSubscriptions(const QString &access_token, const QString fields, const QString &count)
        {
            QUrl link(QString("https://api.vk.com/method/donut.getSubscriptions?access_token=%1&fields=%2&count=%3&v=5.131").arg(access_token).arg(fields).arg(count));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Donut::Finished);
        }

        void Donut::isDon(const QString &access_token, const QString &owner_id)
        {
            QUrl link(QString("https://api.vk.com/method/donut.isDon?access_token=%1&owner_id=%2&v=5.131").arg(access_token).arg(owner_id));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Donut::Finished);
        }

        void Donut::Finished() {
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


