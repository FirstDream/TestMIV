/*
��ʾһ����Ⱦ����;
*/

#pragma once

#include <QObject>

class Scene : public QObject
{
	Q_OBJECT

public:
	Scene(QObject *parent);
	~Scene();
};
