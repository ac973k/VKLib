QT       += core gui network webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    $$PWD/src/Account/Account.cpp \
    $$PWD/src/Auth/VKAuth.cpp \
    $$PWD/src/Groups/Groups.cpp \
    $$PWD/src/Photos/Photos.cpp \
    $$PWD/src/Wall/Wall.cpp

HEADERS += \
    $$PWD/src/Account/Account.h \
    $$PWD/src/Auth/VKAuth.h \
    $$PWD/src/Groups/Groups.h \
    $$PWD/src/Photos/Photos.h \
    $$PWD/src/Wall/Wall.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
