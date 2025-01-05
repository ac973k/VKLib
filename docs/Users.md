# Users

Методы для работы с данными пользователей.

- [Users.get](#Users.get)
- [Users.getFollowers](#Users.getFollowers)
- [Users.getSubscriptions](#Users.getSubscriptions)
- [Users.report](#Users.report)
- [Users.search](#Users.search)


## <a id="Users.get">Users.get</a>

Позволяет получить список пользователей.

`void get(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

user_ids - Перечисленные через запятую идентификаторы пользователей или их короткие имена (screen_name). По умолчанию — идентификатор текущего пользователя.

fields - Список дополнительных полей профилей, которые необходимо вернуть. См. [подробное описание.](https://dev.vk.com/ru/reference/objects/user)

Доступные значения:
activities,
about,
blacklisted,
blacklisted_by_me,
books,
bdate,
can_be_invited_group,
can_post,
can_see_all_posts,
can_see_audio,
can_send_friend_request,
can_write_private_message,
career,
common_count,
connections,
contacts,
city,
crop_photo,
domain,
education,
exports,
followers_count,
friend_status,
has_photo,
has_mobile,
home_town,
photo_100,
photo_200,
photo_200_orig,
photo_400_orig,
photo_50,
sex,
site,
schools,
screen_name,
status,
verified,
games,
interests,
is_favorite,
is_friend,
is_hidden_from_feed,
last_seen,
maiden_name,
military,
movies,
music,
nickname,
occupation,
online,
personal,
photo_id,
photo_max,
photo_max_orig,
quotes,
relation,
relatives,
timezone,
tv,
universities,
is_verified.

name_case - Падеж для склонения имени и фамилии пользователя. Возможные значения:

именительный – nom,
родительный – gen,
дательный – dat,
винительный – acc,
творительный – ins,
предложный – abl.
По умолчанию nom.

from_group_id - Поля counters, military будут возвращены только в случае, если передан ровно один user_id.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/users.get)

## <a id="Users.getFollowers">Users.getFollowers</a>

Позволяет плучить список подписчиков пользователя.

`void getFollowers(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

user_id(positive) - Идентификатор пользователя.

offset(positive) - Смещение, необходимое для выборки определенного подмножества подписчиков.

count(positive) - Количество подписчиков, информацию о которых нужно получить.

fields - Список дополнительных полей профилей, которые необходимо вернуть. См. [подробное описание.](https://dev.vk.com/ru/reference/objects/user) 

Доступные значения:
about,
activities,
bdate,
blacklisted,
blacklisted_by_me
books,
can_post,
can_see_all_posts,
can_see_audio,
can_send_friend_request,
can_write_private_message,
career,
city,
common_count,
connections,
contacts,
country,
crop_photo,
domain,
education,
exports,
followers_count,
friend_status,
games,
has_mobile,
has_photo,
home_town,
interests,
is_favorite,
is_friend,
is_hidden_from_feed,
last_seen,
lists,
maiden_name,
military,
movies,
music,
nickname,
occupation,
online,
personal,
photo_100,
photo_200,
photo_200_orig,
photo_400_orig,
photo_50,
photo_id,
photo_max,
photo_max_orig,
quotes,
relation,
relatives,
schools,
screen_name,
sex,
site,
status,
timezone,
tv,
universities,
verified,
wall_comments.

name_case - Падеж для склонения имени и фамилии пользователя. 
Возможные значения:
именительный – nom,
родительный – gen,
дательный – dat,
винительный – acc,
творительный – ins,
предложный – abl.
По умолчанию nom.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/users.getFollowers)

## <a id="Users.getSubscriptions">Users.getSubscriptions</a>

Позволяет плучить список подписок пользователя.

`void getSubscriptions(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

user_id(positive) - Идентификатор пользователя, подписки которого необходимо получить.

extended - 1 – возвращает объединенный список, содержащий объекты group и user вместе. 0 – возвращает список идентификаторов групп и пользователей отдельно (по умолчанию).

offset(positive) - Смещение необходимое для выборки определенного подмножества подписок. Этот параметр используется только если передан extended=1.

count(positive) - Количество подписок, которые необходимо вернуть. Этот параметр используется только если передан extended=1.

fields - Список дополнительных полей для объектов user и group, которые необходимо вернуть.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/users.getSubscriptions)

## <a id="Users.report">Users.report</a>

Позволяет отправить жалобу на пользователя.

`void report(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

user_id(positive) - Идентификатор пользователя, на которого нужно подать жалобу. Обязательный параметр.

type - Обязательный параметр. Тип жалобы, может принимать следующие значения:
porn — порнография;
spam — рассылка спама;
insult — оскорбительное поведение;
advertisement — рекламная страница, засоряющая поиск.

comment - Комментарий к жалобе на пользователя.

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/users.report)

## <a id="Users.search">Users.search</a>

Позволяет найти пользователя.

`void search(const QString &access_token, const QString &scopes);`

В QString передаётся Access Token пользователя, в scopes необходимые параметры.

### Параметры

q - Строка поискового запроса. Например, Вася Бабич.

sort - Сортировка результатов. Возможные значения:
1 — по дате регистрации,
0 — по популярности.

offset(positive) - Смещение относительно первого найденного пользователя для выборки определенного подмножества.

count(positive) - Количество возвращаемых пользователей.

Обратите внимание, даже при использовании параметра offset для получения информации доступны только первые 1000 результатов.

fields - Список дополнительных полей профилей, которые необходимо вернуть. См. [подробное описание.](https://dev.vk.com/ru/reference/objects/user) 
Доступные значения:
about,
activities,
bdate,
blacklisted,
blacklisted_by_me
books,
can_post,
can_see_all_posts,
can_see_audio,
can_send_friend_request,
can_write_private_message,
career,
city,
common_count,
connections,
contacts,
country,
crop_photo,
domain,
education,
exports,
followers_count,
friend_status,
games,
has_mobile,
has_photo,
home_town,
interests,
is_favorite,
is_friend,
is_hidden_from_feed,
last_seen,
lists,
maiden_name,
military,
movies,
music,
nickname,
occupation,
online,
personal,
photo_100,
photo_200,
photo_200_orig,
photo_400_orig,
photo_50,
photo_id,
photo_max,
photo_max_orig,
quotes,
relation,
relatives,
schools,
screen_name,
sex,
site,
status,
timezone,
tv,
universities,
verified,
wall_comments.

city(positive) - Идентификатор города.

city_id(positive) - Идентификатор города для обратной совместимости. Используйте city

country(positive) - Идентификатор страны.

country_id(positive) - Идентификатор страны для обратной совместимости. Используйте country

hometown - Название города строкой.

university_country(positive) - Идентификатор страны, в которой пользователи закончили ВУЗ.

university(positive) - Идентификатор ВУЗа.

university_year(positive) - Год окончания ВУЗа.

university_faculty(positive) - Идентификатор факультета.

university_chair(positive) - Идентификатор кафедры.

sex(positive) - Пол. Возможные значения:
1 — женщина,
2 — мужчина,
0 — любой (по умолчанию).

status(positive) - Семейное положение. Возможные значения:
1 — не женат (не замужем),
2 — встречается,
3 — помолвлен(-а),
4 — женат (замужем),
5 — всё сложно,
6 — в активном поиске,
7 — влюблен(-а),
8 — в гражданском браке.

age_from(positive) - Возраст, от.

age_to(positive) - Возраст, до.

birth_day(positive) - День рождения.

birth_month(positive) - Месяц рождения.

birth_year(positive) - Год рождения.

online - Учитывать ли статус «онлайн». Возможные значения:
1 — искать только пользователей онлайн,
0 — искать по всем пользователям.

has_photo - Учитывать ли наличие фото. Возможные значения:
1 — искать только пользователей с фотографией,
0 — искать по всем пользователям.

school_country(positive) - Идентификатор страны, в которой пользователи закончили школу.

school_city(positive) - Идентификатор города, в котором пользователи закончили школу.

school_class(positive) - Буква класса.

school(positive) - Идентификатор школы, которую закончили пользователи.

school_year(positive) - Год окончания школы.

religion - Религиозные взгляды.

company - Название компании, в которой работают пользователи.

position - Название должности.

group_id - Идентификатор группы, среди пользователей которой необходимо проводить поиск.

from_list - Разделы среди которых нужно осуществить поиск, перечисленные через запятую. Возможные значения:
friends — искать среди друзей,
subscriptions — искать среди друзей и подписок пользователя.

screen_ref - Реферер, откуда был вызван метод

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/method/users.search)
