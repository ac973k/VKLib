# Calls

Методы для работы со звонками.

- [Calls.forceFinish](#Calls.forceFinish)
- [Calls.start](#Calls.start)


## <a id="Calls.forceFinish">Calls.forceFinish</a>

Принудительно завершает звонок

`void forceFinish(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры
call_id - Идентификатор звонка. Обязательный параметр. Макс. длина = 36; Мин. длина = 36

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/calls.forceFinish)


## <a id="Calls.start">Calls.start</a>

Создаёт новый звонок от имени пользователя или сообщества

`void start(const QString &access_token, const QString &scopes);`

`void start(const QString &access_token);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры
group_id - Идентификатор сообщества (отрицательное число)

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/calls.start)
