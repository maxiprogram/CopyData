#-------------------------------------------------
#
# Project created by QtCreator 2015-03-23T14:51:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CopyData
TEMPLATE = app


SOURCES += main.cpp\
        mainform.cpp \
    copy.cpp \
    threadcopy.cpp \
    logfile.cpp

HEADERS  += mainform.h \
    copy.h \
    threadcopy.h \
    logfile.h

FORMS    += mainform.ui
