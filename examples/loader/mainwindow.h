#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QString>

#include <QMainWindow>

class QMdiArea;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = 0);
	~MainWindow();

public slots:
	void activate();
	void handleMessage(const QString& message);

private:
	QMdiArea* workspace;
};

#endif // MAINWINDOW_H
