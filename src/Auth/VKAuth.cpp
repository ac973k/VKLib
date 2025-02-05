#include "VKAuth.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QUrlQuery>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace VK {
    namespace Auth {
        VKAuth::VKAuth(QWidget *parent)
            : QWebEngineView(parent)
        {
            connect(this, &QWebEngineView::urlChanged, this, &VKAuth::onUrlChanged);
        }

        VKAuth::~VKAuth()
        {

        }

        void VKAuth::startAuth(const QString &appId, const QString &scopes)
        {
            QString authUrl = QString("https://oauth.vk.com/authorize?client_id=%1&display=page&redirect_uri=https://oauth.vk.com/blank.html&scope=%2&response_type=token&v=5.199")
                                  .arg(appId).arg(scopes);
            setUrl(QUrl(authUrl));
            show();
        }

        void VKAuth::onUrlChanged(const QUrl &url)
        {
            if (url.toString().startsWith("https://oauth.vk.com/blank.html")) {
                QUrlQuery query(url.fragment());
                QString accessToken = query.queryItemValue("access_token");
                QString userId = query.queryItemValue("user_id");

                if (!accessToken.isEmpty() && !userId.isEmpty()) {
                    result << accessToken << userId;
                    emit authCompleted(result);
                    close();
                } else {
                    qDebug() << "Access token or User ID is missing";
                }
            }
        }

    }
}
