TEMPLATE	= app
LANGUAGE	= C++

TARGET		= loader


macx: {
   QT += macextras
}



include(../../config.pri)

DEPENDPATH	+= .
INCLUDEPATH	+= .

HEADERS		+= mainwindow.h \
                 eventapplication.h

SOURCES		+= main.cpp \
		      mainwindow.cpp \
                eventapplication.cpp

win32:LIBS	+= -luser32

include(../../singleapplication.pri)



RC_FILE = zzz.icns
QMAKE_INFO_PLIST = Info.plist
APP_QML_FILES.files = zzz.ico zzz.png testfile1.txt testfile2.txt
APP_QML_FILES.path = Contents/Resources
QMAKE_BUNDLE_DATA += APP_QML_FILES






RESOURCES += resourceapp.qrc
