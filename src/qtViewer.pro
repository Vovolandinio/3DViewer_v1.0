QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    qtViewer/dscene.cpp \
    qtViewer/main.cpp \
    qtViewer/mainwindow.cpp \
    parser/s21_rotate.c

HEADERS += \
    dscene.h \
    qtViewer/mainwindow.h \
    parser/s21_parser.h


FORMS += \
    qtViewer/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
