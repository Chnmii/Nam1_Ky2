#include<bits/stdc++.h>
using namespace std;

class ps
{
	private:
		int x;
    	int y;
	public:
		ps()
		{
			this->x = 0;
			this->y = 1;
		}
		ps(int x=0, int y=1)
		{
			this->x = x;
			this->y = y;
		}
		
		friend istream& operator>>(istream &is, ps &a);

        friend ostream& operator<<(ostream &os, const ps &a);
        
        friend ps rutgon(ps &a);

        friend ps operator+(const ps &a);

        friend ps operator-(const ps &a);
        
        friend ps operator*(const ps &a);
        
        friend ps operator/(const ps &a);
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
        
ps rutgon(ps &a)
{
    int b=abs(a.x);
    int c=abs(a.y);
    while(b!=c)
	{ 
        if(b>c) b-=c;
        else c-=b;
    }
    a.x=a.x/b;
    a.y=a.y/b;
    return a;
}

ps operator+(const ps &b)
{
    ps c;
    c.x = x*b.y + y*b.x;
    c.y = y*b.y;
	return c;
}

ps operator-(const ps &b)
{
    ps c;
    c.x = x*b.y - y*b.x;
    c.y = y*b.y;
	return c;
}
        
ps operator*( const ps &b)
{
    ps c;
    c.x = x * b.x;
    c.y = y * b.y;
	return c;
}
        
ps operator/( const ps &b)
{
    ps c;
    if(b.x==0)
     	cout<<"Khong the chia 2 pso";
	else
	{
     	c.x = x*b.y;
     	c.y = y*b.x;
    }
	return c;
}

int main()
{
	ps p1, p2, p3, p4, a, b, c, d;
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
	a = p1+p2; 
	b = p3-p4; 
	c = a/t; 
	d = c*p1;
	ps P=rutgon(d);
	cout << P;
	
	return 0;
}


