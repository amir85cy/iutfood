QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminpage.cpp \
    edituser.cpp \
    iutfood_firstpage.cpp \
    loginwindow.cpp \
    main.cpp \
    reports.cpp \
    restaurant.cpp \
    restaurateurpage.cpp \
    signinwindow.cpp

HEADERS += \
    adminpage.h \
    edituser.h \
    iutfood_firstpage.h \
    loginwindow.h \
    reports.h \
    restaurant.h \
    restaurateurpage.h \
    signinwindow.h

FORMS += \
    adminpage.ui \
    edituser.ui \
    iutfood_firstpage.ui \
    loginwindow.ui \
    reports.ui \
    restaurant.ui \
    restaurateurpage.ui \
    signinwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
