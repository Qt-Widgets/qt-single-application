#ifndef EVAPP_H
#define EVAPP_H

#include <QEvent>
#include <QApplication>
#include <QFileOpenEvent>





#define eventApplication \
    (static_cast<EventApplication*>(QCoreApplication::instance()))

class EventApplication : public QApplication
{
  Q_OBJECT
    public:
    EventApplication(int &argc, char **argv);

    signals:
         void signalFileOpen( const QString &f );
    public slots:

    protected:
    bool event (QEvent *event);
    private:

};

#endif // EVAPP_H
