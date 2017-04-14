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
	//���� QAbstractTableModel ����������������д;
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	//-------------------end----------------------------
	
	//-------------------begin--------------------------
	//������д�ĺ���;
	//���ظ����������ݽ�ɫ�����ε�header����;
	//����ˮƽ����header�� section = �к�, ��ֱ���� section = �к�;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;


	//ʹModel�ɱ༭;
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
