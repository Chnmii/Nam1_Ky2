#include <bits/stdc++.h>
using namespace std;

class nguoi
{
	string ten, gt;
	int tuoi, ns;
	public:
		string get_ten() {return ten;}
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

class gv : public nguoi
{
	string mgv; 
	int sonam;
	double hsl, thuong, tong;
	public:
		int get_nam() {return sonam;}
		double get_t() {return thuong;}
		void nhap()
		{
			nguoi::nhap();
			cout << "MGV: ";
			fflush(stdin);
			getline(cin, mgv);
			cout << "So nam kinh nghiem: ";
			cin >> sonam;
			cout << "Thuong them: ";
			cin >> thuong;
		}
		
		void xuat()
		{
			nguoi::xuat();
			cout << setprecision(2) << fixed;
			cout << setw(12) << mgv << "||" << setw(10) << sonam << "||" << setw(10) << thuong << "||";
		}
		
		double tongluong(gv a, double lcb)
		{
			if (get_nam() > 20)	return 3*lcb + a.get_t();
			else if(get_nam() > 10 && get_nam() <= 20)	return 2*lcb + a.get_t();
			else return 1*lcb + a.get_t();
		}
};

class DS
{
	int n;
	gv *a;
	public:
		void nhap()
		{
			cout << "Moi nhap so giang vien: ";
			cin >> n;
			a = new gv [n + 5];
			for(int i = 0; i < n; i++)
			{
				cout<<"Moi nhap giang vien thu " << i + 1 << ": " << endl;
				a[i].nhap(); 
			}
		}
		void xuat()
		{
			cout << "\nDanh sach giang vien: " << endl;
			for(int i = 0; i < n; i++)
			{
				a[i].xuat(); 
			}
		}
		void sx(double lcb)
		{
			for(int i=0; i<n-1; i++)
			{
				for(int j=i+1; j<n; j++)
					if(a[i].tongluong(a[i], lcb) < a[j].tongluong(a[j], lcb))
						swap(a[i], a[j]);
			}
			for(int i=0; i<n; i++)
			{
				a[i].xuat();
				cout << setw(12) << left << a[i].tongluong(a[i], lcb);
			}
		}
		void find()
		{
			int d=0;
			string t;
			cout << "Nhap ten giang vien can tim: ";
			cin >> t;
			for (int i=0; i<n; i++)
			{
				if (a[i].get_ten() == t)
				{
					d++;
					a[i].xuat();
				}
			}
			if (d == 0)
				cout << "\nKo co giang vien can tim";
		}
};

int main()
{
	DS a;
	double lcb;
	a.nhap();
	a.xuat();
	cout << "Nhap luong co ban: ";
	cin >> lcb;
	a.sx(lcb);
	
}

