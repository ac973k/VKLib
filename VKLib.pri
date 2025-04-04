QT       += core gui network webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    $$PWD/src/Account/Account.cpp \
    $$PWD/src/Auth/VKAuth.cpp \
    $$PWD/src/Calls/Calls.cpp \
    $$PWD/src/Donut/Donut.cpp \
    $$PWD/src/DownloadedGames/DownloadedGames.cpp \
    $$PWD/src/Gifts/Gifts.cpp \
    $$PWD/src/Groups/Groups.cpp \
    $$PWD/src/Likes/Likes.cpp \
    $$PWD/src/Notifications/Notifications.cpp \
    $$PWD/src/Photos/Photos.cpp \
    $$PWD/src/Stats/Stats.cpp \
    $$PWD/src/Status/Status.cpp \
    $$PWD/src/Streaming/Streaming.cpp \
    $$PWD/src/Translations/Translations.cpp \
    $$PWD/src/Users/Users.cpp \
    $$PWD/src/Utils/Utils.cpp \
    $$PWD/src/Wall/Wall.cpp

HEADERS += \
    $$PWD/src/Account/Account.h \
    $$PWD/src/Auth/VKAuth.h \
    $$PWD/src/Calls/Calls.h \
    $$PWD/src/Donut/Donut.h \
    $$PWD/src/DownloadedGames/DownloadedGames.h \
    $$PWD/src/Gifts/Gifts.h \
    $$PWD/src/Groups/Groups.h \
    $$PWD/src/Likes/Likes.h \
    $$PWD/src/Notifications/Notifications.h \
    $$PWD/src/Photos/Photos.h \
    $$PWD/src/Stats/Stats.h \
    $$PWD/src/Status/Status.h \
    $$PWD/src/Streaming/Streaming.h \
    $$PWD/src/Translations/Translations.h \
    $$PWD/src/Users/Users.h \
    $$PWD/src/Utils/Utils.h \
    $$PWD/src/Wall/Wall.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    $$PWD/README.md \
    $$PWD/docs/Account.md \
    $$PWD/docs/Auth.md \
    $$PWD/docs/Calls.md \
    $$PWD/docs/Donut.md \
    $$PWD/docs/DownloadedGames.md \
    $$PWD/docs/Gifts.md \
    $$PWD/docs/Likes.md \
    $$PWD/docs/Notifications.md \
    $$PWD/docs/Stats.md \
    $$PWD/docs/Status.md \
    $$PWD/docs/Streaming.md \
    $$PWD/docs/Translations.md \
    $$PWD/docs/Users.md \
    $$PWD/docs/Utils.md
