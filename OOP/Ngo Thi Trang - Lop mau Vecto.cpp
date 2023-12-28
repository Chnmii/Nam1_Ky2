#include <bits/stdc++.h>
using namespace std;

template <class T> class vecto
{
	int n;
	float *x;
	public:
		friend istream& operator>>(istream &Cin, vecto &a)
		{	
			cout << "Nhap so chieu: ";
			Cin >> a.n;
			a.x = new float[a.n+5];
			for (int i=0; i<a.n; i++)
			{
				cout << "Toa do " << i+1 << ": ";
				Cin >> a.x[i];
			}
			return Cin;
		}

		friend ostream& operator<<(ostream &Cout, const vecto &a)
		{
			Cout << "(" << a.x[0];
			for (int i=1; i<a.n; i++)
			{
				Cout << "," << a.x[i];
			}
			Cout << ")";	
			return Cout;
		}

		vecto operator+(const vecto &b)
		{
			vecto c;
			c.n = n > b.n ? n : b.n;
			int min = n < b.n ? n : b.n;
			c.x = new float[c.n+5];
			for (int i=0; i<min; i++)
			{
				c.x[i] = x[i] + b.x[i];
			}
			for (int i=min+1; i<c.n; i++)
				c.x[i] = n > b.n ? x[i] : b.x[i];
			return c;
		}

		float operator*(const vecto &b)
		{
			float s=0;
			int min = n < b.n ? n : b.n;
			for (int i=0; i<min; i++)
				s += x[i]*b.x[i];
			return s;
		}

		vecto operator*(const int &k)
		{
			vecto t;
			t.n = n;
			t.x = new float[t.n+2];
			for (int i=0; i<t.n; i++)
				t.x[i] = k * x[i];
			return t;
		}
};

int main()
{
	vecto<float> a,b;
	int k;
	cout << "Nhap vecto a: ";
	cin >> a; 
	cout << endl << a;
	cout << "Nhap vecto b: ";
	cin >> b; 
	cout << endl << b; 
	
	cout << "\nTong 2 vecto vua nhap: " << a+b;
	cout << "\nTich vo huong 2 vecto vua nhap: " << a*b;
	cout << "\nNhap so nguyen k: ";
	cin >> k;
	cout << "k*a = " << a*k;
	
	return 0;
}

