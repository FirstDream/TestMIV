/*
表示一个渲染场景;
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
