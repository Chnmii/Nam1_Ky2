#include <bits/stdc++.h>
using namespace std;

struct diem{
	float x,y;
	friend istream & operator >> (istream &is, diem &d)
	{
		is >> d.x >> d.y;
		return is;
	}
	friend ostream & operator<< (ostream &os, const diem &d)
	{
		os << "(" << d.x << "," << d.y << ")";
		return os;
	}
	float operator>(const diem d2)
	{
		return (x*x+y*y) > (d2.x*d2.x + d2.y*d2.y);
	}
};

struct ts{
	string ht;
	float diem;
	friend istream & operator>>(istream &is, ts &t)
	{
		cout << "Ho ten: "; 
		fflush(stdin);
		getline(is, t.ht);
		cout << "Diem: "; cin >> t.diem;
		return is;
	}
	friend ostream & operator <<(ostream &os, const ts &t)
	{
		cout << setw(15) << left << t.ht << "||" << t.diem;
		return os;
	}
	int operator>(const ts a)
	{
		return diem>a.diem;
	}
};

template <class T> void nhap(int &n, T *&a)
{
	cout << "Nhap n: ";
	cin >> n;
	a = new T[n+2];
	for (int i=0; i<n; i++)
	{
		cout << "\nNhap pt " << i+1 << ": "; 
		cin >> a[i];
	}
}

template <class T> void xuat(int n, T *a)
{
	for (int i=0; i<n; i++)
	{
		cout << a[i] << " ";
	}
}

template <class T> T max(int n, T *a)
{
	T max = a[0];
	for (int i=0; i<n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

int main()
{
	int n;
	int *A;
	float *B;
	diem *C;
	ts *D;
	cout << "Nhap n: "; cin >> n;
	nhap(n, A);  xuat(n, A);
	max(n, A);
	nhap(n, B);  xuat(n, B);
	max(n, B);
	nhap(n, C);  xuat(n, C);
	max(n, C);
	nhap(n, D);  xuat(n, D);
	max(n, D);
	
}

