#ifndef USERS_H
#define USERS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

namespace VK {
    namespace Users {
        class Users : public QObject
        {
            Q_OBJECT
        public:
            explicit Users(QObject *parent = nullptr);
            ~Users();

            void get(const QString &access_token, const QString &user_ids, const QString &fields, const QString &name_case, const QString &from_group_id);
            void getFollowers(const QString &access_token, const QString &user_id, const QString &count, const QString &fields, const QString &name_case);
            void getSubscriptions(const QString &access_token, const QString &user_id, const QString &count, const QString &fields);
            void report(const QString &access_token, const QString &user_id, const QString &type, const QString &comment);
            void search(const QString &access_token, const QString &q, const QString &sort, const QString &count, const QString &fields, const QString &city, const QString &country, const QString &sex,
                        const QString &age_from, const QString &age_to, const QString &birth_day, const QString &birth_month, const QString &birth_year, const QString &group_id, const QString &from_list);

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

#endif // USERS_H
