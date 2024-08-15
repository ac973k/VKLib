#ifndef UTILS_H
#define UTILS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

namespace VK {
    namespace Utils {
        class Utils : public QObject
            {
                Q_OBJECT
                public:
                    explicit Utils(QObject *parent = nullptr);
                    ~Utils();

                void checkLink(const QString &access_token, const QString &url);
                void deleteFromLastShortened(const QString &access_token, const QString &key);
                void getLastShortenedLinks(const QString &access_token, const QString &count);
                void getLinkStats(const QString &access_token, const QString &key, const QString &interval, const QString &intervals_count, const QString &extended);
                void getServerTime(const QString &access_token);
                void getShortLink(const QString &access_token, const QString &url, const QString &priv);
                void resolveScreenName(const QString &access_token, const QString &screen_name);

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

#endif // UTILS_H
