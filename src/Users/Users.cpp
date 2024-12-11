#include "Users.h"

namespace VK {
    namespace Users {
        Users::Users(QObject *parent)
            : QObject{parent}
        {


        }

        Users::~Users() {

        }

        void Users::get(const QString &access_token, const QString &user_ids, const QString &fields, const QString &name_case, const QString &from_group_id) {
            QUrl link(QString("https://api.vk.com/method/users.get?access_token=%1&user_ids=%2&fields=%3&name_case=%4&from_group_id=%5&v=5.199").arg(access_token).arg(user_ids).arg(fields).arg(name_case)
                          .arg(from_group_id));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Users::Finished);
        }

        void Users::getFollowers(const QString &access_token, const QString &user_id, const QString &count, const QString &fields, const QString &name_case) {
            QUrl link(QString("https://api.vk.com/method/users.getFollowers?access_token=%1&user_id=%2&count=%3&fields=%4&name_case=%5&v=5.199").arg(access_token).arg(user_id).arg(count).arg(fields)
                          .arg(name_case));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Users::Finished);
        }

        void Users::getSubscriptions(const QString &access_token, const QString &user_id, const QString &count, const QString &fields) {
            QUrl link(QString("https://api.vk.com/method/users.getSubscriptions?access_token=%1&user_id=%2&count=%3&fields=%4&v=5.199").arg(access_token).arg(user_id).arg(count).arg(fields));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Users::Finished);
        }

        void Users::report(const QString &access_token, const QString &user_id, const QString &type, const QString &comment) {
            QUrl link(QString("https://api.vk.com/method/users.report?access_token=%1&user_id=%2&type=%3&comment=%4&v=5.199").arg(access_token).arg(user_id).arg(type).arg(comment));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Users::Finished);
        }

        void Users::search(const QString &access_token, const QString &q, const QString &sort, const QString &count, const QString &fields, const QString &city, const QString &country, const QString &sex,
                           const QString &age_from, const QString &age_to, const QString &birth_day, const QString &birth_month, const QString &birth_year, const QString &group_id, const QString &from_list) {
            QUrl link(QString("https://api.vk.com/method/users.search?access_token=%1&q=%2&sort=%3&count=%4&fields=%5&city=%6&country=%7&sex=%8&age_from=%9&age_to=%10&birth_day=%11&birth_month=%12&birth_year=%13"
                              "&group_id=%14&from_list=%15&v=5.199").arg(access_token).arg(q).arg(sort).arg(count).arg(fields).arg(city).arg(country).arg(sex).arg(age_from).arg(age_to).arg(birth_day)
                          .arg(birth_month).arg(birth_year).arg(group_id).arg(from_list));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Users::Finished);
        }

        void Users::Finished() {
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
