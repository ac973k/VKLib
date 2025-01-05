#include "Status.h"

namespace VK {
    namespace Status {
        Status::Status(QObject *parent)
            : QObject{parent} {


        }

        Status::~Status() {

        }

        void Status::get(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/status.get?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Status::Finished);
        }

        void Status::set(const QString &access_token, const QString &scopes)
        {
            QUrl link(QString("https://api.vk.com/method/status.set?access_token=%1&%2&v=5.199").arg(access_token).arg(scopes));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Status::Finished);
        }

        void Status::Finished() {
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
