#include <bits/stdc++.h>
using namespace std;

class A
{
	int a1;
	int *a2;
	public:
		A(const int &x = 1, const int &y = 100)
		{
			a1 = x;
			a2 = new int;
			*a2 = y;
		}
		void operator=(const A &x)
		{
			a1 = x.a1;
			a2 = new int;
			*a2 = *(x.a2);
		}
		A(const A &x)  // ham tao sao chep
		{
			a1 = x.a1;
			a2 = new int;
			*a2 = *(x.a2);
		}
		void xuat()
		{
			cout << a1 << "\t" << *a2 << endl;
		}
		void tranf()
		{
			a1++; (*a2)++;
		}
		~A() {if(a2)  delete []a2;}
};

class B : public A
{
	int b1;
	int *b2;
	public:
		B(const int &x = 1, const int &y = 100, const int &z = 0, const int &t = 50):A(x,y)
		{
			b1 = z;
			b2 = new int;
			*b2 = t;
		}
		void operator=(const B &x)  // toan tu gan
		{
			A::operator=((A)x);
			b1 = x.b1;
			b2 = new int;
			*b2 = *(x.b2);
		}
		B(const B &x):A((A)x)  // ham tao sao chep
		{
			b1 = x.b1;
			b2 = new int;
			*b2 = *(x.b2);
		}
		void xuat()
		{
			A::xuat();
			cout << b1 << "\t" << *b2 << endl;
		}
		void tranf()
		{
			a1++; (*a2)++;
		}
		~B() {if(b2)  delete []b2;}
};
int main()
{
	A a(-100); // goi den ham tao A
	A b(a);    // goi den ham tao sao chep A
	
	B x(1,2,3);  // goi den ham tao B
	x.xuat();
	B z=x;      // toan tu gan
	x.tranf();
	z.xuat();
	
	B y(x);    // goi ham tao sao chep B
	
}

