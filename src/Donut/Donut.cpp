#include "Donut.h"

namespace VK {
    namespace Donut {
        Donut::Donut(QObject *parent)
            : QObject{parent} {

        }

        Donut::~Donut() {

        }

        /*Получаем список друзей, которые являются платными подписчиками*/
        void Donut::getFriends(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/donut.getFriends?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Donut::Finished);
        }

        /*Поучаем рандомного платного подписчика*/
        void Donut::getSubscription(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/donut.getSubscription?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Donut::Finished);
        }

        /*Получаем платных подписчиков*/
        void Donut::getSubscriptions(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/donut.getSubscriptions?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Donut::Finished);
        }

        /*Проверяем, является ли пользователь донатером*/
        void Donut::isDon(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/donut.isDon?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
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


