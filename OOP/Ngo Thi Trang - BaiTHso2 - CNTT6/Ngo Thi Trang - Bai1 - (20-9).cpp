#include<bits/stdc++.h>
using namespace std;

class ps
{
	private:
		int x;
    	int y;
	public:
		ps(){x = 0; y = 1;}
		ps(const int &_x, const int &_y)
		{
			x = _x;
			y = _y;
		}
		void rutgon()
		{
			int a = __gcd(x,y);
			x /= a;
			y /= a;
			if(y < 0)
			{
				y = -y;
				x = -x;
			}			
		}
		
		friend istream& operator>>(istream &is, ps &a);

        friend ostream& operator<<(ostream &os, const ps &a);
        
        friend ps rutgon(ps &a);

        ps operator+(const ps &);

        ps operator-(const ps &);
        
        ps operator*(const ps &);
        
        ps operator/(const ps &);
};

istream& operator>>(istream &is, ps &a)
{
	cout << "Nhap Tu so: " << endl; 
	is >> a.x;
	do
	{
		cout << "Nhap Mau so: " << endl; 
		is >> a.y;
		if(a.y==0)
		    cout<<"nhap lai mau so khac 0: ";
	}while(a.y==0);
	
	return is;
}

ostream& operator<<(ostream &os, const ps &a)
{
    os << a.x << "/" << a.y << endl;
    return os;
}

ps ps::operator+(const ps &b)
{
    int x,y;
    x = x*b.y + y*b.x;
    y = y*b.y;
	return ps(x,y);
}

ps ps::operator-(const ps &b)
{
    int x,y;
    x = x*b.y - y*b.x;
    y = y*b.y;
	return ps(x,y);
}
        
ps ps::operator*( const ps &b)
{
    int x,y;
    x = x * b.x;
    y = y * b.y;
	return ps(x,y);
}
        
ps ps::operator/( const ps &b)
{
    int x,y;
    if(x==0)
     	cout<<"Khong the chia 2 pso";
	else
	{
     	x = x*b.y;
     	y = y*b.x;
    }
	return ps(x,y);
}

int main()
{
	ps p1, p2, p3, p4, T;
	cout << "Nhap p1: ";  cin >> p1;
	cout << "Nhap p2: ";  cin>>p2;
	cout << "Nhap p3: ";  cin>>p3;
	cout << "Nhap p4: ";  cin>>p4;
	cout << "Cac phan so vua nhap:\n";
	cout << p1; 
	cout << p2; 
	cout << p3; 
	cout << p4;
	cout << "\nGia tri bieu thuc = ";
	T = (p1+p2)/(p3+p4)*p1;
	T.rutgon();
	cout << "(p1+p2)/(p3-p4)*p1 = " << T;
	
	return 0;
}


