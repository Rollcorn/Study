QT += widgets
CONFIG += c++11 link_pkgconfig
PKGCONFIG += libmongocxx

SOURCES += \
        main.cpp

HEADERS += \
    MyView.h \
    mongoConnect.h
