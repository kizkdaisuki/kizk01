QT       += core gui charts

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
    core_base/appdata.cpp \
    core_base/appinit.cpp \
    core_base/base64helper.cpp \
    core_base/iconhelper.cpp \
    core_base/quihelper.cpp \
    data.cpp \
    dataprocess.cpp \
    form/frmmain.cpp \
    graphshow.cpp \
    main.cpp \
    mainwindow.cpp \
    people.cpp \
    subwindow.cpp

HEADERS += \
    core_base/appdata.h \
    core_base/appinit.h \
    core_base/base64helper.h \
    core_base/iconhelper.h \
    core_base/quihelper.h \
    data.h \
    dataprocess.h \
    form/frmmain.h \
    graphshow.h \
    head.h \
    mainwindow.h \
    people.h \
    subwindow.h

FORMS += \
    form/frmmain.ui \
    graphshow.ui \
    mainwindow.ui \
    subwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    core_base/qrc/font.qrc \
    core_base/qrc/image.qrc \
    core_base/qrc/qm.qrc \
    res.qrc
INCLUDEPATH += D:\MATLAB\R2017b\extern\include\
INCLUDEPATH += D:\MATLAB\R2017b\extern\include\win64
RESOURCES   += core_qss/qss.qrc


LIBS += -LD:\MATLAB\R2017b\extern\lib\win64\microsoft\ -llibeng
LIBS += -LD:\MATLAB\R2017b\extern\lib\win64\microsoft\ -llibmx
LIBS += -LD:\MATLAB\R2017b\extern\lib\win64\microsoft\ -llibmat

DISTFILES += \
    core_base/core_base.pri \
    core_base/h3.pri \
    core_base/qrc/font/fontawesome-webfont.ttf \
    core_base/qrc/font/iconfont.ttf \
    core_base/qrc/font/pe-icon-set-weather.ttf \
    core_base/qrc/image/bg_novideo.png \
    core_base/qrc/qm/qt_zh_CN.qm \
    core_base/qrc/qm/widgets.qm \
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
    first/readme.docx \
    form/form.pri

