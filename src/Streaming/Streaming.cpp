#include "Streaming.h"

namespace VK {
    namespace Streaming {
        Streaming::Streaming(QObject *parent)
            : QObject{parent} {

        }
        Streaming::~Streaming() {

        }

        void Streaming::getServerUrl(const QString &access_token) {
            QUrl link(QString("https://api.vk.com/method/streaming.getServerUrl"));
            qDebug() << "full url: " << link;

            QUrlQuery query;
            query.addQueryItem("access_token", access_token);
            query.addQueryItem("v", "5.131");
            link.setQuery(query);

            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Streaming::Finished);
        }

        void Streaming::getStats(const QString &access_token, const QString &type, const QString &interval, const QString &start_time, const QString &end_time) {
            QUrl link(QString("https://api.vk.com/method/streaming.getStats"));
            qDebug() << "full url: " << link;

            QUrlQuery query;
            query.addQueryItem("access_token", access_token);
            query.addQueryItem("type", type);
            query.addQueryItem("interval", interval);
            query.addQueryItem("start_time", start_time);
            query.addQueryItem("end_time", end_time);
            query.addQueryItem("v", "5.131");
            link.setQuery(query);

            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Streaming::Finished);
        }

        void Streaming::getStem(const QString &access_token, const QString &word) {
            QUrl link(QString("https://api.vk.com/method/streaming.getStem"));
            qDebug() << "full url: " << link;

            QUrlQuery query;
            query.addQueryItem("access_token", access_token);
            query.addQueryItem("word", word);
            query.addQueryItem("v", "5.131");
            link.setQuery(query);

            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Streaming::Finished);
        }

        void Streaming::Finished() {
            QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
            if (!reply) {
                return;
            }

            if (reply->error() != QNetworkReply::NoError) {
                result = reply->errorString();
                qDebug() << "Error:" << result;
                emit completed(result);
                reply->deleteLater();
                return;
            }

            if (reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() != 200) {
                result = QString("HTTP Error: %1").arg(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt());
                qDebug() << result;
                emit completed(result);
                reply->deleteLater();
                return;
            }

            result = reply->readAll();
            emit completed(result);
            reply->deleteLater();
        }
    }
}
