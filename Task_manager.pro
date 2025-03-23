QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calendar.cpp \
    create_task.cpp \
    for_today.cpp \
    main.cpp \
    mainwindow.cpp \
    plans.cpp \
    unsorted.cpp

HEADERS += \
    calendar.h \
    create_task.h \
    for_today.h \
    mainwindow.h \
    plans.h \
    unsorted.h

FORMS += \
    calendar.ui \
    create_task.ui \
    for_today.ui \
    mainwindow.ui \
    plans.ui \
    unsorted.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
