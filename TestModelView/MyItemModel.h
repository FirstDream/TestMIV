#pragma once

#include <QAbstractItemModel>

class MyItemModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	MyItemModel(QObject *parent);
	~MyItemModel();

	//----------begin----------------------
	/*������������� QAbstractItemModel ���Ǵ��麯����������д;
	ȫΪconst ������ֻ�Ƕ�ȡ���ݵģ������޸�model������;
	*/
	//����ָ�����ڵ�����ǵ�����;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	//����;
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	//��������;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	//parent������;
	QModelIndex parent(const QModelIndex &index) const override;
	//����index
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
	//-----------end-------------------------

private:

};
