#include "MyItemModel.h"

MyItemModel::MyItemModel(QObject *parent)
	: QAbstractItemModel(parent)
{
}

MyItemModel::~MyItemModel()
{
}

int MyItemModel::columnCount(const QModelIndex & parent) const
{
	return 0;
}

int MyItemModel::rowCount(const QModelIndex & parent) const
{
	return 0;
}

QVariant MyItemModel::data(const QModelIndex & index, int role) const
{
	return QVariant();
}

QModelIndex MyItemModel::parent(const QModelIndex & index) const
{
	return QModelIndex();
}

QModelIndex MyItemModel::index(int row, int column, const QModelIndex & parent) const
{
	return QModelIndex();
}
