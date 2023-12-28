#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

class mt
{
	private:
		int n;
		int **a;
	public:
		void nhap()
		{

			cin >> n;
			a = new int *[n + 1];
            for(int i = 0; i < n; i++)
            {
                a[i] = new int [n + 1];
                for(int j = 0; j < n; i++)    
                {
                    cout << "a[" << i << "][" << j << "]: ";
                    cin >> a[i][j];
                }
            }
        }
        void xuat()
        {
            int i, j;
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < n; j++)
                    cout << a[i][j] << "\t";
                cout << endl;
            }
        } 
        int tinhtong(const mt &b, mt &c);
        int max()
        {
            int max = INT_MIN;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(a[i][j] > max)    max = a[i][j];
                }
            }
            return max;
        }
        int sum()
        {
            int max = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    max += a[i][j];
                }
            }
            return max;
        }
        friend int main();
}; 

int mt :: tinhtong(const mt &b, mt &c)
{

    mt d;
    d = *this;
    if(d.n != b.n)
    {
        return 0;
    }
    c.n = b.n;
    c.a = new int *[c.n + 1];
    for(int i = 0; i < n; i++)
	{
        c.a[i] = new int [c.n + 1];
        for(int j = 0; j < n; j++)
        {
            c.a[i][j] = d.a[i][j] + b.a[i][j];
        }
    }
    return 1;
}

int main()
{
    mt A, B, C; 
	// mt *A = new mt;
	
    A.nhap(); //A->nhap();
    B.nhap();
    cout << "Ma tran A:" << endl;
    A.xuat();
    cout << "Ma tran B:" << endl;
    B.xuat();
    int k = A.tinhtong(B, C);

    if (!k)    
		cout << "Khong the cong 2 ma tran";
    else
    {
        cout << "Ma tran A + B:\n";
        C.xuat();
    }

    int x = A.max() + B.max();
	if(!x)    cout << "(sum(A)-sum(B))/(max(A)+max(B)) = " << (A.sum() - B.sum()) / x;
	else    cout << "Khong the tinh (sum(A)-sum(B))/(max(A)+max(B)";

}


