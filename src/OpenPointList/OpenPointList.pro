QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    contactitem.cpp \
    contactlistmodel.cpp \
    contactoverviewdialog.cpp \
    edititemdialog.cpp \
    editopenpointitemdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    openpointlistmodel.cpp \
    sharedcontactlist.cpp

HEADERS += \
    contactitem.h \
    contactlistmodel.h \
    contactoverviewdialog.h \
    edititemdialog.h \
    editopenpointitemdialog.h \
    mainwindow.h \
    openpointlistmodel.h \
    sharedcontactlist.h

FORMS += \
    contactoverviewdialog.ui \
    edititemdialog.ui \
    editopenpointitemdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Stylesheet.qrc
