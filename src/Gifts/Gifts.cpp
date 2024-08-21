#include "Gifts.h"

namespace VK {
    namespace Gifts {
        Gifts::Gifts(QObject *parent)
            : QObject{parent} {

        }

        Gifts::~Gifts()
        {

        }

        void Gifts::get(const QString &access_token, const QString &user_id, const QString &count)
        {
            QUrl link(QString("https://api.vk.com/method/gifts.get?access_token=%1&user_id=%2&count=%3&v=5.131").arg(access_token).arg(user_id).arg(count));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Gifts::Finished);
        }

        void Gifts::Finished() {
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
