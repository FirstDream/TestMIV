#include "MyTableModel.h"

#include <QDebug>
#include <QFont>
#include <QBrush>
#include <QPixmap>
#include <QTime>

MyTableModel::MyTableModel(QObject *parent)
	: QAbstractTableModel(parent)
{
	timer_ = new QTimer(this);
	//timer_->setInterval(1000);
	//connect(timer_, &QTimer::timeout, this, &MyTableModel::timerHit);
	//timer_->start();
}

MyTableModel::~MyTableModel()
{
}

int MyTableModel::rowCount(const QModelIndex & parent) const
{
	return ROWS;
}

int MyTableModel::columnCount(const QModelIndex & parent) const
{
	return COLS;
}

QVariant MyTableModel::data(const QModelIndex & index, int role) const
{

	int row = index.row();
	int col = index.column();

	qDebug() << QString("row %1, col%2, role %3")
		.arg(row).arg(col).arg(role);


	switch (role)
	{
	case Qt::DisplayRole: 

		return m_gridData[row][col];
		break;

	case Qt::FontRole:
		if (row == 0 && col == 0)
		{
			QFont font;
			font.setBold(true);
			return font;
		}

		break;

	case Qt::BackgroundRole:
		if (row == 1 && col == 2)
		{
			QBrush bg(Qt::red);
			return bg;
		}
		break;

	case Qt::TextAlignmentRole:
		if (row == 1 && col ==1 )
		{
			return Qt::AlignRight + Qt::AlignVCenter;
		}

		break;

	case Qt::CheckStateRole: 
		if (row ==1 && col == 0)
		{
			return Qt::Checked;
		}
		break;
	}

	return QVariant();
}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal) {
			switch (section)
			{
			case 0:
				return QString("first");
			case 1:
				return QString("second");
			case 2:
				return QString("third");
			}
		}
	}
	return QVariant();
}

bool MyTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{

	if ( role == Qt::EditRole )
	{
		m_gridData[index.row()][index.column()] = value.toString();

		QString result;
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				result += m_gridData[row][col] + ' ';
			}
		}
		emit editCompleted(result);
	}

	return true;
}

Qt::ItemFlags MyTableModel::flags(const QModelIndex & index) const
{
	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

void MyTableModel::timerHit()
{
	//选择左上角的单元格;
	QModelIndex topLeft = createIndex(0, 0);
	//发送信号给View，更新数据;
	emit dataChanged(topLeft, topLeft);

}
