#include "Calls.h"

namespace VK {
    namespace Calls {
        Calls::Calls(QObject *parent)
            : QObject{parent} {

        }

        Calls::~Calls()
        {

        }

        void Calls::forceFinish(const QString &access_token, const QString &call_id)
        {
            QUrl link(QString("https://api.vk.com/method/calls.forceFinish?access_token=%1&call_id=%2&v=5.199").arg(access_token).arg(call_id));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Calls::Finished);
        }

        void Calls::start(const QString &access_token, const QString &group_id)
        {
            QUrl link(QString("https://api.vk.com/method/calls.start?access_token=%1&group_id=%2&v=5.199").arg(access_token).arg(group_id));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Calls::Finished);
        }

        void Calls::Finished() {
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
