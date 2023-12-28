#include <bits/stdc++.h>
using namespace std;

struct ts
{
	string ht;
	float diem;
};

istream & operator>>(istream &Cin, ts &a)
{
	cout << "Ho ten: ";
	fflush(stdin);
	getline(Cin, a.ht);
	cout << "Diem: ";
	Cin >> a.diem;
	
	return Cin;
}

void nhapds(int &n, ts *&ds)
{
	cout << "Nhap so thi sinh: "; cin >> n;
	ds = new ts[n+5];
	for (int i=0; i<n; i++)
	{
		cout << "Thi sinh " << i+1 << ": ";
		cin >> ds[i];
	}
}

ostream & operator<<(ostream &Cout, const ts &a)
{
	cout << setw(15) << left << a.ht << "||" << setw(10) << setprecision(2) << fixed << a.diem << endl;
	return Cout;
}

void xuat(const int &n, ts ds[])
{
	for (int i=0; i<n; i++)
		cout << ds[i];
}

void sx(const int &n, ts ds[])
{
	cout << "Danh sach thi sinh sau khi sap xep theo diem giam dan:\n";
	for (int i=0; i<n-1; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (ds[i].diem < ds[j].diem)
				swap(ds[i], ds[j]);
		}
	}
}

main()
{
	int n; ts *ds;
	nhapds(n, ds);
	sx(n, ds);
	xuat(n, ds);
}
