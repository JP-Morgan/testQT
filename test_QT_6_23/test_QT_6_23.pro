QT       += core gui#Qt本身就是有模块+=就是在真加core gui模块

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#通用配置
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    test1_2.cpp

HEADERS += \
    test1_2.h

FORMS += \
    test1_2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
