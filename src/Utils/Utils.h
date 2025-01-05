#ifndef UTILS_H
#define UTILS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

namespace VK {
    namespace Utils {
        class Utils : public QObject
            {
                Q_OBJECT
                public:
                    explicit Utils(QObject *parent = nullptr);
                    ~Utils();

                void checkLink(const QString &access_token, const QString &scopes);
                void deleteFromLastShortened(const QString &access_token, const QString &scopes);
                void getLastShortenedLinks(const QString &access_token, const QString &scopes);
                void getLinkStats(const QString &access_token, const QString &scopes);
                void getServerTime(const QString &access_token);
                void getShortLink(const QString &access_token, const QString &scopes);
                void resolveScreenName(const QString &access_token, const QString &scopes);

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
