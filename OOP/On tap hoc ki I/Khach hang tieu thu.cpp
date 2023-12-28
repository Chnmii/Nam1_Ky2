#include <bits/stdc++.h>
using namespace std;

class KhachHang
{
	string ten, sdt;
	
	public:
		void nhap()
		{
			cout << "Nhap ten khach hang: ";
			fflush(stdin);
			getline(cin, ten);
			cout << "Nhap so dien thoai: ";
			getline(cin, sdt);			
		}	
		
		void xuat()
		{
			cout << left << setw(18) << ten << "||" << setw(12) << sdt << "||";
		}
		
		string getsdt()
		{
			return sdt;
		}
};

class KHTieuThu : public KhachHang
{
	int dt, sokhoi;
	
	public:
		void nhap()
		{
			KhachHang::nhap();
			cout << "Doi tuong(1: san xuat, 2: kinh doanh, 3: nha nuoc, 4: tieu dung): ";
			cin >> dt;
			cout << "So khoi tieu thu trong thang: ";
			cin >> sokhoi;
		}
		
		void xuat()
		{
			KhachHang::xuat();
			cout << setw(3) << dt << "||" << setw(5) << sokhoi << "||" << endl; 
		}
		
		int getdt()
		{
			return dt;
		}
		
		int getso()
		{
			return sokhoi;
		}
};

class Ungdung
{
	int n;
	KHTieuThu *a;
	
	public:
		void nhap()
		{
			cout << "Nhap so khach hang: ";
			cin >> n;
			a = new KHTieuThu[n+2];
			for (int i = 0; i < n; i++)
			{
				cout << "Khach hang thu " << i+1 << ":\n";
				a[i].nhap();
			}
		}
		
		void tongdt()
		{
			double s = 0;
			for (int i = 0; i < n; i++)
			{
				if(a[i].getdt() == 1)
					s += a[i].getso() * 2500;
				else if (a[i].getdt() == 2)
						s += a[i].getso() * 2200;
				else if (a[i].getdt() == 3)
						s += a[i].getso() * 1800;
				else s += a[i].getso() * 1500;
			}
			cout << "\nTong doanh thu cua cong ty kinh doanh nuoc sach la: " << s;
		}
		
		void find()
		{
			string m; int d = 0;
			cout << "\n\nNhap so dien thoai cua khach hang ban can tim: ";
			fflush(stdin);
			getline(cin, m);
			
			for (int i = 0; i < n; i++)
			{
				if (a[i].getsdt() == m)
				{
					a[i].xuat();
					d++;
				}
			}
			if (d == 0)
				cout << "\nKhong co khach hang nao co so dien thoai do";
		}
};

int main()
{
	Ungdung t;
	t.nhap();
	t.tongdt();
	t.find();

}

