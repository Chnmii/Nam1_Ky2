#include <bits/stdc++.h>
using namespace std;

class Nguoi
{
	string hoten, maso, gtinh;
	int ns;
	
	public:
		void nhap()
		{
			cout << "Nhap ho ten: ";
			fflush(stdin);
			getline(cin, hoten);
			cout << "Nhap ma so: ";
			getline(cin, maso);
			cout << "Nhap nam sinh: ";
			cin >> ns;
			cout << "Nhap gioi tinh: ";
			fflush(stdin);
			getline(cin, gtinh);
		}
		
		void xuat()
		{
			cout << left << setw(18) << hoten << "||" << setw(10) << maso << "||" << setw(6) << ns << "||" << setw(5) << gtinh << "||";
		}
		
		int nam()
		{
			return ns;
		}
		
		string gioi()
		{
			return gtinh;
		}
};

class HocVien : public Nguoi
{
	int sogio, solan;
	
	public:
		void nhap()
		{
			Nguoi::nhap();
			cout << "Nhap so gio tham gia lop hoc: ";
			cin >> sogio;
			cout << "Nhap so lan tuong tac: ";
			cin >> solan;
		}
		
		void xuat()
		{
			Nguoi::xuat();
			cout << setw(5) << sogio << "||" << setw(5) << solan << "||" << endl;
		}
		
		int gio()
		{
			return sogio;
		}
		
		int ttac()
		{
			return solan;
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
		
		void min_tuoi()
		{
			int min = a[0].nam();
			for (int i = 0; i < n; i++)
			{
				if (min < a[i].nam())
					min = a[i].nam();
			}
			cout << "\nHoc vien tre nhat:\n";
			for (int i = 0; i < n; i++)
			{
				if (min == a[i].nam())
					a[i].xuat();
			}
		}
		
		void sx()
		{
			for (int i = 0; i < n-1; i++)
			{
				for (int j = i+1; j < n; j++)
				{
					if(a[i].gio() > a[j].gio())
						swap(a[i], a[j]);
				}
			}
			cout << "\nDanh sach hoc vien khi sap xep tang dan theo so gio tham gia lop hoc:\n";
			for (int i = 0; i < n; i++)
				a[i].xuat();
		}
		
		void find()
		{
			int max = a[0].ttac(), d = 0;
			for (int i = 0; i < n; i++)
			{
				if (a[i].gioi() == "nu" && max < a[i].ttac())
				{
					d++;
					max = a[i].ttac();
				}
			}
			if (d==0)
			{
				cout << "\nKhong co hoc vien nu nao";
				return;
			}
				
				
			cout << "\nHoc vien nu co so luot tuong tac nhieu nhat la:\n";
			for (int i = 0; i < n; i++)
			{
				if (a[i].gioi() == "nu" && max == a[i].ttac())
					a[i].xuat();
			}
			
		}
};

int main()
{
	Ungdung t;
	t.nhap();
	t.min_tuoi();
	t.sx();
	t.find();
	
	return 0;
}

