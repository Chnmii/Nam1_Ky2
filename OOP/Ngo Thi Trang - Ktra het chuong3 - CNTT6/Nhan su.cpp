#include <bits/stdc++.h>
using namespace std;

class NS
{
	string ht,cv;
	int tuoi;
	int ngay;
	public:
		NS operator=(const NS &a)
		{
			ht = a.ht;
			tuoi = a.tuoi;
			ngay = a.ngay;
			cv = a.cv;
			return *this;
		}
		
		NS (const NS &a)
		{
			ht = a.ht;
			tuoi = a.tuoi;
			ngay = a.ngay;
			cv = a.cv;
		}
		
		friend istream & operator>>(istream &is, NS &a)
		{
			cout << "Ho ten: ";
			fflush(stdin);
			getline(is,a.ht);
			cout << "Tuoi: ";
			is >> a.tuoi;
			cout << "Chuc vu: ";
			fflush(stdin);
			getline(is,a.cv);
			cout << "Ngay cong: ";
			is >> a.ngay;
		
			return is;
		}
		
		friend ostream & operator << (ostream &os, NS a)
		{
			cout << setw(15) << left << a.ht << "||" << setw(8) << a.tuoi << "||" << setw(8) << a.cv << "||" << setw(8) << a.ngay << endl; 
		
			return os;
		}
		
		friend void nhapds(int &n, NS *&ds)
		{
			cout << "Nhap so nguoi quan ly: ";
			cin >>n;
			ds = new NS[n+5];
			for (int i=0; i<n; i++)
				cin >> ds[i];
		}
		
		friend void xuat(const int &n, NS ds[])
		{
			for (int i=0; i<n; i++)
				cout << ds[i];
		}

		friend void mintuoi(int n, NS *a)
		{
			int min = a[0].tuoi;
			for (int i=0; i<n; i++)
			{
				if (min >= a[i].tuoi)
					min = a[i].tuoi;
			}
			for (int i=0; i<n; i++)
			{
				if (min == a[i].tuoi)
					cout << "\nNguoi co tuoi tre nhat: " << a[i];
			}
		}
		
		friend int pcap(NS a)
		{
			int pc;
			if (a.cv == "GD") pc = 10000000;
			else if (a.cv == "TP") pc = 5000000;
			else pc = 1000000;
			return pc;
		}
		
		friend int tcong(NS a)
		{
			int t;
			if (a.cv == "GD") t = 300000;
			else if (a.cv == "TP") t = 200000;
			else t = 100000;
			return t;
		}
		
		friend void maxluong(int n, NS *a)
		{
			int max = a[0].ngay*tcong(a[0])+pcap(a[0]);
			for (int i=0; i<n; i++)
			{
				if (max <= a[i].ngay*tcong(a[i])+pcap(a[i]))
					max = a[i].ngay*tcong(a[i])+pcap(a[i]);
			}
			for (int i=0; i<n; i++)
			{
				if (max == a[i].ngay*tcong(a[i])+pcap(a[i]))
					cout << "\nNguoi co luong cao nhat: " << a[i];
			}
		}
};

int main()
{
	NS *a; int n;
	nhapds(n,a);
	mintuoi(n,a);
	maxluong(n,a);
}

