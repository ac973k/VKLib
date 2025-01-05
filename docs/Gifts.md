# Gifts

Методы для работы с подарками.

- [Gifts.get](#Gifts.get)


## <a id="Gifts.get">Gifts.get</a>

Возвращает список полученных подарков пользователя.

`void get(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

user_id(positive) - Идентификатор пользователя, для которого необходимо получить список подарков.

count(positive) - Количество подарков, которое нужно вернуть.

offset(positive) - Смещение, необходимое для выборки определенного подмножества подарков.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/gifts.get)
