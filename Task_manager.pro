QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calendarpage.cpp \
    create_task.cpp \
    fortodaypage.cpp \
    main.cpp \
    mainwindow.cpp \
    taskspage.cpp \
    unsortedpage.cpp

HEADERS += \
    calendarpage.h \
    create_task.h \
    fortodaypage.h \
    mainwindow.h \
    taskspage.h \
    unsortedpage.h

FORMS += \
    calendarpage.ui \
    create_task.ui \
    fortodaypage.ui \
    mainwindow.ui \
    taskspage.ui \
    unsortedpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
