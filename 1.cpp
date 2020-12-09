#include<iostream>
using namespace std;
//生成基类对象Base
class Base
{
public:
	int a;
protected:
	int b;
private:
	int c;
public:
	static int count;
public:
	Base(int,int,int);
	~Base();
	void print();
	static int statistic();//输出类的数据成员函数print（），统计类对象创建个数的函数 static int statistic（）
};
//定义基类对象Base的构造函数和析构函数
int Base::count = 0;
Base::Base(int m,int n,int k)
{
	a = m;
	b = n;
	c = k;
	count++;
	cout << "构造函数被调用" << endl;
}
Base::~Base()
{
	cout << "析构函数被调用" << endl;
	getchar();
}
//定义两个普通函数，输出类的数据成员函数print（），统计类对象创建个数的函数 static int statistic（）
void Base::print()
{
	cout << a <<" " << b <<" "<< c << endl;
}
int Base::statistic()
{
	return count;
}
//定义三种继承方式的子类对象derived1，derived2，derived3
class derived1:public Base
{
private:
	int l;
	//Base h1;
public:
	derived1(int z, int m, int n, int k) :Base(m, n, k)
	{
		l = z;
		count++;
		cout << l << endl;
		print();
		cout << l << a << endl;
	}
	~derived1();

};
class derived2 :private Base
{
private:
	int l;
	Base h2;
public:
	derived2(int z, int m, int n, int k);
	~derived2();
};
class derived3 :protected Base
{
private:
	int l;
	Base h3;
public:
	derived3(int z, int m, int n, int k);
	~derived3();
};
//定义derived1的构造和析构函数
/*derived1::derived1(int z, int m, int n, int k):Base(m,n,k)
{
	l = z;
	count++;
	cout << l << endl;
	h1.print();
	cout << l << h1.a  << endl;
}*/
derived1::~derived1()
{
	cout << "析构函数被调用" << endl;
	getchar();
}
//定义derived2的构造和析构函数
derived2::derived2(int z, int m, int n, int k) : Base(m, n, k),h2(m, n, k)
{
	l = z;
	count++;
	cout << l << endl;
	h2.print();
	
}
derived2::~derived2()
{
	cout << "析构函数被调用" << endl;
	getchar();
}
//定义derived3的构造和析构函数
derived3::derived3(int z, int m, int n, int k) : Base(m, n, k), h3(m, n, k)
{
	l = z;
	count++;
	cout << l << endl;
	h3.print();
	
}
derived3::~derived3()
{
	cout << "析构函数被调用" << endl;
	getchar();
}
int main()
{
	int b;
	Base hy(0,0,0);//统计对象个数的一个对象
	derived1 D(1,2,3,4);
	derived2 E(1,2,3,4);
	derived3 F(1,2,3,4);
	cout <<hy.statistic() << endl;//全局变量的输出有问题
	return 0;
}