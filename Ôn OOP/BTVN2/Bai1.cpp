#include <bits/stdc++.h>
using namespace std;

class SoPhuc 
{
    double a, b;
    public:
    	SoPhuc(const double &_a, const double &_b)
    	{
    		a = _a;
    		b = _b;
    	}
    	SoPhuc()
    	{
    		a = 0;
    		b = 0;
		}
    
        friend istream & operator>>(istream &is, SoPhuc &p)
        {
        	cout << "Nhap so phuc (a + bi): ";
    		cin >> p.a >> p.b;
    		return is;
		}
        friend ostream & operator<<(ostream &os, SoPhuc p)
		{
			if (p.b >= 0)
        		os << p.a << "+" << p.b << "i\t";
        	else
        		os << p.a << "-" << -p.b << "i\t";
    		return os;
		}
		SoPhuc operator+(const SoPhuc &x)
		{
			SoPhuc c;
			c.a = this->a + x.a;
			c.b = this->b + x.b;
			return c;
		}
	
		SoPhuc operator*(const SoPhuc &x)
		{
			SoPhuc d;
			d.a = this->a*x.a - this->b*x.b;
			d.b = this->a*x.b + x.a*this->b;
			return d;
		}
};

class DSSoPhuc 
{
    SoPhuc *a;
    int n;
    public:
        DSSoPhuc() {n = 0; a = NULL;}
        DSSoPhuc(int m) {n = m;  a = new SoPhuc[m+2];}
        void nhap()
        {
        	cout << "Nhap so phan tu: ";
    		cin >> n;
    		a = new SoPhuc[n+2];
    		for(int i=0; i<n; i++) cin >> a[i];
		}
        void xuat()
		{
			for(int i=0; i<n; i++) 
        		cout << a[i];
		}
		void tong()
		{
			SoPhuc s;
			for (int i=0; i<n; i++)
			{
				s = s + a[i];
			}
			cout << s;
		}
		void tich()
		{
			SoPhuc s(1,0);
			for (int i=0; i<n; i++)
			{
				s = s * a[i];
			}
			cout << s;
		}
};


int main() 
{
    DSSoPhuc a;
    a.nhap();
   // a.xuat();
    a.tong();
    a.tich();
    return 0;
}
