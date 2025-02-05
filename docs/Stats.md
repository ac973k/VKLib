# Stats

Методы для работы со статистикой.

- [Stats.get](#Stats.get)
- [Stats.getPostReach](#Stats.getPostReach)
- [Stats.trackVisitor](#Stats.trackVisitor)


## <a id="Stats.get">Stats.get</a>

Возвращает статистику сообщества или приложения.

`void get(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

group_id — Идентификатор сообщества.

app_id — Идентификатор приложения.

timestamp_from — Начало периода статистики в Unixtime.

timestamp_to — Окончание периода статистики в Unixtime.

interval — Временные интервалы. Возможные значения: day, week, month, year, all. По умолчанию: day.

intervals_count — Количество интервалов времени.

filters

stats_groups — Фильтр для получения данных по конкретному блоку статистики сообщества. Возможные значения: visitors, reach, activity.

extended — 1 — возвращать дополнительно агрегированные данные в результатах.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/stats.get)

## <a id="Stats.getPostReach">Stats.getPostReach</a>

Устанавливает новый статус текущему пользователю или сообществу.

`void getPostReach(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

owner_id — Идентификатор владельца записи (сообщества). Должен начинаться со знака -. Обязательный параметр

post_ids — Обязательный параметр

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/stats.getPostReach)

## <a id="Stats.trackVisitor">Stats.trackVisitor</a>

Устанавливает новый статус текущему пользователю или сообществу.

`void trackVisitor(const QString &access_token);`

В QString передаётся Access Token пользователя.

### Параметры

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/stats.getPostReach)