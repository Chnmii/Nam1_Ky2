#include <stdio.h>
#include <math.h>
#include <conio.h>

void nhapmt(int a[100][100], int *n)
{
	printf("Nhap cap cua ma tran: ");
	scanf("%d", n);
	for (int i=1; i<=*n; i++)
	{
		for (int j=1; j<=*n; j++)
		{
			printf("Nhap phan tu a[%d][%d]: ", i,j);
			scanf("%d", &a[i][j]);
		}
	}
}

void inmt(int a[100][100], int n)
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

int tongpt(int a[100][100], int n)
{
	int T=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			T+= a[i][j];
		}
	}
	return T;
}

int Max(int a[100][100], int n)
{
	int Max=a[1][1];
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (Max < a[i][j])
				Max= a[i][j];
		}
	}
	return Max;
}

void tong_2mt(int a[100][100], int n, int b[100][100], int m)
{
	if (n!=m)
		printf("\nKhong the tinh duoc");
	else 
	{
		int c[100][100];
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
			{
				c[i][j]= a[i][j]+b[i][j];
			}
		}
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++){
				printf("%5d", c[i][j]);
			}
			printf("\n");
		}
	}
}

void tich_2mt(int a[100][100], int n, int b[100][100], int m, int d[100][100], int h)
{
	if (n!=m)
		printf("\nKhong the tinh duoc tich");
	else
	{	if (n==m)
		{
			h=n;
		}
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
			{
				d[i][j]=0;
				for (int k=1; k<=n; k++)
				{
					d[i][j]+= a[i][k]*b[k][j];
				}
			}
		}
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++){
				printf("%5d", d[i][j]);
			}
			printf("\n");
		}
	}
}

int tim_max(int a, int b, int c)
{
	int max = a>b?a:b;
	return max>c?max:c;
}

int main()
{
	int n,m,p,k;
	int A[100][100], B[100][100], C[100][100], D[100][100];
	
	printf("Ma tran A:\n");
	nhapmt(A,&n);
	printf("Ma tran B:\n");
	nhapmt(B,&m);
	printf("Ma tran C:\n");
	nhapmt(C,&p);
	
	getch();
	printf("\nB*C=\n");
	tich_2mt(B,m,C,p,D,k);
	printf("\nA+B*C=");
	tong_2mt(A,n,D,k);
	
	getch();
	int a= tongpt(A,n), b= tongpt(B,m), c= tongpt(C,p);
	int max= tim_max(a,b,c);
	if(max==a)
	{
		printf("\nMa tran A co tong lon nhat\n");
	}
	if(max==b)
	{
		printf("\nMa tran B co tong lon nhat\n");
	}
	if(max== c)
	{
		printf("\nMa tran C co tong lon nhat\n");
	}
	
	getch();
	printf("MaxA-MaxB-MaxC = %d", Max(A,n)-Max(B,m)-Max(C,p));

	return 0;
}


