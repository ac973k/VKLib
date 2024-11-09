#ifndef GROUPS_H
#define GROUPS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QEventLoop>
#include <QUrlQuery>

namespace VK {
    namespace Groups {
        class Groups : public QObject
        {
            Q_OBJECT
        public:
            explicit Groups(QObject *parent = nullptr);
            ~Groups();

            QString getById(const QString &access_token, const QString &group_ids, const QString &fields);

        private:
            QNetworkAccessManager networkManager;
            QString result;
            QEventLoop eventLoop;

        private slots:
            void getGroupInfoFinished();
        };
    }
}

#endif // GROUPS_H
