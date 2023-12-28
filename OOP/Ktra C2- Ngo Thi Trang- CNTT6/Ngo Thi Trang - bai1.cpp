#include <bits/stdc++.h>
using namespace std;

struct dso
{
	int n;
	int *x;
};

istream & operator >> (istream &Cin, dso &a)
{
	cout << "Nhap so phan tu: ";
	Cin >> a.n;
	a.x = new int[a.n+2];
	for (int i=0; i<a.n; i++)
	{
		cout << "Phan tu " << i+1 << " = ";
		Cin >> a.x[i];
	}
	return Cin;
}

ostream & operator << (ostream &Cout, const dso &a)
{
	for (int i=0; i<a.n-1; i++)
	{
		Cout << a.x[i] << ",";
	}
	Cout << a.x[a.n-1];
	return Cout;
}

dso operator+ (const dso &a, const dso &b)
{
	dso c;
	c.n = a.n + b.n;
	c.x = new int[c.n+2];
	
	for (int i=0; i<a.n; i++)
		c.x[i] = a.x[i];
	for (int i=a.n; i<c.n; i++)
		c.x[i] = b.x[i-a.n];
		
	return c;
}

dso operator+ (const int &k, const dso &a)
{
	dso b;
	b.n = a.n;
	b.x = new int[b.n+2];
	
	for (int i=0; i<b.n; i++)
	{
		b.x[i] = k + a.x[i];
	}
	return b;
}

main()
{
	dso A,B;
	cout << "Nhap day so A:\n"; cin >> A;
	cout << "Nhap day so B:\n"; cin >> B;
	cout << "A+B = " << "{" << A+B << "}" << endl;
	cout << "(2+A) + (5+B) = " << "{" << (2+A) + (5+B) << "}";
	
	return 0;
}

