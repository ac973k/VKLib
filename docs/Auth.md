# VKAuth

Метод авторизации в VK и получение access_token

- [VKAuth.startAuth](#VKAuth.startAuth)
- [Пример](#Пример)


## <a id="VKAuth.startAuth">VKAuth.startAuth</a>

`void startAuth(const QString &appId, const QString &scopes);`

В QString &appId передаётся ID приложения, в scopes необходимые параметры.

### Права доступа для токена пользователя

|Атрибут      |Битовые представления    |Описание                                                             |
|-------------|-------------------------|---------------------------------------------------------------------|
|notify       |(+ 1) (1 << 0)           |Пользователь разрешил отправлять ему уведомления (для flash/iframe-приложений).                                                                                     |
|friends      |(+ 2) (1 << 1)           |Доступ к друзьям.                                                    |
|photos       |(+ 4) (1 << 2)           |Доступ к фотографиям.                                                |
|audio        |(+ 8) (1 << 3)           |Доступ к аудиозаписям.                                               |
|video        |(+ 16) (1 << 4)          |Доступ к видеозаписям.                                               |
|stories      |(+ 64) (1 << 6)          |Доступ к историям.                                                   |
|pages        |(+ 128) (1 << 7)         |Доступ к wiki-страницам.                                             |
|menu         |(+ 256) (1 << 8)         |Добавление ссылки на приложение в меню слева.                        |
|status       |(+ 1 024) (1 << 10)      |Доступ к статусу пользователя.                                       |
|notes        |(+ 2 048) (1 << 11)      |Доступ к заметкам пользователя.                                      |
|messages     |(+ 4 096) (1 << 12)      |Доступ к расширенным методам работы с сообщениями (только для Standalone-приложений, прошедших модерацию).                                                                  |
|wall         |(+ 8 192) (1 << 13)      |Доступ к обычным и расширенным методам работы со стеной. Данное право доступа по умолчанию недоступно для сайтов (игнорируется при попытке авторизации для приложений с типом        «Веб-сайт» или по схеме Authorization Code Flow).                                                             |
|ads          |(+ 32 768) (1 << 15)     |Доступ к расширенным методам работы с рекламным API. Доступно для авторизации по схеме Implicit Flow или Authorization Code Flow.                                               |
|offline      |(+ 65 536) (1 << 16)     |Доступ к API в любое время (при использовании этой опции параметр expires_in, возвращаемый вместе с access_token, содержит 0 — токен бессрочный). Не применяется в Open API.    |
|docs         |(+ 131 072) (1 << 17     |Доступ к документам.                                                 |
|groups       |(+ 262 144) (1 << 18)    |Доступ к группам пользователя.                                       |
|notifications|(+ 524 288) (1 << 19)    |Доступ к оповещениям об ответах пользователю.                        |
|stats        |(+ 1 048 576) (1 << 20)  |Доступ к статистике групп и приложений пользователя, администратором которых он является.                                                                                          |
|email        |(+ 4 194 304) (1 << 22)  |Доступ к email пользователя.                                         |
|market       |(+ 134 217 728) (1 << 27)|Доступ к товарам.                                                    |
|phone_number |(+ 268 435 456) (1 << 28)|Доступ к номеру телефона.                                            |

Все параметры доступа можно найти тут [scopes](https://dev.vk.com/ru/reference/access-rights)


## <a id="Пример">Пример</a>

mainwindow.h:
	
```lang-cpp
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "..\VKLib/src/Auth/VKAuth.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void authVK(QStringList data);

private:
    Ui::MainWindow *ui;
    VK::Auth::VKAuth *auth;
    
    QString VKToken = "";
    int UserID = 0;
};
#endif // MAINWINDOW_H

```
	
mainwindow.cpp:
	
```lang-cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auth = new VK::Auth::VKAuth;
}

MainWindow::~MainWindow()
{
    delete auth;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    auth->startAuth("123", "status"); // 123 - ID приложения, status - доступ к статусу пользователя через токен.
    QObject::connect(auth, SIGNAL(authCompleted(QStringList)), this, SLOT(authVK(QStringList)));
}

void MainWindow::authVK(QStringList data) {
    VKToken = data[0];
    UserID = data[1].toInt();
}

```

### Что если потребуется доступ к нескольким функциям?
Допустим, мы хотим получить вечный токен с доступом к статусу и стене, тогда наша строка будет выглядеть так:

`QString scopes = "offline,status,wall";`

И передаём её:

```
VK::Auth::VKAuth auth;
auth.startAuth(ID_APP, scopes);
```
