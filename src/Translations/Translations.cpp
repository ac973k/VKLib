#include "Translations.h"

namespace VK {
    namespace Translations {
        Translations::Translations(QObject *parent)
            : QObject{parent} {

        }

        Translations::~Translations() {

        }

        void Translations::translate(const QString &access_token, const QString &texts, const QString &translation_language)
        {
            QUrl link(QString("https://api.vk.com/method/translations.translate?access_token=%1&texts=%2&translation_language=%3&v=5.131").arg(access_token).arg(texts).arg(translation_language));
            qDebug() << "full url: " << link;
            QNetworkRequest request(link);
            QNetworkReply* reply = networkManager.get(request);
            connect(reply, &QNetworkReply::finished, this, &Translations::Finished);
        }

        void Translations::Finished() {
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
