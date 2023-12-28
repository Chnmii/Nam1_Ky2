#include <bits/stdc++.h>
using namespace std;

struct mt
{
	int m,n;
	float **tp;
};

istream & operator >> (istream &Cin, mt &a)
{
	cout << "Nhap kich thuoc ma tran: ";
	Cin >> a.m >> a.n;
	a.tp = new float*[a.m * a.n];
	
	for (int i=0; i<a.m; i++)
	{
		a.tp[i] = new float[a.m+2];
		for (int j=0; j<a.n; j++)
		{
			cout << "tp[" << i+1 << "][" << j+1 << "] = ";
			Cin >> a.tp[i][j];
		}
	} 
	return Cin;
}

ostream & operator << (ostream &Cout, const mt &a)
{
	for (int i=0; i<a.m; i++)
	{
		for (int j=0; j<a.n; j++)
		{
			Cout << setw(9) << left << setprecision(2) << fixed << a.tp[i][j];
		}
		Cout << endl;
	}
	return Cout;
}

mt operator+ (const mt &a, const mt &b)
{
	mt c;
	c.m = a.m; c.n = a.n;
	c.tp = new float*[c.m * c.n];
	
	for(int i=0; i<c.m; i++)
	{
		c.tp[i] = new float[c.m+2];
		for(int j=0; j<c.n; j++)
		{
			c.tp[i][j] = a.tp[i][j] + b.tp[i][j];
		}
	}
	return c;
}

mt operator* (const mt &a, const mt &b)
{
	mt d;
	d.n = a.n; d.m = a.m; 
	d.tp = new float*[d.m * d.n];
	
	for(int i=0; i<d.m; i++)
	{
		d.tp[i] = new float[d.n+2];
		for(int j=0; j<d.n; j++)
		{
			d.tp[i][j]=0;
			for(int k=0; k<d.m; k++)
			{
				d.tp[i][j] += a.tp[i][k] * b.tp[k][j];
			}
		}
	}
	return d;
}

mt operator* (const int &k, const mt &a)
{
	mt e;
	e.m = a.m; e.n = a.n;
	e.tp = new float*[e.n * e.m];
	
	for (int i=0; i<e.m; i++)
	{
		e.tp[i] = new float[e.m+2];
		for (int j=0; j<e.n; j++)
		{
			e.tp[i][j] = k * a.tp[i][j];
		}
	}
	return e;
}

float operator! (const mt &a)
{
	float T=0;
	for (int i=0; i<a.m; i++)
	{
		for (int j=0; j<a.n; j++)
		{
			T += a.tp[i][j];
		}
	}
	return T;
}

main()
{
	mt a,b,c,h;
	cout << "Ma tran A:\n"; cin >> a;
	cout << "Ma tran B:\n"; cin >> b;
	cout << "Ma tran C:\n"; cin >> c;
	if(c.n == b.n && c.m == b.m)
	{
		h = b*c;
		if (h.m == a.m && h.n == a.n)
			cout << "2*A + B*C :\n" << 2*a + b*c;
		else 
			cout << "Bieu thuc ko thuc hien dc" << endl;
	}
	
	cout << "Ma tran co tong phan tu lon nhat la:\n";
	if (!a >= !b && !a >= !c) cout << a;
	if (!b >= !a && !b >= !c) cout << b;
	if (!c >= !b && !c >= !a) cout << c;
	
	return 0;
}
