#ifndef STATS_H
#define STATS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

namespace VK {
namespace Stats {
class Stats : public QObject {
    Q_OBJECT

public:
    explicit Stats(QObject *parent = nullptr);
    ~Stats();

    void get(const QString &access_token, const QString &scopes);
    void getPostReach(const QString &access_token, const QString &scopes);
    void trackVisitor(const QString &access_token);

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

#endif // STATS_H
