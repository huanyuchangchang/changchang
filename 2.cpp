#include<iostream>
using namespace std;
/*定义基类一个二维空间点类Location*/
class Location
{
public:
	float x;
	float y;
public:
	Location(float a, float b);
	~Location();
	void move(float ch1, float ch2);//ch1为x改变量，ch2为y改变量
	void show();
	
};
/*完成类内函数的定义*/
Location::Location(float a,float b)
{
	x = a;
	y = b;
}
Location::~Location()
{
	cout << "析构函数被调用" << endl;
}
void Location::move(float ch1, float ch2)
{
	x += ch1;
	y += ch2;
}
void Location::show()
{
	cout << '(' << x << ',' << y << ')' << endl;
}
/*以Location派生出三维空间坐标点类Point*/
class Point :public Location
{
public:
	float z;
public:
	Point(float a, float b, float c):Location(a,b)
	{
		z = c;
	}
	~Point()
	{

	}
	void move(float ch1, float ch2, float ch3)//ch1为x改变量，ch2为y改变量,ch3为z改变量
	{
		x += ch1;
		y += ch2;
		z += ch3;
	}
	void show()
	{
		cout << '(' << x <<','<<y <<','<< z << ')' << endl;
	}

};
/*以Pofloat派生处一个三维空间下的球体类Sphere*/
class Sphere :public Point
{
public:
	float r;
	
public:
	Sphere(float v1,float v2,float v3,float v4):Point(v1,v2,v3)
	{
		r = v4;
		
	}
	~Sphere()
	{

	}
	void move(float v5, float v6, float v7, float v8)//c1为k1改变量，c2为k2改变量
	{
		x += v5;
		y += v6;
		z += v7;
		r += v8;
	}
	void show()
	{
		cout << "球心为" << '(' << x << ',' << y << ',' << z <<')' << endl;
		cout << "半径为" << r << endl;
	}
};
int main()
{
	Location L1(1.1,1.2);
	L1.show();
	L1.move(2.7, 8.5);
	L1.show();
	
	Point P1(1.1, 1.2, 1.3);
	P1.show();
	P1.move(1.3, 4.2, 5.4);
	P1.show();

	Sphere S1(1.1, 1.2, 1.3, 4.3);
	S1.show();
	S1.move(1.1, 1.2, 1.3, 4.3);
	S1.show();

	system("pause");
	return 0;
}