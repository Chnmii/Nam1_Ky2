#include <bits/stdc++.h>
using namespace std;

class MaTran
{
	int bac;
	int **hs;
	
	public:
		
		friend istream &operator>> (istream &is, MaTran &a)
		{
			cout << "Nhap cap cua ma tran: ";
			is >> a.bac;
			a.hs = new int*[a.bac+2];
			for(int i = 0; i < a.bac; i++)
			{
				a.hs[i] = new int[a.bac+2];
				for (int j = 0; j < a.bac; j++)
				{
					cout << "Phan tu a[" << i+1 << "][" << j+1 << "]: ";
					is >> a.hs[i][j];
				}
			}
			return is;
		}
		
		friend ostream&operator<< (ostream &os, MaTran a)
		{
			for (int i = 0; i < a.bac; i++)
			{
				for (int j = 0; j < a.bac; j++)
				{
					os << a.hs[i][j] << "\t";
				}
				os << "\n";
			}
			return os;
		}
	
		int max()
		{
			int max = hs[0][0];
			for (int i = 0; i < bac; i++)
			{
				for (int j = 0; j < bac; j++)
				{
					if (max < hs[i][j])
						max = hs[i][j];
				}
			}
			cout << "\nPhan tu lon nhat cua ma tran la: ";
			return max;
		}
		
		double tbc()
		{
			int s = 0, d=0;
			for (int i = 0; i < bac; i++)
			{
				for (int j = 0; j < bac; j++)
				{
					if (hs[i][j] %2 != 0 && i < j)
					{
						s += hs[i][j];
						d++;
					}
				}
			}
			return 1.0*s/d;
		}
};

int main()
{
	MaTran A, B;
	cout << "Ma tran A:\n";
	cin >> A;
	cout << "\nMa tran A ban vua nhap:\n" << A;
	cout << "\nMa tran B:\n";
	cin >> B;
	cout << "\nMa tran B ban vua nhap:\n" << B;
	
	double T = 23122021 / (A.max() + B.max());
	
	cout << "T = 23122021/(maxA + maxB) = " << T;
	
	double s = sqrt(A.tbc() - B.tbc());
	
	cout << "\nS = sqrt(tbA - tbB) = " << s;

}

