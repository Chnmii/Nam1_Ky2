#include<bits/stdc++.h>
using namespace std;

class nguoi
{
	string cmnd, ten;
	int ns;
	public:
		nguoi(const string &_cmnd = "", const string &_ten = "", const int &_ns = 0)
		{
			cmnd = _cmnd;
			ten = _ten;
			ns = _ns;
		}
		void nhap()
		{
			cout << "Nhap so cmnd: ";
			fflush(stdin);
			getline(cin, cmnd);
			cout << "Nhap ten: ";
			getline(cin, ten);
			cout << "Nhap nam sinh: ";
			cin >> ns;
		}
		void xuat()
		{
			cout << setw(15) << left << cmnd << "||" << setw(20) << ten << "||" << setw(10) << ns;
		}
		int get_nam()
		{
			return ns;
		}
		string get_ten()
		{
			return ten;
		}
};

class CT : public nguoi
{
	int sbt, sptd;
	public:
		CT(const string &_cmnd = "", const string &_ten = "", const int &_ns = 0, const int &_sbt = 0, const int &_sptd = 0):nguoi(_cmnd, _ten, _ns)
		{
			sbt = _sbt;
			sptd = _sptd;
		}
		void nhap()
		{
			nguoi::nhap();
			cout << "Nhap so ban thang: ";
			cin >> sbt;
			cout << "Nhap so phut thi dau: ";
			cin >> sptd;
		}
		void xuat()
		{
			nguoi::xuat();
			cout << setw(10) << left << sbt << "||" << setw(10) << sptd << "||" << endl;
		}
		long tien()
		{
			if(sbt >= 5)	return 70000000;
			if((sbt >= 3 && sbt < 5) || sptd >= 500)	return 50000000;
			return 0;
		}
};

class ungdung
{
	int n;
	CT *a;
	public:
		void nhapds()
		{
			cout << "Nhap so cau thu: ";
			cin >> n;
			a = new CT [n+5];
			for(int i=0; i<n; i++)
			{
				cout<<"Cau thu thu " << i + 1 << ": "<<endl;
				a[i].nhap(); 
			}
		}
		void xuatds()
		{
			cout << "\nDanh sach cau thu: " << endl;
			//cout << setw(12) << left << "CMND"  << setw(20) << "Ten" << setw(8) << "namsinh" << setw(8) << "sbt" << setw(8) << "sptd" << endl;
			for(int i=0; i<n; i++)
			{
				a[i].xuat(); 
			}
		}
		void tuoi_min()
		{
			int max = 0;
			for(int i=0; i<n; i++)
			{
				if(a[i].get_nam() > max)	
					max = a[i].get_nam(); 
			}
			cout << "\nCau thu tre tuoi nhat: " << endl;
			//cout << setw(12) << left << "CMND"  << setw(20) << "Ten" << setw(8) << "namsinh" << setw(8) << "sbt" << setw(8) << "sptd" << endl;
			for(int i=0; i<n; i++)
			{
				if(a[i].get_nam() == max)	
					a[i].xuat();
			}
		}
		void tienthuong()
		{
			int d = 0;
			cout << "\nDanh sach thuong: " << endl;
			for(int i=0; i<n; i++)
			{
				if(a[i].tien() > 0)
				{
					d++;
					cout << a[i].get_ten() << "\t" << a[i].tien() << endl;
				}
			}
			
			if(d==0)	
				cout << "Khong co cau thu nao duoc nhan thuong" << endl;
		}
		~ungdung() {if(a) delete []a;}
};

int main()
{
	ungdung a;
	a.nhapds();
	a.xuatds();
	a.tuoi_min();
	a.tienthuong();
	
	return 0;
}
