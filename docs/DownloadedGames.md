# DownloadedGames

- [DownloadedGames.getPaidStatus](#Donut.getPaidStatus)


## <a id="DownloadedGames.getPaidStatus">DownloadedGames.getPaidStatus</a>

Метод получает информацию, купил ли пользователь игру или нет.

`void getPaidStatus(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

user_id(positive) - Идентификатор пользователя, возможно купившего приложение.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/downloadedGames.getPaidStatus)
