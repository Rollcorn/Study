QT += widgets
CONFIG += c++11 link_pkgconfig
PKGCONFIG += libmongocxx

SOURCES += \
        main.cpp \
        meteo.cpp

HEADERS += \
    meteo.h \
    mongoConnect.h
