QT       += core gui network
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminpage.cpp \
    cart.cpp \
    edituser.cpp \
    global.cpp \
    history.cpp \
    iutfood_firstpage.cpp \
    loginwindow.cpp \
    main.cpp \
    managemenu.cpp \
    orderslist.cpp \
    panel.cpp \
    peygiri.cpp \
    reports.cpp \
    restaurant.cpp \
    restaurantcard.cpp \
    restaurantpage.cpp \
    restaurateurpage.cpp \
    shoppage.cpp \
    signinwindow.cpp

HEADERS += \
    adminpage.h \
    cart.h \
    edituser.h \
    global.h \
    history.h \
    iutfood_firstpage.h \
    loginwindow.h \
    managemenu.h \
    orderslist.h \
    panel.h \
    peygiri.h \
    reports.h \
    restaurant.h \
    restaurantcard.h \
    restaurantpage.h \
    restaurateurpage.h \
    shoppage.h \
    signinwindow.h

FORMS += \
    adminpage.ui \
    cart.ui \
    edituser.ui \
    history.ui \
    iutfood_firstpage.ui \
    loginwindow.ui \
    managemenu.ui \
    orderslist.ui \
    panel.ui \
    peygiri.ui \
    reports.ui \
    restaurant.ui \
    restaurantcard.ui \
    restaurantpage.ui \
    restaurateurpage.ui \
    shoppage.ui \
    signinwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
