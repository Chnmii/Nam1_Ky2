#include <bits/stdc++.h>
using namespace std;

class DaThuc
{
	int bac;
	double *hs;
	
	public:
		friend istream &operator >> (istream &is, DaThuc &a)
		{
			cout << "Nhap bac cua da thuc: ";
			is >> a.bac;
			a.hs = new double[a.bac+2];
			for(int i = 0; i <= a.bac; i++)
			{
				cout << "Nhap he so bac " << i << ": ";
				is >> a.hs[i];
			}
			return is;
		}
		
		void xuat()
		{
			cout << hs[0];
			for (int i = 1; i <= bac; i++)
			{
				if(hs[i] >= 0)
					cout << " + " << hs[i] << "x^" << i;
				else if(hs[i] < 0)
						cout << " - " << -hs[i] << "x^" << i;
			}
		}
		
		double tinhgt(double d)
		{
			double s = hs[0];
			for(int i = 1; i <= bac; i++)
			{
				s += hs[i] * pow(d, i);
			}
			return s; 
		}
		
		void biendoi(DaThuc P)
		{
			bac = P.bac+1;
			hs = new double[P.bac+5];
			hs[0] = 2021;
			for (int i = 1; i <= P.bac+1; i++)
			{
				hs[i] = P.hs[i-1];
			}
		}

};

int main()
{
	DaThuc a, b;
	double d;
	cin >> a;
	cout << "Da thuc P(X) = ";
	a.xuat();
	
	cout << "\nDa thuc Q(x) = ";
	b.biendoi(a);
	b.xuat();
	
	cout << "\nNhap so thuc d: ";
	cin >> d;
	cout << "\nQ(d) = " << b.tinhgt(d);
	

}

