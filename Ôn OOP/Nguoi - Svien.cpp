#include <bits/stdc++.h>
using namespace std;

class nguoi
{
	string ten, gt;
	int tuoi, ns;
	public:
		void nhap()
		{
			cout << "Nhap ten: ";
			fflush(stdin);
			getline(cin, ten);
			cout << "Tuoi: ";
			cin >> tuoi;
			cout << "Nam sinh: ";
			cin >> ns;
			cout << "Gioi tinh: ";
			fflush(stdin);
			getline(cin, gt);
		}
		void xuat()
		{
			cout << setw(15) << left << ten << "||" << setw(8) << tuoi << "||" << setw(8) << ns << "||" << setw(10) << gt << "||";
		}
			
};

class sv : public nguoi
{
	string msv, lop;
	float toan, ly, hoa;
	public:
		string getm() {return msv;}
		void nhap()
		{
			nguoi::nhap();
			cout << "MSV: ";
			fflush(stdin);
			getline(cin, msv);
			cout << "Lop: ";
			getline(cin, lop);
			cout << "Diem: ";
			cin >> toan >> ly >> hoa;
		}
		void xuat()
		{
			nguoi::xuat();
			cout << setprecision(2) << fixed;
			cout << setw(12) << msv << "||" << setw(10) << lop << "||" << setw(8) << toan << "||" << setw(8) << ly << "||" << setw(8) << hoa << endl;
		}
		double tong()
		{
			return toan+ly+hoa;
		}
};

class DS
{
	int n;
	sv *a;
	public:
		void nhap()
		{
			cout << "Moi nhap so sv: ";
			cin >> n;
			a = new sv [n + 5];
			for(int i = 0; i < n; i++)
			{
				cout<<"Moi nhap sv thu " << i + 1 << ": " << endl;
				a[i].nhap(); 
			}
		}
		void xuat()
		{
			cout << "\nDanh sach sv: " << endl;
			for(int i = 0; i < n; i++)
			{
				a[i].xuat(); 
			}
		}
		void sx()
		{
			for(int i=0; i<n-1; i++)
			{
				for(int j=i+1; j<n; j++)
					if(a[i].tong() > a[j].tong())
						swap(a[i], a[j]);
			}
		}
		void find()
		{
			int d=0;
			string t;
			cout << "Nhap msv can tim: ";
			cin >> t;
			for (int i=0; i<n; i++)
			{
				if (a[i].getm() == t)
				{
					d++;
					a[i].xuat();
				}
			}
			if (d == 0)
				cout << "\nKo co sinh vien can tim";
		
		}
};

int main()
{
	DS a;
	a.nhap();
	a.xuat();
	a.sx();
	a.find();
}

