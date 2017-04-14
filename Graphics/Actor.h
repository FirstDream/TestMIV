/**
Actor 表示渲染场景(Scene)中的一个实体;

*/


#pragma once

#include <QObject>
#include <QPointer>

#include "Transform.h"


class Actor : public QObject
{
	Q_OBJECT

public:
	Actor(QObject *parent);
	~Actor();

	virtual void render();

	Transform* getModelTransform() { return this->model_transform_; }
	void setModelTransform(Transform* trans) { this->model_transform_ = trans; }

private:
	QPointer<Transform> model_transform_;

};

