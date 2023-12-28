#include <bits/stdc++.h>
using namespace std;

class MatHang
{
	string ma, ten, hangsx;
	int sl;
	double dongia;
	
	public:
		MatHang(const string &_ma="", const string &_ten="", const string &_hangsx="", const int &_sl=0, const double &_dongia=0)
		{
			ma = _ma;
			ten = _ten;
			hangsx = _hangsx;
			sl = _sl;
			dongia = _dongia;
			
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
			cout << "So luong: ";
			cin >> sl;
			cout << "Don gia: ";
			cin >> dongia;
		}
		void xuat()
		{
			cout << left << setw(10) << ma << "||" << setw(15) << ten << "||" << setw(15) << hangsx << "||" << setw(3) << sl << "||" << setw(10) << dongia << "||" ;
		}
		
		string get_hang()
		{
			return hangsx;
		}
		
		double get_gia()
		{
			return dongia;
		}
};

class Laptop : public MatHang
{
	string CPU, RAM, HDH;
	double TL;
	
	public:
		Laptop(const string &_ma="", const string &_ten="", const string &_hangsx="", const int &_sl=0, const double &_dongia=0, const string &_CPU="", const string &_RAM="", const string &_HDH="", const int &_TL=0) : MatHang(_ma, _ten, _hangsx, _sl, _dongia)
		{
			CPU = _CPU;
			RAM = _RAM;
			HDH = _HDH;
			TL = _TL;			
		}
		void nhap()
		{
			MatHang::nhap();
			cout << "CPU: ";
			fflush(stdin);
			getline(cin, CPU);
			cout << "RAM: ";
			getline(cin, RAM);
			cout << "He dieu hanh: ";
			getline(cin, HDH);
			cout << "Trong luong: ";
			cin >> TL;
		}
		void xuat()
		{
			MatHang::xuat();
			cout << setw(5) << CPU << "||" << setw(5) << RAM << "||" << setw(8) << HDH << "||" << setw(5) << TL << "||" << endl;
		}
		
};

class Ungdung
{
	int n;
	Laptop *a;
	
	public:
		void nhap()
		{
			cout << "Nhap so laptop: ";
			cin >> n;
			a = new Laptop[n+2];
			for (int i = 0; i < n; i++)
			{
				cout << "Mat hang thu " << i+1 << ":\n";
				a[i].nhap();
			}
				
		}
		
		void find()
		{
			string m; int d=0;
			cout << "Nhap hang san xuat ban can tim: ";
			fflush(stdin);
			getline(cin, m);
			
			for (int i = 0; i < n; i++)
			{
				if (a[i].get_hang() == m)
				{
					a[i].xuat();
					d++;
				}
			}
			if (d==0)
				cout << "\nKhong co hang san xuat ban can tim";
		}
		
		void min_gia()
		{
			cout << "\nLaptop ca gia thap:\n ";
			double min = a[0].get_gia();
			for (int i = 0; i < n; i++)
				if (min > a[i].get_gia())
					min = a[i].get_gia();
			for (int i = 0; i < n; i++)
				if (min == a[i].get_gia()) 
					a[i].xuat();
		}
};

int main()
{
	Ungdung t;
	t.nhap();
	t.find();
	t.min_gia();

}

