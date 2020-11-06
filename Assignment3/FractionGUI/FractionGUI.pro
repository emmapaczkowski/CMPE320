QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    fractionLibrary/Fraction_global.h \
    fractionLibrary/fraction.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += “$$PWD/FractionGUI/fractionLibrary”

#LIBS += “$$PWD\FractionGUI\fractionLibrary\Fraction.dll”
#LIBS += “$$PWD/fractionLibrary/Fraction.dll” #you changes .dll to .lib
LIBS += "C:\Users\emmap\OneDrive - Queen's University\Third Year\CMPE320\Assignment3\FractionGUI\fractionLibrary\Fraction.dll"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



