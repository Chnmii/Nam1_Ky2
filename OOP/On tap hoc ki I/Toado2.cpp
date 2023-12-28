#include <bits/stdc++.h>
using namespace std;

class Diem
{
	double x,y;
	public:
		Diem()
		{
			x = this->x;
			y = this->y;
		}
		
		friend istream &operator>> (istream &is, Diem &a)
		{
			is >> a.x >> a.y;
			return is;
		}
		
		friend ostream &operator << (ostream &os, Diem a)
		{
			os << "(" << a.x << "," << a.y << ")" << endl;
			return os;			
		}
		
		double kc()
		{
			double d = sqrt(x*x + y*y);
			return d;
		}
		
		double getx(){return x;}
		double gety(){return y;}
};



class DsDiem
{
	int n;
	Diem *a;
	
	public:
		void nhap()
		{
			cout << "Nhap so diem: ";
			cin >> n;
			a = new Diem[n+2];
			for (int i = 0; i < n; i++)
				cin >> a[i];
		}
		
		void find()
		{
			cout << "\nDiem xa goc toa do nhat la:\n";
			double max = 0;
			for (int i = 0; i < n; i++)
			{
				if (max < a[i].kc())
					max = a[i].kc();
			}
			for (int i = 0; i < n; i++)
				if (max == a[i].kc())
					cout << a[i];
		}
		
		void doan_max()
		{
			cout << "\nDoan dai nhat la doan noi 2 diem:\n";
			double max = 0;
			for (int i = 0; i < n-1; i++)
			{
				for (int j = i+1; j < n; j++)
				{
					double k = pow(a[i].getx() - a[j].getx(), 2) + pow(a[i].gety() - a[j].gety(), 2);
					if (max < k)
						max = k;
				}
			}
			for (int i = 0; i < n-1; i++)
				for (int j = i+1; j < n; j++)
				{
					double k = pow(a[i].getx() - a[j].getx(), 2) + pow(a[i].gety() - a[j].gety(), 2);
					if (max == k)
						cout << a[i] << a[j];
				}
		}
};

int main()
{
	DsDiem t;
	t.nhap();
	t.find();
	t.doan_max();

}

