#include <bits/stdc++.h>
using namespace std;

class A{
	int a1;
	protected: int a2;
	public: int a3;
	friend int main(); // ban be cua lop A
};

int main()
{
	A *x;
	x = new A;
	cout << sizeof(x);
//	x.a1=1;
//	x.a2=4;
//	x.a3=10;	
//	cout << "Cac thanh phan cua lop A:\n" << x.a1 << "\t" << x.a2<< "\t" << x.a3;
	
}
