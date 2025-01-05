# Account

Методы для работы с аккаунтом.

- [SIGNALS](#SIGNALS)
- [account.ban](#account.ban)
- [account.changePassword](#account.changePassword)
- [account.getActiveOffers](#account.getActiveOffers)
- [account.getAppPermissions](#account.getAppPermissions)
- [account.getBanned](#account.getBanned)
- [account.getCounters](#account.getCounters)
- [account.getInfo](#account.getInfo)
- [account.getProfileInfo](#account.getProfileInfo)
- [account.getPushSettings](#account.getPushSettings)
- [account.registerDevice](#account.registerDevice)
- [account.saveProfileInfo](#account.saveProfileInfo)
- [account.setInfo](#account.setInfo)
- [account.setOffline](#account.setOffline)
- [account.setOnline](#account.setOnline)
- [account.setPushSettings](#account.setPushSettings)
- [account.setSilenceMode](#account.setSilenceMode)
- [account.unban](#account.unban)
- [account.unregisterDevice](#account.unregisterDevice)
- [Пример](#Пример)


## <a id="SIGNALS">SIGNALS</a>
`void Completed(const QString &result);`

## <a id="account.ban">account.ban</a>

`void ban(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

owner_id - Идентификатор пользователя или сообщества, которое будет добавлено в черный список.

Все параметры можно найти тут [scopes](https://dev.vk.com/ru/method/account.ban)

## <a id="account.changePassword">account.changePassword</a>

Позволяет сменить пароль пользователя после успешного восстановления доступа к аккаунту через СМС, используя метод auth.restore.

`void changePassword(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

restore_sid - Идентификатор сессии, полученный при восстановлении доступа используя метод auth.restore. (В случае если пароль меняется сразу после восстановления доступа).

change_password_hash - Хэш, полученный при успешной OAuth авторизации по коду полученному по СМС (В случае если пароль меняется сразу после восстановления доступа).

old_password - Текущий пароль пользователя.

new_password - Новый пароль, который будет установлен в качестве текущего.
Обязательный параметр. Мин. длина = 6

Все параметры можно найти тут [scopes](https://dev.vk.com/ru/method/account.changePassword)

## <a id="account.getActiveOffers">account.getActiveOffers</a>

Возвращает список активных рекламных предложений (офферов), выполнив которые, пользователь сможет получить соответствующее количество голосов на свой счёт внутри приложения.

`void getActiveOffers(const QString &access_token);`

`void getActiveOffers(const QString &access_token, const QString &scopes);`

### Параметры

offset(positive) - Смещение, необходимое для выборки определенного подмножества офферов.

count(positive) - Количество офферов, которое необходимо получить.

Все параметры можно найти тут [scopes](https://dev.vk.com/ru/method/account.getActiveOffers)

## <a id="account.getAppPermissions">account.getAppPermissions</a>

Метод получает настройки пользователя вашего приложения.

`void getAppPermissions(const QString &access_token, const QString &scopes);`

### Параметры

user_id(positive) - Обязательный параметр. Идентификатор пользователя, настройки которого необходимо получить. Значение по умолчанию: идентификатор текущего пользователя.

Все параметры можно найти тут [scopes](https://dev.vk.com/ru/method/account.getAppPermissions)

## <a id="account.getBanned">account.getBanned</a>

Возвращает список пользователей, находящихся в черном списке.

`void getBanned(const QString &access_token, const QString &scopes);`

`void getBanned(const QString &access_token);`

### Параметры

offset(positive) - Смещение, необходимое для выборки определенного подмножества черного списка.

count(positive) - Количество объектов, информацию о которых необходимо вернуть.

fields

Все параметры можно найти тут [scopes](https://dev.vk.com/ru/method/account.getBanned)

## <a id="account.getCounters">account.getCounters</a>

Метод возвращает ненулевые значения счётчиков пользователя.

`void getCounters(const QString &access_token);`

`void getCounters(const QString &access_token, const QString &scopes);`

### Параметры

filter - Необязательный параметр. Cчётчики, информацию о которых нужно вернуть, перечисленные через запятую. Возможные значения:

•friends — новые заявки в друзья.

•friends_suggestions — предлагаемые друзья.

•messages — новые сообщения.

•photos — новые отметки на фотографиях.

•videos — новые отметки на видеозаписях.

•gifts — подарки.

•events — события.

•groups — сообщества.

•notifications — ответы.

•sdk — запросы в мобильных играх.

•app_requests — уведомления от приложений.

•friends_recommendations — рекомендации друзей.

Все параметры можно найти тут [scopes](https://dev.vk.com/ru/method/account.getCounters)

## <a id="account.getInfo">account.getInfo</a>

Возвращает информацию о текущем аккаунте.

`void getInfo(const QString &access_token);`

`void getInfo(const QString &access_token, const QString &scopes);`

### Параметры

fields - Cписок полей, которые необходимо вернуть. Возможные значения:

•country;

•https_required;

•own_posts_default;

•no_wall_replies;

•intro;

•lang.

По умолчанию будут возвращены все поля.

Все параметры можно найти тут [scopes](https://dev.vk.com/ru/method/account.getInfo)

## <a id="account.getProfileInfo">account.getProfileInfo</a>

Возвращает информацию о текущем профиле.

`void getProfileInfo(const QString &access_token);`

## <a id="account.getPushSettings">account.getPushSettings</a>

Позволяет получать настройки Push-уведомлений.

`void getPushSettings(const QString &access_token, const QString &scopes);`

### Параметры

token - Идентификатор устройства, используемый для отправки уведомлений. (для mpns идентификатор должен представлять из себя URL для отправки уведомлений)

device_id - Уникальный идентификатор устройства.

Все параметры можно найти тут [scopes](https://dev.vk.com/ru/method/account.getPushSettings)

## <a id="account.registerDevice">account.registerDevice</a>

Подписывает устройство на базе iOS, Android, Windows Phone или Mac на получение push-уведомлений.

`void registerDevice(const QString &access_token, const QString &scopes);`

### Параметры

token - Идентификатор устройства, используемый для отправки уведомлений. (для mpns идентификатор должен представлять из себя URL для отправки уведомлений). Обязательный параметр

device_model - Строковое название модели устройства.

device_year - Год устройства.

device_id - Уникальный идентификатор устройства. Обязательный параметр

system_version - Строковая версия операционной системы устройства.

no_text - 1 — не передавать текст сообщения в push-уведомлении. 0 — (по умолчанию) текст сообщения передаётся.

subscribe - Список типов уведомлений, которые следует присылать. Могут быть переданы следующие типы:
msg,friend,call,reply,mention,group,like.
По умолчанию присылаются: msg, friend.

settings - Сериализованный JSON-объект, описывающий настройки уведомлений в [специальном формате](https://dev.vk.com/ru/reference/objects/push-settings).

sandbox - Флаг предназначен для iOS устройств. 1 — использовать sandbox сервер для отправки push-уведомлений, 0 — не использовать.

Все параметры можно найти тут [scopes](https://dev.vk.com/ru/method/account.registerDevice)

## <a id="account.saveProfileInfo">account.saveProfileInfo</a>

Редактирует информацию текущего профиля.

`void saveProfileInfo(const QString &access_token, const QString &scopes);`

### Параметры

first_name - Имя пользователя. Обязательно с большой буквы.

last_name - Фамилия пользователя. Обязательно с большой буквы.

maiden_name - Девичья фамилия пользователя (только для женского пола).

screen_name - Короткое имя страницы.

cancel_request_id(positive) - Идентификатор заявки на смену имени, которую необходимо отменить. Если передан этот параметр, все остальные параметры игнорируются.

sex(positive) - пол пользователя. Возможные значения:
1 — женский;
2 — мужской.

relation(positive) - Семейное положение пользователя. Возможные значения:
1 — не женат/не замужем;
2 — есть друг/есть подруга;
3 — помолвлен/помолвлена;
4 — женат/замужем;
5 — всё сложно;
6 — в активном поиске;
7 — влюблён/влюблена;
8 — в гражданском браке;
0 — не указано.

relation_partner_id - Идентификатор пользователя, с которым связано семейное положение.

bdate - Дата рождения пользователя в формате DD.MM.YYYY, например 15.11.1984.

bdate_visibility - (positive)
Видимость даты рождения. Возможные значения:
1 — показывать дату рождения;
2 — показывать только месяц и день;
0 — не показывать дату рождения.

home_town - Родной город пользователя.

country_id(positive) - Идентификатор страны пользователя.

city_id(positive) - Идентификатор города пользователя.

status - Статус пользователя, который также может быть изменен методом status.set.

Все параметры можно найти тут [scopes](https://dev.vk.com/ru/method/account.saveProfileInfo)

## <a id="account.setInfo">account.setInfo</a>

Позволяет редактировать информацию о текущем аккаунте.

`void setInfo(const QString &access_token, const QString &scopes);`

### Параметры

intro(positive) - Битовая маска, отвечающая за прохождение обучения в мобильных клиентах.

own_posts_default - 1 – на стене пользователя по умолчанию должны отображаться только собственные записи; 0 – на стене пользователя должны отображаться все записи.

no_wall_replies - 1 – отключить комментирование записей на стене; 0 – разрешить комментирование.

name - Имя настройки

value - Значение настройки

Все параметры можно найти тут [scopes](https://dev.vk.com/ru/method/account.setInfo)

## <a id="account.setOffline">account.setOffline</a>

Помечает текущего пользователя как offline (только в текущем приложении).

`void setOffline(const QString &access_token);`

## <a id="account.setOnline">account.setOnline</a>

Помечает текущего пользователя как online на 5 минут.

`void setOnline(const QString &access_token);`

## <a id="account.setPushSettings">account.setPushSettings</a>

Изменяет настройку push-уведомлений.

`void setPushSettings(const QString &access_token, const QString &scopes);`

### Параметры

device_id - Уникальный идентификатор устройства. Обязательный параметр

settings - Сериализованный JSON-объект, описывающий настройки уведомлений в специальном формате.

key - Ключ уведомления.

value - Новое значение уведомления в [специальном формате](https://dev.vk.com/ru/reference/objects/push-settings).

Должен быть обязательно передан один из параметров: token или device_id.

Все параметры можно найти тут [scopes](https://dev.vk.com/ru/method/account.setPushSettings)

## <a id="account.setSilenceMode">account.setSilenceMode</a>

Отключает push-уведомления на заданный промежуток времени.

`void setSilenceMode(const QString &access_token, const QString &scopes);`

### Параметры

token - Идентификатор устройства для сервиса push уведомлений.

device_id - Уникальный идентификатор устройства.

time - Время в секундах на которое требуется отключить уведомления, -1 отключить навсегда.

chat_id - Идентификатор чата, для которого следует отключить уведомления.

user_id - Идентификатор пользователя, для которого следует отключить уведомления.

peer_id - Идентификатор назначения.

Для пользователя:
id пользователя.
Для групповой беседы:
2000000000 + id беседы.
Для сообщества:
-id сообщества.

sound - 1 — включить звук в этом диалоге, 0 — отключить звук (параметр работает, только если в peer_id передан идентификатор групповой беседы или пользователя).

Все параметры можно найти тут [scopes](https://dev.vk.com/ru/method/account.setSilenceMode)

## <a id="account.unban">account.unban</a>

Удаляет пользователя или группу из черного списка.

`void unban(const QString &access_token, const QString &scopes);`

### Параметры

owner_id - Идентификатор пользователя или группы, которого нужно удалить из черного списка.

Все параметры можно найти тут [scopes](https://dev.vk.com/ru/method/account.unban)

## <a id="account.unregisterDevice">account.unregisterDevice</a>

Отписывает устройство от Push уведомлений.

`void unregisterDevice(const QString &access_token, const QString &scopes);`

### Параметры

token - Идентификатор устройства, используемый для отправки уведомлений.

device_id - Уникальный идентификатор устройства.

sandbox - Флаг предназначен для iOS устройств. Возможные значения:
1 — отписать устройство, использующего sandbox сервер для отправки push-уведомлений;
0 — отписать устройство, не использующее sandbox сервер.

Все параметры можно найти тут [scopes](https://dev.vk.com/ru/method/account.unregisterDevice)

## <a id="Пример">Пример</a>

acc.h:
	
```lang-cpp
#include <QObject>
#include "../VKLib/src/Account/Account.h"
	
class Account : public QObject {
	Q_OBJECT
	public:
	explicit Account(QObject *parent = nullptr);

	private:
		QString VKToken = "asdhfbsdfvalefuhszkdfhvr" // наш токен, который мы получили при авторизации
		VK::Account::Account account;
		QString scopes = "owner_id=1" // параметр и значение. Тут мы вибраем, какого пользователя забаним. В данном случае Пользователь с id 1

	private slots:
		void ban(QString data); // Сюда придет ответ от VK в формате json

};
```
	
acc.cpp:
	
```lang-cpp
#include "acc.h"

Account::Account(QObject *parent)
	: QObject{parent} {

	account.ban(VKToken, scopes);
	QObject::connect(account, SIGNAL(Completed(const QString)), this, SLOT(ban(QString)));
}

void Account::ban(QString data) {
	qDebug() << data;
}
```
