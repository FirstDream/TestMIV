/*
表示一个变换矩阵;
线性变换：
平移缩放旋转。
*/


#pragma once

#include <QObject>
#include <glm\vec3.hpp>
#include <glm\mat4x4.hpp>

class Transform : public QObject
{
	Q_OBJECT

public:
	Transform(QObject *parent);
	~Transform();
	Transform(const Transform& trans);
	Transform& operator=(const Transform& rhs);


	void identity();
	void inverse();


	void setMatrix(const glm::mat4& mat);
	const glm::mat4& getMatrix() const { return this->mat_; }
	
	void preMultipy(const Transform& t);
	void postMultipy(const Transform& t);
	void preMultipy(const glm::mat4& mat);
	void postMultipy(const glm::mat4& mat);

	void translate(glm::vec3& xyz);
	void scale(glm::vec3 scale_xyz);
	void rotate(float angle, glm::vec3& axis);
	

private:
	glm::mat4 mat_;
	
};
Transform operator*(const Transform& lhs, const Transform& rhs);
