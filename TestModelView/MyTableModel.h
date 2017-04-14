#pragma once

#include <QAbstractTableModel>

#include <QTimer>

const int COLS = 3;
const int ROWS = 2;

class MyTableModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	MyTableModel(QObject *parent = 0);
	~MyTableModel();

	//-------------------begin--------------------------
	//对于 QAbstractTableModel 这三个函数必须重写;
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	//-------------------end----------------------------
	
	//-------------------begin--------------------------
	//可以重写的函数;
	//返回给定方向，数据角色，区段的header数据;
	//对于水平方向header， section = 列号, 垂直方向 section = 行号;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;


	//使Model可编辑;
	bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;
	Qt::ItemFlags flags(const QModelIndex & index) const override;

	//-------------------end----------------------------

private slots:
	void timerHit();

signals:
	void editCompleted(const QString &);

private:
	QTimer* timer_;

	QString m_gridData[ROWS][COLS];

};
