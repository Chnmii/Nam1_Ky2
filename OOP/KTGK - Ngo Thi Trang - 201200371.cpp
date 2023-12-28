#include <bits/stdc++.h>
using namespace std;

class MT
{
    int n;
    int **tp;
    public:
        MT() {n=0; tp = NULL;}

        friend istream &operator >> (istream &is, MT &a)
        {
            cout << "Nhap cap cua ma tran: ";
            is >> a.n;
            a.tp = new int *[a.n+2];
            for (int i=0; i<a.n ;i++)
            {
                a.tp[i] = new int [a.n +2];
                for (int j=0; j<a.n; j++)
                {
                    cout << "a[" << i+1 << "][" << j+1 << "]: ";
                    is >> a.tp[i][j]; 
                }
            }
            return is;
        }

        friend ostream &operator<< (ostream &os, MT a)
        {
            for(int i=0; i<a.n; i++)
            {
                for (int j=0; j<a.n; j++)
                {
                    cout << a.tp[i][j] << "\t";
                }
                cout << "\n";
            }
            return os;
        }
        
        void operator=(const MT &a)
        {
        	n = a.n;
        	a.tp = new int*[a.n+2];
        	for(int i=0; i<a.n; i++)
        	{
        		a.tp[i] = new int[a.n +2];
        		for(int j=0; j<a.n; j++)
        			tp[i][j] = a.tp[i][j];
			}
		}

        friend void congmt(MT &a, MT &b)
        {
            if(a.n != b.n)  cout << "\nKhong the cong 2 ma tran khac bac";
            MT c;
            c.n = a.n;
            c.tp = new int*[c.n+2];
            for(int i=0; i<c.n; i++)
            {
                c.tp[i] = new int [c.n+2];
                for (int j=0; j<c.n; j++)
                {
                    c.tp[i][j] = a.tp[i][j] + b.tp[i][j];
                }
            }
        }

        friend double tbc(MT a)
        {
            int d=0, T=0;
            for(int i=0; i<a.n; i++)
            {
                for(int j=0; j<a.n; j++)
                {
                    if (a.tp[i][j] %2 == 0 && a.tp[i][j] > 20)
                    {
                        T += a.tp[i][j];
                        d++;
                    }
                }
            }
            return 1.0*T/d;
        }
};

int main()
{
    MT A, B, C;
    cout << "Ma tran A:\n";
    cin >> A;
    cout << "Ma tran B:\n";
    cin >> B;    
	
	cout << "Ma tran A vua nhap:\n" << A;
    cout << "Ma tran B vua nhap:\n" << B;
    
    C = congmt(A, B);
    cout << C;

	cout << "\nTBC cua A: " << tbc(A);
	cout << "\nTBC cua B: " << tbc(B);
}

