#include <bits/stdc++.h>
using namespace std;

class sothuc
{
	int n;
	double *tp;
	public:
		sothuc() {n = 0; tp = NULL;}
		
		friend istream & operator >> (istream &is, sothuc &a)
		{
			cout << "Nhap so phan tu cua day: ";
			is >> a.n;
            a.tp = new double[a.n+2];
			for (int i=0; i<a.n; i++)
			{
				cout << "Nhap phan tu thu " << i+1 << ": " ;
				is >> a.tp[i];
			}
            return is;
		}
		
		friend ostream & operator << (ostream &os, sothuc a)
		{
			for (int i=0; i<a.n; i++)
			{
				os << a.tp[i] << "\t";
			}
            return os;
		}
		
		friend double max(sothuc &a)
		{
			double m = a.tp[0];
			for (int i=0; i<a.n; i++)
			{
				if (m < a.tp[i])
					m = a.tp[i];
			}
			return m;
		}
		
		friend double tb(sothuc a)
		{
			double T = 0;
			for (int i=0; i<a.n; i++)
				T += a.tp[i];
				
			return T/a.n;
		}
		
        friend bool operator > (sothuc &a, sothuc &b)
        {
	        return tb(a) > tb (b);
        }

};

int main()
{
	sothuc A, B;
	cout << "Day A:\n";
	cin >> A;
	cout << "Day B:\n";
	cin >> B;
	
    cout << "GTLN cua day A: " << max(A);
    cout << "\nGTLN cua day B: " << max(B);
    
    cout << "\nGTTB cua day A: " << tb(A);
    cout << "\nGTTB cua day B: " << tb(B);
    
    if (A>B) cout << "\nDay B co GTTB nho hon";
    else cout << "\nDay A co GTTB nho hon";
    
    return 0;
}

