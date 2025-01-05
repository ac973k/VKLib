# Donut

Методы для работы с VK Donut.

- [Donut.getFriends](#Donut.getFriends)
- [Donut.getSubscription](#Donut.getSubscription)
- [Donut.getSubscriptions](#Donut.getSubscriptions)
- [Donut.isDon](#Donut.isDon)


## <a id="Donut.getFriends">Donut.getFriends</a>

Возвращает список донов, которые подписаны на определенные сообщества, из числа друзей пользователя.

`void getFriends(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

owner_id - Идентификатор сообщества. Обратите внимание, идентификатор сообщества в параметре owner_id необходимо указывать со знаком «-» — например, owner_id=-1 соответствует идентификатору сообщества ВКонтакте API (club1). Обязательный параметр

offset(positive) - Смещение, необходимое для выборки определенного подмножества друзей.

count(positive) - Количество друзей, информацию о которых необходимо вернуть.

fields - Список дополнительных полей профилей, которые необходимо вернуть. См. [подробное описание.]( https://dev.vk.com/ru/reference/objects/user)

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/donut.getFriends)


## <a id="Donut.getSubscription">Donut.getSubscription</a>

Возвращает информацию о подписке VK Donut.

`void getSubscription(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

owner_id - Идентификатор сообщества. Обратите внимание, идентификатор сообщества в параметре owner_id необходимо указывать со знаком «-» — например, owner_id=-1 соответствует идентификатору сообщества ВКонтакте API (club1).

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/donut.getSubscription)


## <a id="Donut.getSubscriptions">Donut.getSubscriptions</a>

Возвращает информацию о подписках пользователя.

`void getSubscriptions(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

fields - Список дополнительных полей профиля, которые необходимо вернуть. См. подробное описание.

offset(positive) - Смещение, необходимое для выборки определенного подмножества подписок.

count(positive) - Количество подписок, информацию о которых необходимо вернуть.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/donut.getSubscriptions)


## <a id="Donut.isDon">Donut.isDon</a>

Возвращает информацию о том, подписан ли пользователь на платный контент (является доном).

`void isDon(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

owner_id - Идентификатор сообщества. Обратите внимание, идентификатор сообщества в параметре owner_id необходимо указывать со знаком «-» — например, owner_id=-1 соответствует идентификатору сообщества ВКонтакте API (club1). Обязательный параметр.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/donut.isDon)