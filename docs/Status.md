# Status

Методы для работы со статусом.

- [Status.get](#Status.get)
- [Status.set](#Status.set)


## <a id="Status.get">Status.get</a>

Получает текст статуса пользователя или сообщества.

`void get(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

user_id - Идентификатор пользователя, статус которого необходимо получить.

group_id - Идентификатор сообщества, статус которого необходимо получить.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/status.get)

## <a id="Status.set">Status.set</a>

Устанавливает новый статус текущему пользователю или сообществу.

`void set(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

text - Текст нового статуса.

group_id(positive) - Идентификатор сообщества, в котором будет установлен статус. По умолчанию статус устанавливается текущему пользователю

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/status.set)