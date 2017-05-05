#include "MainWindow.h"
#include <QtWidgets/QApplication>

#include <vector>

#include <QSettings>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setAttribute(Qt::AA_UseDesktopOpenGL, true);
	
	MainWindow w;
	w.show();
	return a.exec();



}
