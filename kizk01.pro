QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dataprocess.cpp \
    main.cpp \
    mainwindow.cpp \
    people.cpp \
    subwindow.cpp

HEADERS += \
    dataprocess.h \
    mainwindow.h \
    people.h \
    subwindow.h

FORMS += \
    mainwindow.ui \
    subwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

INCLUDEPATH += D:\MATLAB\R2017b\extern\include\
INCLUDEPATH += D:\MATLAB\R2017b\extern\include\win64



LIBS += -LD:\MATLAB\R2017b\extern\lib\win64\microsoft\ -llibeng
LIBS += -LD:\MATLAB\R2017b\extern\lib\win64\microsoft\ -llibmx
LIBS += -LD:\MATLAB\R2017b\extern\lib\win64\microsoft\ -llibmat

DISTFILES += \
    first/BendedLine.mat \
    first/CShape.mat \
    first/DoubleBendedLine.mat \
    first/GShape.mat \
    first/JShape.mat \
    first/Khamesh.mat \
    first/Leaf_1.mat \
    first/Multi_Models_1.mat \
    first/NShape.mat \
    first/PShape.mat \
    first/Sine.mat \
    first/Zshape.mat \
    first/readme.docx

