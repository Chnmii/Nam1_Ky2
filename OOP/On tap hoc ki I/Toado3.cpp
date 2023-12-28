#include <bits/stdc++.h>
using namespace std;

class Toado
{
	double x,y,z;
	
public:
	
	Toado(double _x, double _y, double _z)
	{
		x = _x;
		y = _y;
		z = _z;	
	}
	
	Toado()
	{
		x = this->x;
		y = this->y;
		z = this->z;
	}
	
	friend istream &operator >> (istream &is, Toado &a)
	{
		is >> a.x >> a.y >> a.z;
		return is;
	}
	
	friend ostream &operator<< (ostream &os, Toado a)
	{
		os << "(" << a.x << "," << a.y << "," << a.z << ")" << "\n";
		return os;
	}
	
	double kc()
	{
		double d = sqrt(x*x + y*y + z*z);
		return d;
	}

};

int main()
{
	Toado A(1.2,2.5,3), B(2,9,5.6), C, D;
	cout << "Nhap toa do diem C: ";
	cin >> C;
	cout << "\nNhap toa do diem D: ";
	cin >> D; 
	 
	double t[5] = {A.kc(), B.kc(), C.kc(), D.kc()};
	double max = 0;
	for(int i = 0; i <= 3; i++)
	{
		if(max < t[i])
			max = t[i];
	}
	for (int i = 0; i <= 3; i++)
		if(max == t[i])
			cout << "Diem xa goc toa do nhat la: " << static_cast<char>(i+'A');
}

