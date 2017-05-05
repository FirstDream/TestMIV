#pragma once

#include <QOpenGLWidget>

#include "GraphicsRenderOpenGL/"

class Canvas : public QOpenGLWidget
{
	Q_OBJECT

public:
	Canvas(QWidget *parent = Q_NULLPTR);

	~Canvas();

};
