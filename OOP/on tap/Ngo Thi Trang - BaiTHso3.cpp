#include<bits/stdc++.h>
#include <string.h>
using namespace std;

const int n = 3;

class douong
{
	string tennuoc;
	int soluong;
	public:
	douong(string ten = "pepsi", int sl = 1)
	{
		tennuoc = ten;
		soluong = sl;
	}
	float tinhtiendouong()
	{
		float s=0;
		if(tennuoc == "cocacola")
			s += soluong*20000;
		if(tennuoc == "pepsi")
			s += soluong*15000;
		if(tennuoc == "sevenup")
			s += soluong*10000;
		return s;
	}
	void xuat1douong()
	{
		cout << setw(15) << left << tennuoc << "||"<< setw(8) << soluong << "||";
	}
};

class KH
{
	string ma;
	string ten;
	string sdt;
	int loaidv;
	douong ds[4];
	public:
		void nhap1kh()
		{
			cout << "Nhap ma KH: ";
			fflush(stdin);
			getline(cin, ma);
			cout << "Nhap ten KH: ";
			fflush(stdin);
			getline(cin, ten);
			cout << "SDT: ";
			getline(cin, sdt);
			cout << "Nhap so loai do uong:";
			//cin>>n;
			// ds= new douong[4];
			for(int i=1; i<=3; i++)
			{
				int sl;
				switch(i)
				{
					case 1: 
					{
						cout << "\nhay chon so lon cocacola: ";
						cin >> sl;  //soluong[i];
						ds[i] = douong("cocacola",sl);
						break;
					}
					case 2: 
					{
						cout << "\nhay chon so lon pepsi: ";
						cin >> sl;  //soluong[i];
						ds[i] = douong("pepsi",sl);
						break;
					}
					case 3: 
					{
						cout << "\nhay chon so lon seven up: ";
						cin >> sl;  //soluong[i];
						ds[i] = douong("sevenup",sl);
						break;
					}
				}
			}
			//ds[i].nhap1douong();
			cout << "Loai dich vu: ";
			cin >> loaidv;
		}
		float tiendouong()
		{
			float s = 0;
			for(int i=1; i<=n; i++)
			s += ds[i].tinhtiendouong();
			if(loaidv == 1)
				s += 2000000;
			else
				s += 1200000;
			return s;
		}
		float tienthue()
		{
			float s = 0;
			if(loaidv == 1)
				s += 2000000;
			else
				s += 1200000;
			return s;
		}
		void xuat1kh()
		{
			cout << setw(10) << left << "Ma KH: " << ma << setw(15) << "||" << "Ten KH: " << ten << setw(10) << "||" << "SDT: " << sdt << setw(8) << "||" << "Loai dich vu: " << loaidv << "||"<< setw(15) << "Thanh tien: " << tienthue() + tiendouong() << endl;
			cout << "Danh sach cac loai do uong cua KH: " << endl;
			for(int i=1; i<=n; i++)
			ds[i].xuat1douong();
			cout << endl;
		}
		string get_ten()
		{
			return ten;
		}
};

class QLKH
{
	KH *a;
	int m;
	public:
	void nhapdskh()
	{
		cout << "Nhap so luong khach hang: ";
		cin >> m;
		a = new KH [m+5];
		for(int i=0; i<m; i++)
		{
			cout << "Khach hang thu " << i+1 << endl;
			a[i].nhap1kh();
		}
	}
	void xuatdskh()
	{
		cout << "\nDanh sach khach hang: " << endl;
		for(int i=0; i<m; i++)
		a[i].xuat1kh();
	}
	void tongtien()
	{
		float s1 = 0, s2 = 0;;
		for(int i=0; i<m; i++)
		{
			s1 += a[i].tiendouong();
			s2 += a[i].tienthue();
		}
		
		cout << "\nTien do uong: " << s1 << endl;
		cout << "\nTien thue: " << s2 << endl;
		cout << "\nTong doanh thu: " << s1 + s2 << endl;
	}
	void find()
	{
		int c = 0;
		string s;
		cout << "\nNhap ten khach hang can tim: ";
		fflush(stdin);
		getline(cin, s);
		for(int i=0; i<m; i++)
		{
			if(s == a[i].get_ten())
			{
				a[i].xuat1kh();
				c++;
			}
		}
		if(c==0)	
			cout << "Khong co khach hang can tim" << endl;
	}

	void sapxep()
	{
		for(int i=0; i<m-1; i++)
		{
			for(int j=1; j<m; j++)
			{
				if(a[i].tiendouong() + a[i].tienthue() < a[j].tiendouong() + a[j].tienthue())
					swap(a[i], a[j]);
			}
		}
		xuatdskh();
	}
};

int main()
{
	QLKH a;
	a.nhapdskh();
	a.xuatdskh();
	a.find();
	a.tongtien();
	a.sapxep();
	
	return 0;
}

