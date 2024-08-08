#ifndef TRANSLATIONS_H
#define TRANSLATIONS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

namespace VK {
    namespace Translations {
        class Translations : public QObject {
            Q_OBJECT

        public:
        explicit Translations(QObject *parent = nullptr);
        ~Translations();

        void translate(const QString &access_token, const QString &texts, const QString &translation_language);

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



#endif // TRANSLATIONS_H
