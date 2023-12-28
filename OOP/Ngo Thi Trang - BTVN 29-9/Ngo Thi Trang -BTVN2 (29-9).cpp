#include<bits/stdc++.h>
using namespace std;

class toado
{
	private:
		float x, y;
	public:
		void nhap()
		{
			cout << "\nnhap toa do :";
			cin >> x >> y;
		}
		void xuat()
		{
			cout << "(" << x << "," << y << ")" << "\t";
		}
		double kc()
		{
			return sqrt(x*x+y*y);
		}
};

class diemmau : public toado
{
	private:
		int mau;
	public:
		void nhap()
		{
			toado :: nhap();
			cout << "\nnhap mau :";
			cin >> mau;
		}
		int getmau()
		{
			return mau;
		}
		void xuat()
		{
			toado::xuat();
			cout << mau << " ; ";
		}
};

class ds_diem
{
	private:
		int n;
		diemmau *a;
	public:
		void nhap()
		{
			cout << "nhap tong so diem : "; cin >> n;
			a = new diemmau[n+5];
			for(int i=0; i<n; i++)
			{
				cout << "\nnhap diem a[" << i+1 << "] :";
				a[i].nhap();
			}
		}
		void thongke(int x);
		void diemxanhat();
};

void ds_diem::thongke(int x)
{
	int check = 0;
	for(int i=0; i<n; i++)
		if(a[i].getmau() == x)
		{
			a[i].xuat();
			check ++;
		}
	if(check == 0)
		cout << "khong co diem mau " << x;
}

void ds_diem::diemxanhat()
{
	double kc = 0;
	for(int i=0; i<n; i++)
	{
		if(a[i].kc() > kc)
			kc = a[i].kc();
	}
	for(int i=0; i<=n; i++)
		if(a[i].kc() == kc)
			a[i].xuat();
}

int main()
{
	ds_diem A;
	A.nhap();
	cout << "\nkhong ke diem mau 1 : "; A.thongke(1);
	cout << "\nkhong ke diem mau 2 : "; A.thongke(2);
	cout << "\nkhong ke diem mau 3 : "; A.thongke(3);
	cout << "\ndiem xa goc tao do nhat : "; A.diemxanhat();
}
