#ifndef PHOTOS_H
#define PHOTOS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QStringList>
#include <QEventLoop>
#include <QUrlQuery>

namespace VK {
    namespace Photos {
        class Photos : public QObject
        {
            Q_OBJECT
        public:
            explicit Photos(QObject *parent = nullptr);
            ~Photos();
            QStringList getWallUploadServerSync(const QString &accessToken, const QString &groupId);

        private slots:
            void onGetWallUploadServer();
            void onUploadImageFinished();
            void onSavePhotoFinished();

        signals:
            void photoUploadFinished(const QStringList &result);

        private:
            QString accessToken;
            QString groupId;
            QString imagePath;
            QString filename;
            QNetworkAccessManager networkManager;
            QString uploadUrl;
            QString photo;
            QString server;
            QString hash;
            QString upload_result;
            QString sig;
            QStringList result;
            QEventLoop eventLoop;
        };
    }
}

#endif // PHOTOS_H
