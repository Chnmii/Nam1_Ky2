#include <bits/stdc++.h>
using namespace std;

class dathuc
{
	private: 
		int n;
		float *hs;
	public:
		dathuc(){ n=-1; hs = NULL; }
		
		dathuc(const dathuc &a)
		{
			n = a.n;
			hs = new float[n+2];
			for (int i=0; i<=n; i++)
				hs[i] = a.hs[i];
		}
		
		~dathuc() { if(hs) delete[]hs;}
		
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
				Cout << "+ " << setprecision(2) << fixed << a.hs[i] << "x^" << i;
			}
			return Cout;
		}	

		float tinhgt(const float &d=0)
		{	
    		float s=hs[0];
    		for (int i=1; i <= n; i++)
    		{
     		   s+= hs[i]*pow(d,i);
    		}
    		return s;
		}
};

int main()
{
	float d1, d2, P1, P2;
	dathuc P;
	cin >> P;
	cout << P;
	cout << "\nNhap vao d1, d2: ";
	cin >> d1 >> d2;
	P1 = P.tinhgt(d1);
	P2 = P.tinhgt(d2);
	if (P1 == P2)
		cout << "\nKo the tinh bieu thuc\n";
	else 
		cout << "\n1/(P(d1)-P(d2)) = " << setprecision(2) << fixed << 1.0/(P1-P2);
}
