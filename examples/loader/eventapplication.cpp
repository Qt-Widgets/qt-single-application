#include "eventapplication.h"

#include <QDebug>
#include <QMenu>
#include <QDesktopWidget>



#ifdef Q_OS_MACOS
#include <AvailabilityMacros.h>
#include <QtMac>
extern void qt_mac_set_dock_menu(QMenu *);
#include <Carbon/Carbon.h>
#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFArray.h>
#include <CoreFoundation/CFDictionary.h>
#include <CoreFoundation/CFError.h>
#include <CoreFoundation/CFString.h>
#include <CoreFoundation/CFURL.h>
#include <CoreFoundation/CoreFoundation.h>
#include <CoreServices/CoreServices.h>
#endif




EventApplication::EventApplication(int &argc, char **argv) : QApplication(argc,argv)
{
          #ifdef Q_OS_MACOS
                       //// http://doc.qt.io/archives/qt-5.5/qmenu.html#setAsDockMenu
                      QMenu *macdocks = new QMenu();  //// menu by mac bar icons
                      macdocks->addAction(tr("&Mac Icon Exit Test"),this, SLOT(quit()));
                      macdocks->addSeparator();
                      qt_mac_set_dock_menu(macdocks);

                       /// CFURLRef appUrlRef = CFBundleCopyBundleURL(CFBundleGetMainBundle());
                       /// CFStringRef macPath = CFURLCopyFileSystemPath(appUrlRef,  kCFURLPOSIXPathStyle);
                       /// const char *pathPtr = CFStringGetCStringPtr(macPath,CFStringGetSystemEncoding());
                       /// qDebug("Path = %s", pathPtr);
                       /// CFRelease(appUrlRef);
                       /// CFRelease(macPath);

          #endif
          const int screenactive = this->desktop()->screenCount();
          qDebug() << "screen count " << screenactive;

}

bool EventApplication::event (QEvent *event)
   {

       qDebug() << "### EventApplication event in >>  " << event->type();
       // The system requested us to open a file
       if (event->type() == QEvent::FileOpen)
       {
       // Get the path of the file that we want to open
       const QString  file_path = static_cast<QFileOpenEvent *> (event)->file();
       emit this->signalFileOpen(file_path);
       } else {
         // The system requested us to do another thing, so we just follow the rules
         return QApplication::event (event);
       }
       return true;
   }
