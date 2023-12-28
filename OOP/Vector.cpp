#include <bits/stdc++.h>
using namespace std;

struct vecto
{
	int n;
	float *pt;
};

istream& operator>>(istream &Cin, vecto &a)
{	
	cout << "Nhap so chieu: ";
	Cin >> a.n;
	a.pt = new float[a.n+5];
	for (int i=0; i<a.n; i++)
	{
		cout << "Toa do " << i+1 << ": ";
		Cin >> a.pt[i];
	}
	return Cin;
}

ostream& operator<<(ostream &Cout, const vecto &a)
{
	cout << "(" << a.pt[0];
	for (int i=0; i<a.n; i++)
	{
		Cout << "," << a.pt[i];
	}
	cout << ")";	
	return Cout;
}

vecto operator+(const vecto &a, const vecto &b)
{
	vecto c;
	c.n = a.n > b.n ? a.n : b.n;
	int min = a.n < b.n ? a.n : b.n;
	c.pt = new float[c.n+5];
	for (int i = 0; i <= min; i++)
	{
		c.pt[i] = a.pt[i] + b.pt[i];
	}
	for (int i = min + 1; i < c.n; i++)
		c.pt[i] = a.n > b.n ? a.pt[i] : b.pt[i];
	return c;
}

float operator*(const vecto &a, const vecto &b)
{
	float s = 0;
	int min = a.n < b.n ? a.n : b.n;
	for (int i = 0; i < min; i++)
		s += a.pt[i] * b.pt[i];
	return s;
}

vecto operator*(const vecto &u, const int &k)
{
	vecto t;
	t.n = u.n;
	t.pt = new float[t.n+2];
	for (int i=0; i<t.n; i++)
		t.pt[i] = k * u.pt[i];
	return t;
}

main()
{
	vecto u[5];
	int k1,k2;
	for (int i=1; i<5; i++)
	{
		cout << "Nhap vector " << i << endl;
		cin >> u[i];
	}
	cout << "Nhap cac so nguyen k1, k2: ";
	cin >> k1 >> k2;
	cout << u[1]*k1 + u[2]*k2 + u[3] + u[4];
	// vector u trc k
	return 0;
}
