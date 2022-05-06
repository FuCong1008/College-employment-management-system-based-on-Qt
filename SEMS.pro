#-------------------------------------------------
#
# Project created by QtCreator 2022-02-28T21:22:37
#
#-------------------------------------------------

QT       += core gui sql network axcontainer

RC_ICONS = icon3.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SEMS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        login.cpp \
    Database/databasemanagement.cpp \
    Warning/warninghint.cpp \
    Warning/configvalue.cpp \
    switchscreen.cpp \
    SubScreen/employmentinfo.cpp \
    SubScreen/employmentstatistics.cpp \
    SubScreen/usermanagement.cpp \
    SubScreen/addemploymentinfo.cpp \
    SubScreen/adduser.cpp \
    registeruser.cpp \
    SubScreen/studentinfo.cpp \
    SubScreen/addstudent.cpp \
    SubScreen/companyinfo.cpp \
    SubScreen/addcompany.cpp \
    Network/tcpserver.cpp \
    Network/tcpclient.cpp \
    Network/universal.cpp \
    Network/udpc2c.cpp \
    Thread/tablesavetoexcel.cpp \
    Thread/threadoperateexcel.cpp
HEADERS += \
        login.h \
    Database/databasemanagement.h \
    Warning/warninghint.h \
    Warning/configvalue.h \
    switchscreen.h \
    SubScreen/employmentinfo.h \
    SubScreen/employmentstatistics.h \
    SubScreen/usermanagement.h \
    SubScreen/addemploymentinfo.h \
    SubScreen/adduser.h \
    variableset.h \
    registeruser.h \
    SubScreen/studentinfo.h \
    SubScreen/addstudent.h \
    SubScreen/companyinfo.h \
    SubScreen/addcompany.h \
    Network/tcpserver.h \
    Network/tcpclient.h \
    Network/universal.h \
    Network/udpc2c.h \
    Thread/tablesavetoexcel.h \
    Thread/threadoperateexcel.h

FORMS += \
        login.ui \
    switchscreen.ui \
    SubScreen/employmentinfo.ui \
    SubScreen/employmentstatistics.ui \
    SubScreen/usermanagement.ui \
    SubScreen/addemploymentinfo.ui \
    SubScreen/adduser.ui \
    registeruser.ui \
    SubScreen/studentinfo.ui \
    SubScreen/addstudent.ui \
    SubScreen/companyinfo.ui \
    SubScreen/addcompany.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
