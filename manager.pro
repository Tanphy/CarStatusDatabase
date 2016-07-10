QT += core sql
QT -= gui

TARGET = manager
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    dbmanager.cpp \
    datamanager.cpp \
    mrecord.cpp

HEADERS += \
    dbmanager.h \
    datamanager.h \
    mrecord.h \
    mfieldglobal.h


win32:CONFIG(release, debug|release): LIBS += -LC:/MinGW64/lib/ -lsqlite3
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/MinGW64/lib/ -lsqlite3

INCLUDEPATH += C:/MinGW64/include
DEPENDPATH += C:/MinGW64/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += C:/MinGW64/lib/libsqlite3.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += C:/MinGW64/lib/libsqlite3.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += C:/MinGW64/lib/sqlite3.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += C:/MinGW64/lib/sqlite3.lib

FORMS +=
