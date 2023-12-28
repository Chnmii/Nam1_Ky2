#include <bits/stdc++.h>
using namespace std;

class MatHang
{
	string ma, ten, hangsx, timebh;
	double dongia;
	
	public:
		MatHang()
		{
			ma = this->ma;
			ten = this->ten;
			hangsx = this->hangsx;
			timebh = this->timebh;
			dongia = this->dongia;
		}
		
		void nhap()
		{
			cout << "Nhap ma hang: ";
			fflush(stdin);
			getline(cin, ma);
			cout << "Nhap ten hang: ";
			getline(cin, ten);
			cout << "Nhap hang san xuat: ";
			getline(cin, hangsx);
			cout << "Nhap thoi gian bao hanh: ";
			getline(cin, timebh);
			cout << "Nhap don gia: ";
			cin >> dongia;
		}
		
		void xuat()
		{
			cout << left << setw(8) << ma << "||" << setw(10) << ten << "||" << setw(10) << hangsx << "||" << setw(8) << timebh << "||" << setw(10) << dongia << "||";
		}
		
		double get_gia()
		{
			return dongia;
		}
	
		string get_hang()
		{
			return hangsx;
		}
};

class DienThoai : public MatHang
{
	string hdh, bxl; 
	double tl;
	
	public:
		void nhap()
		{
			MatHang::nhap();
			cout << "Nhap he dieu hanh: ";
			fflush(stdin);
			getline(cin, hdh);
			cout << "Nhap bo xu ly: ";
			getline(cin, bxl);
			cout << "Nhap trong luong: ";
			cin >> tl;
		}
		
		void xuat()
		{
			MatHang::xuat();
			cout << setw(10) << hdh << "||" << setw(8) << bxl << "||" << setw(5) << tl << "||" << endl;
		}
	
};

class Ungdung
{
	int n;
	DienThoai *t;
	
	public:
		void nhap()
		{
			cout << "Nhap so dien thoai: ";
			cin >> n;
			t = new DienThoai[n+2];
			for (int i = 0; i < n; i++)
			{
				cout << "Mat hang thu " << i+1 << ":\n";
				t[i].nhap();
			}
		}
		
		void find_gia(double a, double b)
		{
			int d=0;
			for(int i = 0; i < n; i++)
			{
				if(t[i].get_gia() >= a && t[i].get_gia() <= b)
				{
					t[i].xuat();
					d++;
				}	
			}
			if(d==0)
				cout << "\nKhong co dien thoai nao nam trong gia do";
		}
		
		void find_hang()
		{
			int d=0;
			string m;
			cout << "\nNhap hang san xuat ban muon tim: ";
			fflush(stdin);
			getline(cin, m);
			
			cout << "\nNhung dien thoai co hang san xuat do la:\n";
			for (int i = 0; i < n; i++)
			{
				if (t[i].get_hang() == m)
				{
					t[i].xuat();
					d++;
				}
			}
			if(d==0)
				cout << "\nKhong co dien thoai nao co hang san xuat ban can tim";
		}
};

int main()
{
	Ungdung A;
	double a,b;
	A.nhap();
	
	cout << "\nGia nam trong doan: ";
	cin >> a;
	cout << "den "; cin >> b;
	while(a>0 && b>0 && a<b)
	{
		A.find_gia(a,b);
	}
	cout << "\nBan phai nhap gia > 0 va gia dau phai nho hon gia cuoi";
	
	A.find_hang();
}

