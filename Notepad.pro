QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    notepad.cpp

HEADERS += \
    notepad.h

FORMS += \
    notepad.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc

DISTFILES += \
    ../../../../Desktop/icons/Actions-document-save-all-icon.png \
    ../../../../Desktop/icons/Actions-edit-cut-icon.png \
    ../../../../Desktop/icons/Document-Copy-icon.png \
    ../../../../Desktop/icons/Document-Write-icon.png \
    ../../../../Desktop/icons/Documents-icon.png \
    ../../../../Desktop/icons/File-New-icon.png \
    ../../../../Desktop/icons/Files-Clipboard-icon.png \
    ../../../../Desktop/icons/Files-icon.png \
    ../../../../Desktop/icons/Zoom-Out-icon (1).png \
    ../../../../Desktop/icons/delete-icon.png \
    ../../../../Desktop/icons/user-info-icon.png
