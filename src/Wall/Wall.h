#ifndef WALL_H
#define WALL_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QUrlQuery>

namespace VK {
    namespace Wall {
        class Wall : public QObject
        {
            Q_OBJECT
        public:
            explicit Wall(QObject *parent = nullptr);
            ~Wall();

            QString post(const QString &access_token, const int &owner_id, const int &friends_only, const int &from_group, const QString &message, const QString &attachments,
                         const QString &services, const int &sign, const uint &publish_date, const QString &lat, const QString &longs, const uint &place_id, const uint &post_id,
                         const QString &guid, const int &mark_as_ads, const QString &link_title, const QString &link_photo_id, const int &close_comments, const int &donut_paid_duration,
                         const int &mute_notifications, const QString &copyright);

            QString post(const QString &access_token, const int &owner_id, const int &from_group, const QString &message);
            QString post(const QString &access_token, const int &owner_id, const int &from_group, const QString &message, const QString &attachments);

        private:
            QNetworkAccessManager networkManager;
            QString result;
            QEventLoop eventLoop;
        };
    }
}

#endif // WALL_H
