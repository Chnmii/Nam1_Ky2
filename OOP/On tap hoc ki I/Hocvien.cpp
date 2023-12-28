#include <bits/stdc++.h>
using namespace std;

class Nguoi
{
	string hoten, maso;
	int namsinh;
	
	public:
		void nhap()
		{
			cout << "Nhap ho ten: ";
			fflush(stdin);
			getline(cin, hoten);
			cout << "Nhap ma so: ";
			getline(cin, maso);
			cout << "Nhap nam sinh: ";
			cin >> namsinh;
		}
		
		void xuat()
		{
			cout << left << setw(20) << hoten << "||" << setw(10) << maso << "||" << setw(5) << namsinh << "||";
		}
		
		int get_nam() 
		{
			return namsinh;
		}
};

class HocVien : public Nguoi
{	
	int sogio, vaitro;
	
	public:
		void nhap()
		{
			Nguoi::nhap();
			cout << "Nhap so gio tham gia lop hoc: ";
			cin >> sogio;
			cout << "Vai tro(1: chu tri, 2: tham du): ";
			cin >> vaitro;
		}
		void xuat()
		{
			Nguoi::xuat();
			cout << setw(3) << sogio << "||" << setw(3) << vaitro << "||" << endl;
		}
		
		int get_gio()
		{
			return sogio;
		}
};

class Ungdung
{
	int n;
	HocVien *a;
	
	public:
		void nhap()
		{
			cout << "Nhap so hoc vien: ";
			cin >> n;
			a = new HocVien[n+2];
			for (int i = 0; i < n; i++)
			{
				cout << "Hoc vien thu " << i+1 << ":\n";
				a[i].nhap();
			}
		}
		
		void tuoimax()
		{
			cout << "\nThanh vien tuoi cao nhat:\n";
			int min = 2021;
			for (int i = 0; i < n; i++)
			{
				if (min > a[i].get_nam())
					min = a[i].get_nam();
			}
			for (int i = 0; i < n; i++)
				if (min == a[i].get_nam())
					a[i].xuat();
		}
		
		void sapxep()
		{
			cout << "\nDanh sach theo thu tu tang dan theo so gio:\n";
			for (int i = 0; i < n-1; i++)
			{
				for (int j = i+1; j < n; j++)
				{
					if (a[i].get_gio() > a[j].get_gio())
						swap(a[i], a[j]);
				}
			}
			for (int i = 0; i < n; i++)
				a[i].xuat();
		}
	
};

int main()
{
	Ungdung t;
	t.nhap();
	t.tuoimax();
	t.sapxep();

}

