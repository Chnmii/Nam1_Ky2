#include <bits/stdc++.h>
using namespace std;

struct ts
{
	string sbd, ht, trg;
	float diem;
};

istream & operator>>(istream &Cin, ts &a)
{
	cout << "SBD: ";
	fflush(stdin);
	getline(Cin, a.sbd);
	cout << "Ho ten: ";
	fflush(stdin);
	getline(Cin, a.ht);
	cout << "Diem: ";
	Cin >> a.diem;
	cout << "Truong: ";
	fflush(stdin);
	getline(Cin, a.trg);
	
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
	cout << setw(15) << left << a.sbd << "||" << setw(20) << a.ht << "||" << setw(10) << setprecision(2) << fixed << a.diem << "||" << setw(15) << a.trg << endl;
	return Cout;
}

void xuat(const int &n, ts ds[])
{
	for (int i=0; i<n; i++)
		cout << ds[i];
}

bool operator > (const ts &a, const ts &b)
{
	return a.diem > b.diem;
}

bool sx(const ts &a, const ts &b)
{
	return a > b;
}

main()
{
	int n; ts *ds;
	nhapds(n, ds);
	sort(ds, ds+n, sx);
	xuat(n, ds);
	
	return 0;
}
