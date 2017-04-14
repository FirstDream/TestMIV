#pragma once

#include <QAbstractListModel>

class MyListModel : public QAbstractListModel
{
	Q_OBJECT

public:
	MyListModel(QObject *parent = 0);
	~MyListModel();

	//������д���������麯��;
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};
