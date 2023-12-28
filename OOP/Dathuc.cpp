#include <bits/stdc++.h>
using namespace std;

class dathuc
{
	private: 
		int n;
		float *hs;
	public:
	friend istream& operator>>(istream &Cin, dathuc &a)
	{   
   		cout << "\nNhap bac cua da thuc: ";
    	Cin >> a.n;
    	a.hs= new float[a.n+1];
    	int i;
    	for(i=0; i <= a.n; i++)
    	{
    	    cout << "Nhap hs ung voi bac " << i << ": ";
    	    Cin >> a.hs[i];
    	}
    	while (a.hs[a.n] == 0)
    	{
    		cout << "nhap he so thu " << a.n << "khac 0: ";
    		Cin >> a.hs[a.n];
		}
		return Cin;
	}

	friend ostream & operator <<(ostream &Cout, const dathuc &a)
	{
    	Cout << a.hs[0];
		
		for (int i=1; i <= a.n; i++){
			Cout << "+ " << a.hs[i] << "x^" << i;
		}
		return Cout;
	}	

	dathuc operator+(const dathuc &b)
	{
		dathuc c;
		dathuc a = *this;
		int max = a.n > b.n ? a.n : b.n;
		int min = a.n < b.n ? a.n : b.n;
		c.n = max;
		c.hs = new float[c.n+1];
	
		for (int i=0; i <= min; i++)
    	{
			c.hs[i]= a.hs[i] + b.hs[i];
		}
		for (int i = min+1; i <= max; i++)
    	{
			c.hs[i]= a.n > b.n ? a.hs[i] : b.hs[i];
		}
		return c;
	}

	float operator+(const float &d)
	{	
    	float s=hs[0];
    	for (int i=1; i <= n; i++)
    	{
     	   s+= hs[i]*pow(d,i);
    	}
    	return s;
	}
	~dathuc(){}
};

int main()
{
	dathuc P, Q;
	cin >> P >> Q;
	cout << P+Q;
	cout << "\nP(-1) = " << P+(-1);
}
