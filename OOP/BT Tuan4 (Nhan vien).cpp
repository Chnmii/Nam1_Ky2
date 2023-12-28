#include <bits/stdc++.h>
using namespace std;

class nv
{
	private:
		string Ma, HT;
		int year;
		double luong;
	public:
		void nhap()
		{
			cout << "Ma: ";
			fflush(stdin);
			getline(cin, Ma);
			cout << "Ho ten: ";
			fflush(stdin);
			getline(cin, HT);
			cout << "Nam sinh: ";
			cin >> year;
			cout << "Luong: ";
			cin >> luong;
		}
		void xuat()
		{
			cout << setw(10) << left << Ma << " || " << setw(20) << HT << " || " << setw(10) << year << " || " << setw(10) << setprecision(2) << fixed << luong << " ||\n";
		}

	friend void maxtuoi(const int &, nv *);	
	friend void minluong(const int &, nv *);
	friend double luongtb(const int &, nv *);
};

void nhapds(int &n, nv *&ds)
{
	cout << "Moi nhap so nhan vien: ";
	cin >> n;
	ds = new nv[n+5];
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin nhan vien thu " << i+1 << ":\n";
		ds[i].nhap();
	}
}

void maxtuoi(const int &n, nv *ds)
{
	int min = ds[0].year;
	for(int i = 1; i < n; i++)
	{
		if(ds[i].year < min)
		{
			min = ds[i].year;
		}
	}
	cout << "Tuoi lon nhat: " << 2021 - min + 1 << endl;
	cout << "Nhan vien co tuoi cao nhat la:" << endl;
	for(int i = 0; i < n; i++)
	{
		if(ds[i].year == min)
		{
			ds[i].xuat();
		}
	}
}

void minluong(const int &n, nv *ds)
{
	double min = ds[0].luong;
	for(int i = 1; i < n; i++)
	{
		if(ds[i].luong < min)
		{
			min = ds[i].ns;
		}
	}
	
	cout << "Luong thap nhat: " << min << endl;
	cout << "Nhan vien co luong thap nhat la:" << endl;
	for(int i = 0; i < n; i++)
	{
		if(ds[i].luong == min)
		{
			ds[i].xuat();
		}
	}
}

double luongtb(const int &n, nv *ds)
{
	double S = 0;
	for(int i = 0; i < n; i++)
	{
		S += ds[i].luong;
	}
	return S / n;
}

int main()
{
	int n;
	nv *ds;
	nhapds(n, ds);
	maxtuoi(n, ds);
	minluong(n, ds);
	cout << "Luong trung binh: " << setprecision(2) << fixed << luongtb(n, ds);
}
