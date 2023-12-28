#include <bits/stdc++.h>
using namespace std;

class Diem
{
	float x,y;
	public:
		void nhap()
		{
			cout << "Moi nhap toa do: ";
			cin >> x >> y;
		}
		void xuat()
		{
			cout << setprecision(2) << fixed << "(" << x << "," << y << ")" << endl;
		}
		float getx() {return x;}
		float gety() {return y;}
};

class DayDiem
{
	int n;
	Diem *a;
	public:
		void nhap()
		{
			int n;
			cout << "Nhap so diem: "; cin >> n;
			a = new Diem[n+2];
			for (int i=0; i<n; i++)
			{
				cout << "Diem " << i+1 << ": ";
				a[i].nhap();
			}
		}
		void xuat()
		{
			cout << "Day diem vua nhap: ";
			for (int i=0; i<n; i++)
				a[i].xuat();			
		}
		float Tongkc()
		{
			float s=0;
			for (int i=0; i<n; i++)
			{
				s += sqrt(pow(a[i].getx(), 2) + pow(a[i].gety(), 2));
			}
			return s;
		}
		int DemTrongR(float R)
		{
			int d=0;
			for (int i=0; i<n; i++)
			{
				if (pow(a[i].getx(), 2) + pow(a[i].gety(), 2) < R*R)
					d++;
			}
			return d;
		}
		~DayDiem()
		{
			if(a)	delete []a;
		}
};

int main()
{
	DayDiem A;
	A.nhap();
	A.xuat();
	cout << "\nTong kc den goc toa do: "; A.Tongkc();
	cout << "So diem nam trong (O;R), R=6: "; A.DemTrongR(6.00);
}

