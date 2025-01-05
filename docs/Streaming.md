# Streaming

- [Streaming.getServerUrl](#Streaming.getServerUrl)
- [Streaming.getStats](#Streaming.getStats)
- [Streaming.getStem](#Streaming.getStem)


## <a id="Streaming.getServerUrl">Streaming.getServerUrl</a>

Позволяет получить данные для подключения к Streaming API.

`void getServerUrl(const QString &access_token);`

В QString передаётся Access Token пользователя.

## <a id="Streaming.getStats">Streaming.getStats</a>

Позволяет получить статистику для подготовленных и доставленных событий Streaming API.

`void getStats(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

type - Тип статистики. Возможные значения:

received — события, полученные приложением;

prepared — события, сгенерированные со стороны ВКонтакте.

interval - Интервалы статистики. Возможные значения:

5m — пять минут. Максимальный период — 3 дня между start_time и end_time;

1h — один час. Максимальный период — 7 дней между start_time и end_time;

24h — сутки. Максимальный период — 31 день между start_time и end_time.



start_time(positive) - Время начала отсчёта в unixtime. По умолчанию: end_time минус сутки.

end_time(positive) - Время окончания отсчёта в unixtime. По умолчанию: текущее время.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/streaming.getStats)

## <a id="Streaming.getStem">Streaming.getStem</a>

Позволяет получить основу слова.

`void getStem(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

type - Тип статистики. Возможные значения:

received — события, полученные приложением;

prepared — события, сгенерированные со стороны ВКонтакте.

interval - Интервалы статистики. Возможные значения:

5m — пять минут. Максимальный период — 3 дня между start_time и end_time;

1h — один час. Максимальный период — 7 дней между start_time и end_time;

24h — сутки. Максимальный период — 31 день между start_time и end_time.



start_time(positive) - Время начала отсчёта в unixtime. По умолчанию: end_time минус сутки.

end_time(positive) - Время окончания отсчёта в unixtime. По умолчанию: текущее время.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/streaming.getStem)