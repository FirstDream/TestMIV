#include "MyListModel.h"

#include <QPixmap>

MyListModel::MyListModel(QObject *parent)
	: QAbstractListModel(parent)
{
}

MyListModel::~MyListModel()
{
}

int MyListModel::rowCount(const QModelIndex & parent) const
{
	return 3;
}

QVariant MyListModel::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	
	switch (role)
	{
	case Qt::DisplayRole:

		return QString("Row%1")
			.arg(row + 1);
		break;

	case Qt::DecorationRole:

		QPixmap pic("D:\\2.jpg");
		pic = pic.scaled(64, 64);
		return pic;
		break;
	}
	return QVariant();
}
