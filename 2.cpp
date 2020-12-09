#include<iostream>
using namespace std;
/*�������һ����ά�ռ����Location*/
class Location
{
public:
	float x;
	float y;
public:
	Location(float a, float b);
	~Location();
	void move(float ch1, float ch2);//ch1Ϊx�ı�����ch2Ϊy�ı���
	void show();
	
};
/*������ں����Ķ���*/
Location::Location(float a,float b)
{
	x = a;
	y = b;
}
Location::~Location()
{
	cout << "��������������" << endl;
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
/*��Location��������ά�ռ��������Point*/
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
	void move(float ch1, float ch2, float ch3)//ch1Ϊx�ı�����ch2Ϊy�ı���,ch3Ϊz�ı���
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
/*��Pofloat������һ����ά�ռ��µ�������Sphere*/
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
	void move(float v5, float v6, float v7, float v8)//c1Ϊk1�ı�����c2Ϊk2�ı���
	{
		x += v5;
		y += v6;
		z += v7;
		r += v8;
	}
	void show()
	{
		cout << "����Ϊ" << '(' << x << ',' << y << ',' << z <<')' << endl;
		cout << "�뾶Ϊ" << r << endl;
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