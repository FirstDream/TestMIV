#include "MainWindow.h"




MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);

	tableView_ = new QTableView(this);
	model_ = new MyTableModel(this);
	tableView_->setModel(model_);

	this->setCentralWidget(tableView_);

	connect(model_, &MyTableModel::editCompleted, this, &MainWindow::showWindowTitle);
}

MainWindow::~MainWindow()
{
}

void MainWindow::showWindowTitle(const QString & title)
{
	setWindowTitle(title);
}
