#include <bits/stdc++.h>
using namespace std;

struct ps{
	int a,b;
};

istream& operator>>(istream &Cin, ps &A)
{
	cout << "Nhap tu so: ";
	Cin >> A.a;
	do {
		cout << "Nhap mau so khac 0: ";
		Cin >> A.b;
	} while(A.b == 0);
	return Cin;
	
}

ostream& operator<<(ostream &Cout, const ps& A)
{
	Cout << A.a << "/" << A.b << endl;
	return Cout;
}

ps operator+(const ps &A, const ps &B)
{
	ps C;
	C.a = A.a*B.b + A.b*B.a;
	C.b = A.b * B.b;
	return C;
}

ps operator*(const ps &A, const ps &B)
{
	ps C;
	C.a = A.a * B.a;
	C.b = A.b * B.b;
	return C;
}

main()
{
	ps p1, p2, p3, kq;
	cout << "Nhap phan so p1: " ; cin >> p1;
	cout << "Nhap phan so p2: " ; cin >> p2;
	cout << "Nhap phan so p3: " ; cin >> p3;
	
	cout << "p1 = " << p1;
	cout << "p2 = " << p2;
	cout << "p3 = " << p3;
	
	kq = (p1+p2)*p3;
	cout << "Ket qua = " << kq;
	
	return 0;
	
}

