#include <bits/stdc++.h>
using namespace std;

typedef struct mt
{
	int **a;
	int n;
};

void nhap(mt &A)
{
    printf("Moi nhap cap cua ma tran: ");
   	scanf("%d", &A.n);
	
	A.a =(int **)malloc(A.n*sizeof(int *));
	for(int i=0; i<A.n; i++)
	{
		A.a[i]=(int*)malloc(A.n*sizeof(int));
	}
	for(int i=0; i<A.n; i++)
	{
		for(int j=0; j<A.n; j++)
		{
			printf("a[%d][%d]: ", i+1, j+1);
			scanf("%d", &A.a[i][j]);
		}
	}
}

int mtp(mt A, mt B, mt &G)
{
	if(A.n!=B.n)
	{
		return 0;
	}
	G.n=A.n;
	G.a =(int **)malloc(G.n*sizeof(int *));
	for(int i=0; i<A.n; i++)
	{
		G.a[i]=(int*)malloc(G.n*sizeof(int));
	}
	for(int i=0; i<G.n; i++)
	{
		for(int j=0; j<G.n; j++)
		{
			G.a[i][j]=0;
			for(int k=0; k<G.n; k++)
			{
				G.a[i][j]+=A.a[i][k]*B.a[k][j];
			}
		}
	}
	return 1;
}

int main()
{

}

