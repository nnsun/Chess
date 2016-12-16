#-------------------------------------------------
#
# Project created by QtCreator 2016-11-25T17:45:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    board.cpp \
    piece.cpp \
    pawn.cpp \
    knight.cpp \
    bishop.cpp \
    rook.cpp \
    queen.cpp \
    king.cpp

HEADERS  += mainwindow.h \
    game.h \
    board.h \
    piece.h \
    pawn.h \
    knight.h \
    bishop.h \
    rook.h \
    queen.h \
    king.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
