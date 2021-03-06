#-------------------------------------------------
#
# Project created by QtCreator 2016-12-22T10:04:07
#
#-------------------------------------------------

QT       += core gui sql network multimedia multimediawidgets quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Carmachine
LANGUAGE = C++
TEMPLATE = app

DEFINES += CONFIG_CTRL_IFACE

# 3399Linux、Big DPI
DEFINES += DEVICE_EVB

CONFIG	+= qt warn_on release

win32 {
  LIBS += -lws2_32 -static
  DEFINES += CONFIG_NATIVE_WINDOWS CONFIG_CTRL_IFACE_NAMED_PIPE
  SOURCES += setting/wpa_supplicant/src/utils/os_win32.c
} else:win32-g++ {
  # cross compilation to win32
  LIBS += -lws2_32 -static -mwindows
  DEFINES += CONFIG_NATIVE_WINDOWS CONFIG_CTRL_IFACE_NAMED_PIPE
  SOURCES += setting/wpa_supplicant/src/utils/os_win32.c
} else:win32-x-g++ {
  # cross compilation to win32
  LIBS += -lws2_32 -static -mwindows
  DEFINES += CONFIG_NATIVE_WINDOWS CONFIG_CTRL_IFACE_NAMED_PIPE
  DEFINES += _X86_
  SOURCES += setting/wpa_supplicant/src/utils/os_win32.c
} else {
  DEFINES += CONFIG_CTRL_IFACE_UNIX
  SOURCES += setting/wpa_supplicant/src/utils/os_unix.c
}


INCLUDEPATH +=$$PWD mainWindows
include(mainWindows/mainWindows.pri)

INCLUDEPATH +=$$PWD base
include(base/base.pri)

INCLUDEPATH +=$$PWD setting
include(setting/setting.pri)

INCLUDEPATH +=$$PWD music
include(music/music.pri)

INCLUDEPATH +=$$PWD video
include(video/video.pri)

INCLUDEPATH +=$$PWD gallery
include(gallery/gallery.pri)

INCLUDEPATH +=$$PWD camera
include(camera/camera.pri)


SOURCES +=$$PWD/singleApplication/qsingleapplication.cpp \

HEADERS +=$$PWD/singleApplication/qsingleapplication.h \

FORMS = networkconfig.ui \

RESOURCES += \
    res_main.qrc\
    res_music.qrc\
    res_camera.qrc\
    res_video.qrc \
    res_setting.qrc \
    res_gallery.qrc \
    qml.qrc

UI_DIR = .ui
MOC_DIR = .moc
OBJECTS_DIR = .obj

target.path = $$[QT_INSTALL_EXAMPLES]/multimedia/Carmachine
INSTALLS += target

