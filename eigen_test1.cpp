// ===========  vs2017 ====== Eigen3.3 ===========
// Eigen 练习向量的旋转、变换矩阵和四元数等

#include "stdafx.h"
#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <vector>
#include <cmath>

using namespace std;
using namespace Eigen;

#define MATSIZE 100
const double PI = 3.1415926;

void matrix_test();
int main()
{
	matrix_test();
	system("pause");
}

void matrix_test() 
{
	cout << "--------------MATRIX TEST-----------------" << endl;

	Vector3d v(1, 0, 0);	//原始坐标

	//旋转向量:
	//使用AngelAxis（底层不直接是Matrix），但可以当做矩阵运算（因为重载了运算符）
	AngleAxisd rotation_vector(PI / 4, Vector3d(0, 0, 1));	//绕z轴旋转pi/4角度（45度）

	//用AngelAxis进行坐标转换
	Vector3d v_result = rotation_vector * v;
	cout << "(1,0,0) after rotation: " << v_result.transpose() << endl;


	//旋转矩阵：
	Matrix3d rotation_matrix = rotation_vector.toRotationMatrix();	//从旋转向量转成旋转矩阵
	//用旋转矩阵
	v_result = rotation_matrix * v;
	cout << "(1,0,0) after rotation: " << v_result.transpose() << endl;


	//欧拉角：
	Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0);	//旋转矩阵 转成 ZYX顺序的欧拉角yaw/roll/pitch
	cout << "euler_angles: " << euler_angles.transpose() << endl;

	//欧式变换矩阵：
	Isometry3d T = Isometry3d::Identity();		//虽然称为3d,其实是4*4矩阵
	T.rotate(rotation_vector);	//根据旋转向量计算欧式变换矩阵
	T.pretranslate(Vector3d(1,3,4));	//平移向量设为（1，3，4）
	cout << "Transform matrix = \n" << T.matrix() << endl;

	//用变换矩阵进行坐标变换：
	v_result = T * v;
	cout << "after rotation:\n" << v_result << endl;

	//四元数
	Quaterniond q;
	q = Quaterniond(rotation_vector);//根据旋转向量定义四元数
	cout << "quaterniond = \n" << q.coeffs() << endl;	//coeffs顺序是（x,y,z,w）,w是实部，xyz为三个虚部
	q = Quaterniond(rotation_matrix);//根据旋转矩阵定义四元数
	cout << "quaterniond = \n" << q.coeffs() << endl;
	v_result = q * v;
	cout << "after rotation with quarternion :\n" << v_result << endl;
}
