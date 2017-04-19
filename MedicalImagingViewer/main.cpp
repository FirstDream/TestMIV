#include "MainWindow.h"
#include <QtWidgets/QApplication>

#include <vector>

#include <QSettings>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setAttribute(Qt::AA_UseDesktopOpenGL, true);
	
	QSettings settings(QApplication::applicationDirPath() + "/config.ini", QSettings::IniFormat);
	settings.beginGroup("logins");
	settings.setValue("app", QVariant(1));
	settings.endGroup();

	struct Login {
		QString userName;
		QString password;
	};
	QList<Login> logins;

	Login l1{ "a","1" };
	Login l2{ "b","2" };
	Login l3{ "c","3" };

	logins << l1 << l2 << l3;

	settings.beginWriteArray("logins");
	for (int i = 0; i < logins.size(); ++i) {
		settings.setArrayIndex(i);
		settings.setValue("userName", logins.at(i).userName);
		settings.setValue("password", logins.at(i).password);
	}
	settings.endArray();

	QList<Login> logins2;
	int size = settings.beginReadArray("logins");
	for (int i = 0; i < size; ++i) {
		settings.setArrayIndex(i);
		Login login;
		login.userName = settings.value("userName").toString();
		login.password = settings.value("password").toString();
		logins2.append(login);
	}
	settings.endArray();

	settings.beginWriteArray("logins");
	{
		settings.setArrayIndex(0);
		settings.setValue("userName", "e");
		settings.setValue("password", "5");
	}
	settings.endArray();

	MainWindow w;
	w.show();
	return a.exec();
}
