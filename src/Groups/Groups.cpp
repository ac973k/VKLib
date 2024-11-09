#include "Groups.h"

#include <QUrlQuery>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace VK {
    namespace Groups {
        Groups::Groups(QObject *parent)
            : QObject{parent}
        {

        }

        Groups::~Groups() {

        }

        QString Groups::getById(const QString &access_token, const QString &group_ids, const QString &fields) {
            QUrl link(QString("https://api.vk.com/method/groups.getById?group_ids=%1&fields=%2&access_token=%3&v=5.199").arg(group_ids).arg(fields).arg(access_token));
            qDebug() << "url with token: " << link;
            QNetworkRequest request(link);
            QNetworkReply* replys = networkManager.get(request);
            connect(replys, &QNetworkReply::finished, this, &Groups::getGroupInfoFinished);

            eventLoop.exec(); // Wait for the network request to complete
            return result;
        }

        void Groups::getGroupInfoFinished() {
            QNetworkReply *replys = qobject_cast<QNetworkReply*>(sender());
            if (!replys) return;

            if (replys->error() != QNetworkReply::NoError) {
                qDebug() << "Error getting info:" << replys->errorString();
                replys->deleteLater();
                return;
            }

            result = replys->readAll();

            eventLoop.quit();
            replys->deleteLater();
        }
    }
}
