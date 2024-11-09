#include "Wall.h"
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>

namespace VK {
    namespace Wall {
        Wall::Wall(QObject *parent)
            : QObject{parent} {

        }

        Wall::~Wall() {

        }

        QString Wall::post(const QString &access_token, const int &owner_id, const int &friends_only, const int &from_group, const QString &message, const QString &attachments,
                           const QString &services, const int &sign, const uint &publish_date, const QString &lat, const QString &longs, const uint &place_id, const uint &post_id,
                           const QString &guid, const int &mark_as_ads, const QString &link_title, const QString &link_photo_id, const int &close_comments, const int &donut_paid_duration,
                           const int &mute_notifications, const QString &copyright) {
            QUrl url("https://api.vk.com/method/wall.post");
            QUrlQuery query;
            query.addQueryItem("access_token", access_token);
            query.addQueryItem("owner_id", QString::number(owner_id));
            query.addQueryItem("friends_only", QString::number(friends_only));
            query.addQueryItem("from_group", QString::number(from_group));
            query.addQueryItem("message", message);
            query.addQueryItem("attachments", attachments);
            query.addQueryItem("services", services);
            query.addQueryItem("signed", QString::number(sign));
            query.addQueryItem("publish_date", QString::number(publish_date));
            query.addQueryItem("lat", lat);
            query.addQueryItem("long", longs);
            query.addQueryItem("place_id", QString::number(place_id));
            query.addQueryItem("post_id", QString::number(post_id));
            query.addQueryItem("guid", guid);
            query.addQueryItem("mark_as_ads", QString::number(mark_as_ads));
            query.addQueryItem("link_title", link_title);
            query.addQueryItem("link_photo_id", link_photo_id);
            query.addQueryItem("close_comments", QString::number(close_comments));
            query.addQueryItem("donut_paid_duration", QString::number(donut_paid_duration));
            query.addQueryItem("mute_notifications", QString::number(mute_notifications));
            query.addQueryItem("copyright", copyright);
            query.addQueryItem("v", "5.199");
            url.setQuery(query);

            QNetworkRequest request(url);
            QNetworkReply* reply = networkManager.get(request);
            QEventLoop eventLoop;
            connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
            eventLoop.exec();

            if (reply->error() != QNetworkReply::NoError) {
                qDebug() << "Error posting to wall:" << reply->errorString();
                reply->deleteLater();
                return QString();
            }

            QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
            QJsonObject responseObject = doc.object();
            reply->deleteLater();

            return QString::fromUtf8(QJsonDocument(responseObject).toJson());
        }

        QString Wall::post(const QString &access_token, const int &owner_id, const int &from_group, const QString &message, const QString &attachments) {
            QUrl url("https://api.vk.com/method/wall.post");
            QUrlQuery query;
            query.addQueryItem("access_token", access_token);
            query.addQueryItem("owner_id", QString::number(owner_id));
            query.addQueryItem("from_group", QString::number(from_group));
            query.addQueryItem("message", message);
            query.addQueryItem("attachments", attachments);
            query.addQueryItem("v", "5.199");
            url.setQuery(query);

            QNetworkRequest request(url);
            QNetworkReply* reply = networkManager.get(request);
            QEventLoop eventLoop;
            connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
            eventLoop.exec();

            if (reply->error() != QNetworkReply::NoError) {
                qDebug() << "Error posting to wall:" << reply->errorString();
                reply->deleteLater();
                return QString();
            }

            QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
            QJsonObject responseObject = doc.object();
            reply->deleteLater();

            return QString::fromUtf8(QJsonDocument(responseObject).toJson());
        }

        QString Wall::post(const QString &access_token, const int &owner_id, const int &from_group, const QString &message) {
            QUrl url("https://api.vk.com/method/wall.post");
            QUrlQuery query;
            query.addQueryItem("access_token", access_token);
            query.addQueryItem("owner_id", QString::number(owner_id));
            query.addQueryItem("from_group", QString::number(from_group));
            query.addQueryItem("message", message);
            query.addQueryItem("v", "5.199");
            url.setQuery(query);

            QNetworkRequest request(url);
            QNetworkReply* reply = networkManager.get(request);
            QEventLoop eventLoop;
            connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
            eventLoop.exec();

            if (reply->error() != QNetworkReply::NoError) {
                qDebug() << "Error posting to wall:" << reply->errorString();
                reply->deleteLater();
                return QString();
            }

            QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
            QJsonObject responseObject = doc.object();
            reply->deleteLater();

            return QString::fromUtf8(QJsonDocument(responseObject).toJson());
        }
    }
}
