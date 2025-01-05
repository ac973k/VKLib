#ifndef LIKES_H
#define LIKES_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

namespace VK {
    namespace Likes {
        class Likes : public QObject
        {
            Q_OBJECT

            public:
                explicit Likes(QObject *parent = nullptr);
                ~Likes();

                void add(const QString &access_token, const QString &scopes);
                void del(const QString &access_token, const QString &scopes);
                void getList(const QString &access_token, const QString &scopes);
                void isLiked(const QString &access_token, const QString &scopes);

            private:
                QNetworkAccessManager networkManager;
                QString result;

            signals:
                void Completed(const QString &result);

            private slots:
                void Finished();
        };
    }
}

#endif // LIKES_H
