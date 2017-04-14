#pragma once

#include <QAbstractItemModel>

class MyItemModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	MyItemModel(QObject *parent);
	~MyItemModel();

	//----------begin----------------------
	/*这五个个函数在 QAbstractItemModel 中是纯虚函数，必须重写;
	全为const 函数，只是读取数据的，不能修改model的数据;
	*/
	//返回指定父节点的子们的列数;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	//行数;
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	//返回数据;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	//parent的索引;
	QModelIndex parent(const QModelIndex &index) const override;
	//返回index
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
	//-----------end-------------------------

private:

};
