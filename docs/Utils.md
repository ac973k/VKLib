# Utils

Служебные методы.

- [Utils.checkLink](#Utils.checkLink)
- [Utils.deleteFromLastShortened](#Utils.deleteFromLastShortened)
- [Utils.getLastShortenedLinks](#Utils.getLastShortenedLinks)
- [Utils.getLinkStats](#Utils.getLinkStats)
- [Utils.getServerTime](#Utils.getServerTime)
- [Utils.getShortLink](#Utils.getShortLink)
- [Utils.resolveScreenName](#Utils.resolveScreenName)


## <a id="Utils.checkLink">Utils.checkLink</a>

Метод для проверки ссылки.

`void checkLink(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры 

url - Обязательный параметр. Внешняя ссылка, которую необходимо проверить. Например, https://google.com.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/utils.checkLink)

## <a id="Utils.deleteFromLastShortened">Utils.deleteFromLastShortened</a>

Позволяет удалить сокращенную ссылку vk.cc.

`void deleteFromLastShortened(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры 

key - Обязательный параметр. Сокращённая ссылка (часть URL после «vk.cc/»).

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/utils.deleteFromLastShortened)

## <a id="Utils.getLastShortenedLinks">Utils.getLastShortenedLinks</a>

Позволяет получить список сокращенных ссылок пользователя.

`void getLastShortenedLinks(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры 

count(positive) - Количество ссылок, которые необходимо получить.

offset(positive) - Сдвиг для получения определенного подмножества ссылок.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/utils.getLastShortenedLinks)

## <a id="Utils.getLinkStats">Utils.getLinkStats</a>

Позволяет получить статистику сокращенной ссылки.

`void getLinkStats(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры 

key - Сокращённая ссылка (часть URL после «vk.cc/»). Обязательный параметр.

source

access_key - Ключ доступа к приватной статистике ссылки.

interval - Единица времени для подсчета статистики. Возможные значения:
hour — час;
day — день;
week — неделя;
month — месяц;
forever — все время с момента создания ссылки.

intervals_count(positive) - Длительность периода для получения статистики в выбранных единицах (из параметра interval).

extended - 1 — возвращать расширенную статистику (пол, возраст, страна, город). 0 — возвращать только количество переходов.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/utils.getLinkStats)

## <a id="Utils.getServerTime">Utils.getServerTime</a>

Позволяет получить серверное время в unixtime.

`void getServerTime(const QString &access_token);`

В QString передаётся Access Token пользователя.


## <a id="Utils.getShortLink">Utils.getShortLink</a>

Позволяет создать сокращенную ссылку vk.cc.

`void getShortLink(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры 

url - URL, для которого необходимо получить сокращённый вариант. Обязательный параметр.

private - 1 — статистика ссылки приватная. 0 — статистика ссылки общедоступная.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/utils.getShortLink)

## <a id="Utils.resolveScreenName">Utils.resolveScreenName</a>

Позволяет получить короткое имя пользователя/группы.

`void resolveScreenName(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры 

screen_name - Короткое имя пользователя, группы или приложения. Например, apiclub, andrew или rules_of_war. Обязательный параметр.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/utils.resolveScreenName)