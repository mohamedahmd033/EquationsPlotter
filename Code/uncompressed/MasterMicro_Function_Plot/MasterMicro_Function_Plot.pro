QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Add_Substract_Parser_Replacor.cpp \
    Equation_Parser.cpp \
    Equation_Plotter.cpp \
    Equation_Validator.cpp \
    Multiplication_Devision_Parser_Replacor.cpp \
    Power_Parser_Replacor.cpp \
    Services.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    Add_Substract_Parser_Replacor.h \
    Equation_Parser.h \
    Equation_Plotter.h \
    Equation_Validator.h \
    Multiplication_Devision_Parser_Replacor.h \
    Power_Parser_Replacor.h \
    Services.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
