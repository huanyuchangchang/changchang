#include<iostream>
using namespace std;
//���ɻ������Base
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
	static int statistic();//���������ݳ�Ա����print������ͳ������󴴽������ĺ��� static int statistic����
};
//����������Base�Ĺ��캯������������
int Base::count = 0;
Base::Base(int m,int n,int k)
{
	a = m;
	b = n;
	c = k;
	count++;
	cout << "���캯��������" << endl;
}
Base::~Base()
{
	cout << "��������������" << endl;
	getchar();
}
//����������ͨ���������������ݳ�Ա����print������ͳ������󴴽������ĺ��� static int statistic����
void Base::print()
{
	cout << a <<" " << b <<" "<< c << endl;
}
int Base::statistic()
{
	return count;
}
//�������ּ̳з�ʽ���������derived1��derived2��derived3
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
//����derived1�Ĺ������������
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
	cout << "��������������" << endl;
	getchar();
}
//����derived2�Ĺ������������
derived2::derived2(int z, int m, int n, int k) : Base(m, n, k),h2(m, n, k)
{
	l = z;
	count++;
	cout << l << endl;
	h2.print();
	
}
derived2::~derived2()
{
	cout << "��������������" << endl;
	getchar();
}
//����derived3�Ĺ������������
derived3::derived3(int z, int m, int n, int k) : Base(m, n, k), h3(m, n, k)
{
	l = z;
	count++;
	cout << l << endl;
	h3.print();
	
}
derived3::~derived3()
{
	cout << "��������������" << endl;
	getchar();
}
int main()
{
	int b;
	Base hy(0,0,0);//ͳ�ƶ��������һ������
	derived1 D(1,2,3,4);
	derived2 E(1,2,3,4);
	derived3 F(1,2,3,4);
	cout <<hy.statistic() << endl;//ȫ�ֱ��������������
	return 0;
}