#pragma once

#include <QMainWindow>
#include "ui_MainWindow.h"

#include <QTableView>

#include <QTableView>
#include <QListView>
#include <QTreeView>

#include "MyTableModel.h"
#include "MyListModel.h"
#include "MyItemModel.h"


class MainWindow : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private slots:
	void showWindowTitle(const QString& title);

private:
	QTableView* tableView_;
	MyTableModel* model_;

};
