#ifndef VKAUTH_H
#define VKAUTH_H

#include <QUrl>
#include <QWebEngineView>
#include <QStringList>

namespace VK {
    namespace Auth {
        class VKAuth : public QWebEngineView {
            Q_OBJECT

        public:
            explicit VKAuth(QWidget *parent = nullptr);
            ~VKAuth();

            /**
            * @brief Запускает процесс аутентификации.
            * @param appId ID приложения.
            * @param scopes Права доступа.
            * @return QStringList Список, содержащий access_token и user_id.
            */
            void startAuth(const QString &appId, const QString &scopes);

        signals:
            /**
            * @brief Сигнал, который отслеживает завершение авторизации.
            * @param QStringList Список, содержащий access_token и user_id.
            * @return QStringList Список, содержащий access_token и user_id.
            */
            void authCompleted(const QStringList &result);

        private slots:
            /**
            * @brief Слот, который отслеживает смену URL авторизации.
            * @param QUrl URL, содержащий измененную ссылку с токеном и id.
            * @return QStringList Список, содержащий access_token и user_id.
            */
            void onUrlChanged(const QUrl &url);

        private:
            QStringList result;
        };
    } // namespace Auth
} // namespace VK

#endif // VKAUTH_H
