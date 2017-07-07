#include "widget.h"

#include <QtCore/QCoreApplication>

#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>

Widget::Widget(QWidget* parent) : QWidget(parent)
{
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(new QLabel(tr("Became to a Single Mode. start app once again...")));
	layout->addWidget(new QLabel(tr("PID: %1").arg(QCoreApplication::applicationPid())));
}

Widget::~Widget()
{
}

void Widget::handleMessage(const QString& message)
{
	QMessageBox::information(0, "", message, QMessageBox::Ok, QMessageBox::Ok);
}

#include "moc_widget.cpp"
