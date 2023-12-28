#include <bits/stdc++.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct mt
{
	float **hs;
	int m, n;
};

mt nhap()
{	mt A;
	cout << "\nnhap so hang va so cot cua ma tran : ";
	cin >> A.m >> A.n;
	A.hs= new float*[A.m];
	for(int i=0; i<A.m; i++)
	{
		A.hs[i] = new float[A.m];
	}
	for (int i=0; i<A.m; i++)
        for (int j=0; j<A.n; j++)
		{	
			cout << "Nhap phan tu a" << i+1 << j+1 << ": ";
        	cin >> A.hs[i][j];
        }
	return A;
}

int tong_2mt(mt A, mt B, mt &C)
{
	if(A.n!=B.n && A.m!=B.m)
	{
		return 0;
	}
	C.m = A.m; C.n = A.n;
	C.hs = new float*[C.m];
	for(int i=0; i<C.m; i++)
	{
		C.hs[i] = new float[C.m];
	}
	for(int i=0; i<C.m; i++)
	{
		for(int j=0; j<C.n; j++)
		{
			C.hs[i][j] = A.hs[i][j] + B.hs[i][j];
		}
	}
	return 1;
}

void in(mt A)
{
	for (int i=0; i<A.m; i++)
	{
		for (int j=0; j<A.n; j++)
		{
			cout << setprecision(2) << fixed << A.hs[i][j] << "\t";
		}
		cout << "\n";
	}
}

int main()
{
	mt A, B, C;
	cout << "Moi nhap ma tran A: ";
	A = nhap();
	cout << "Moi nhap ma tran B: ";
	B = nhap();
	cout << "Tong 2 ma tran A va B la: \n";
	int k = tong_2mt(A,B,C);
	if (k==0)
		cout << "Ko the cong tong 2 ma tran";
	else 
		in(C);
	
	return 0;
}

