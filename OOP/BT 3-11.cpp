#include <bits/stdc++.h>
using namespace std;

class Ngay_thang
{
	int ngay, thang, nam;
	public:
		Ngay_thang(const int &_ngay = 1, const int &_thang = 1, const int &_nam = 2018)
		{
			ngay = _ngay;
			thang = _thang;
			nam = _nam;
		}
		
		friend istream &operator >> (istream &Cin, Ngay_thang &x)
		{
			cout << "Nhap ngay: ";
			Cin >> x.ngay;
			cout << "Nhap thang: ";
			Cin >> x.thang;
			cout << "Nhap nam: ";
			Cin >> x. nam;
			return Cin;
		}
		friend ostream &operator << (ostream &Cout, const Ngay_thang &x)
		{
			Cout << x.ngay << "/" << x.thang << "/" << x.nam << endl;
			return Cout;
		}
		int get_nam()
		{
			return nam;
		}
		int get_ngay()
		{
			return ngay;
		}		
		int get_thang()
		{
			return thang;
		}
		friend int operator < (const Ngay_thang &a, const Ngay_thang &b)
		{
			if(a.nam < b.nam)	return 1;
			if(a.nam > b.nam)	return 0;
			if(a.thang < b.thang)	return 1;
			if(a.thang > b.thang)	return 0;
			if(a.ngay < b.ngay)	return 1;
			if(a.ngay == b.ngay)	return 2;
			return 0;
		}
};

class SV
{
	string msv, ht, lop;
	Ngay_thang ngaysinh;
	int khoa;
	public:
		SV(const Ngay_thang &_ngaysinh = Ngay_thang(1, 1, 2019), const string &_msv = "", const string &_lop = "", const string &_ht = "", const int &_khoa = 58)
		{
			lop = _lop;
			msv = _msv;
			ht = _ht;
			ngaysinh = _ngaysinh;
			khoa = _khoa;
		}
		
		nhap()
		{	
			cout << "Moi nhap msv: ";
			fflush(stdin);
			getline(cin, msv);
			cout << "Moi nhap ht: ";
			fflush(stdin);
			getline(cin, ht);
			cout << "Moi nhap lop: ";
			fflush(stdin);
			getline(cin, lop);
			cout << "Nhap ngay sinh\n";
			cin >> ngaysinh;
			do
			{
				cout << "Nhap khoa (58 - 62): ";
				cin >> khoa;
			}
			while(khoa != 58 && khoa != 59 && khoa != 60 && khoa != 61 && khoa != 62);
		}
		
		xuat()
		{
			cout << setw(10) << left << msv << setw(20) << ht << setw(10) << lop << setw(15) << khoa << endl;
			cout << ngaysinh;
		}
		int get_khoa()
		{
			return khoa;
		}
		
		friend int operator < (const SV &a, const SV &b)
		{
			return a.ngaysinh < b.ngaysinh;
		}
};

class DV : public SV
{
	Ngay_thang nvd;
	public:
		DV(const Ngay_thang &_nvd = Ngay_thang(1, 1, 2018), const Ngay_thang &_ngaysinh = Ngay_thang(1, 1, 2018), const string &_msv = "", const string &_lop = "", const string &_ht = "", const int &_khoa = 58) : SV(_ngaysinh, _msv, _lop, _ht, _khoa)
		{
			nvd = _nvd;
		}
		nhap()
		{
			SV::nhap();
			cout << "Moi nhap ngay vao dang\n";
			cin >> nvd;
		}
		xuat()
		{
			SV::xuat();
			cout << setw(15) << nvd;
		}
		int get_year()
		{
			return nvd.get_nam();
		}
};

class ungdung
{
	int n;
	DV *a;
	public:
		void nhapds()
		{
			cout << "Moi nhap so DV: ";
			cin >> n;
			a = new DV [n + 5];
			for(int i = 0; i < n;i++)
			{
				cout<<"Moi nhap DV thu " << i + 1 << ": "<<endl;
				a[i].nhap(); 
			}
		}
		void xuatds()
		{
			cout << "\nDanh sach DV: " << endl;
			for(int i = 0; i < n; i++)
			{
				a[i].xuat(); 
			}
		}
		void trenhat()
		{
			DV x = a[0];
			for(int i = 1; i < n; i++)
			{
				if(x < a[i])	x = a[i]; 
			}
			cout << "\nDV tre tuoi nhat: " << endl;
			for(int i = 0; i < n; i++)
			{
				if((x < a[i]) == 2)	a[i].xuat();
			}
		}
		void sapxep()
		{
			for(int i = 1; i < n - 1; i++)
			{
				for(int j = i + 1; j < n; j++)
				{
					if(a[j].get_year() < a[i].get_year())
					{
						DV x = a[i];
						a[i] = a[j];
						a[j] = a[i]; 
					}
				}
			}
		}
		~ungdung()
		{
			if(a)	delete []a;
		}
		void thongke()
		{
			int m[5] = {0};
			for(int i = 0; i < n; i++)
			{
				m[a[i].get_khoa() - 58]++;
			}
			cout << endl;
			for(int i = 0; i < 5; i++)
			{
				cout << "So dang vien theo khoa " << i + 58 << ": " << m[i] << endl;
			}
		}
};

int main()
{
	ungdung x;
	x.nhapds();
	x.sapxep();
	x.xuatds();
	x.trenhat();
	x.thongke();
	
	return 0;
}

