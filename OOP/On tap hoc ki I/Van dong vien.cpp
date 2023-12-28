#include <bits/stdc++.h>
using namespace std;

class HuyChuong
{
	int hcvang, hcbac, hcdong;
	
	public:
		void nhap()
		{
			cout << "Nhap so huy chuong vang: ";
			cin >> hcvang;				
			cout << "Nhap so huy chuong bac: ";
			cin >> hcbac;
			cout << "Nhap so huy chuong dong: ";
			cin >> hcdong;
		}
		void xuat()
		{
			cout << setw(3) << hcvang << "||" << setw(3) << hcbac << "||" << setw(3) << hcdong << "||" << endl;
		}

		int tong()
		{
			return hcvang + hcbac + hcdong;
		}
		
		int hcv()
		{
			return hcvang;
		}		
};

class Nguoi
{
	string hoten, gtinh, sothich, nuoc;
	
	public:
		void nhap()
		{
			cout << "Nhap ho ten: ";
			fflush(stdin);
			getline(cin, hoten);
			cout << "Nhap gioi tinh: ";
			getline(cin, gtinh);
			cout << "Nhap so thich: ";
			getline(cin, sothich);
			cout << "Nuoc: ";
			getline(cin, nuoc);
		}
		
		void xuat()
		{
			cout << left << setw(18) << hoten << "||" << setw(6) << gtinh << "||" << setw(10) << sothich << "||" << setw(12) << nuoc << "||";
		}
		
		string getn()
		{
			return nuoc;
		}
		
};

class VDV : public Nguoi
{
	string mtd;
	int nang, cao;
	HuyChuong hc;
	
	public:
		void nhap()
		{
			Nguoi::nhap();
			cout << "Nhap mon thi dau: ";
			fflush(stdin);
			getline(cin, mtd);
			cout << "Can nang: ";
			cin >> nang;
			cout << "Chieu cao: ";
			cin >> cao;
			hc.nhap();
		}
		
		void xuat()
		{
			Nguoi::xuat();
			cout << setw(10) << mtd << "||" << setw(6) << nang << "||" << setw(6) << cao << "||";
			hc.xuat(); 
		}
		
		int ccao()
		{
			return cao;
		}
		int gethc()
		{
			return hc.hcv();
		}
		
		int gettong()
		{
			return hc.tong();
		}
};

class Ungdung
{
	int n;
	VDV *a;
	
	public:
		void nhap()
		{
			cout << "Nhap so van dong vien: ";
			cin >> n;
			a = new VDV[n+2];
			for (int i = 0; i < n; i++)
			{
				cout << "Van dong vien thu " << i+1 << ":\n";
				a[i].nhap();
			}
		}
		
		void sx()
		{
			for (int i = 0; i < n-1; i++)
			{
				for (int j = i+1; j < n; j++)
				{
					if(a[i].ccao() > a[j].ccao())
						swap(a[i], a[j]);
				}
			}
			cout << "\nDanh sach theo thu tu tang dan ve chieu cao:\n";
			for (int i = 0; i < n; i++)
				a[i].xuat();
		}
		
		void max_hcv()
		{
			int max = 0;
			for (int i = 0; i < n; i++)
			{
				if(max < a[i].gethc())
					max = a[i].gethc();
			}
			cout << "\nVan dong vien co so huy chuong vang nhieu nhat la:\n";
			for (int i = 0; i < n; i++)
			{
				if(max == a[i].gethc())
					a[i].xuat();
			}
		}
		
		void thongke()
		{
			int t[]={};
			for (int i = 0; i < n; i++)
			{
				if(a[i].getn() == )
			}
		}
};

int main()
{
	Ungdung t;
	t.nhap();
	t.sx();
	t.max_hcv();

}

