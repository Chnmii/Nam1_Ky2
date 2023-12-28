#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct mt{
	int n;
	int **hs;
};

void docfile(mt *a, char name[30])
{
	FILE *fi = fopen(name, "r");
	if (fi == NULL)
		printf("Loi doc tep");
		
	fscanf(fi, "%d\n", &a->n);
	a->hs = (int**) calloc ((a->n + 2), sizeof(int*));
	
	for (int i=1; i<=a->n; i++)
	{
		a->hs[i] = (int*) calloc ((a->n + 2), sizeof(int));
		for (int j=1; j<=a->n; j++)
		{
			fscanf(fi, "%d", &a->hs[i][j]);
		}
	}
}

void xuat(mt a)
{
	for (int i=1; i<=a.n; i++)
	{
		for (int j=1; j<=a.n; j++)
		{
			printf("%5d", a.hs[i][j]);
		}
		printf("\n");
	}
}

void cvi(mt a, mt &b)
{
	b.hs = (int**) calloc ()
}
void tbc(mt a, char name[30])
{
	FILE *fo = fopen(name, "a");
	int T=0, d=0;
	for (int i=1; i<=a.n; i++)
	{
		for (int j=1; j<=a.n; j++)
		{
			if ((i+j) > (a.n+1))
			{
				T += a.hs[i][j];
				d++;
			}
		}
	}
	printf("\nTBC cac phan tu nam duoi dg cheo phu la: %.2f", 1.0*T/d);
	fprintf(fo, "\nTBC cac phan tu nam duoi dg cheo phu la: %.2f", 1.0*T/d);
}

int tong(int k)
{
	int i, t=0;
	for (i=1; i<k; ++i)
		t+=i;
	return t;
}

void mt_tgt(mt a, char name[30])
{
	FILE *fo = fopen(name, "a");
	int d=0;
	for (int i=1; i<=a.n; i++)
	{
		for (int j=1; j<=a.n; j++)
		{
			if (i>j && a.hs[i][j] == 0)
				d++;
		}
	}
	if (d == tong(a.n))
	{
		printf("\nA la ma tran tam giac tren");
		fprintf(fo, "\nA la ma tran tam giac tren");
	}
	else
	{
		printf("\nA ko la ma tran tam giac tren");
		fprintf(fo, "\nA ko la ma tran tam giac tren");
	}		
}

void mt_thua(mt a, char name[30])
{
	FILE *fo = fopen(name, "a");
	int d=0;
	for (int i=1; i<=a.n; i++)
	{
		for (int j=1; j<=a.n; j++)
		{
			if (a.hs[i][j] == 0)
				d++;
		}
	}
	if (d >= (a.n*a.n*0.6))
	{
		printf("\nA la ma tran thua");
		fprintf(fo, "\nA la ma tran thua");
	}
	else 
	{
		printf("\nA ko la ma tran thua");
		fprintf(fo, "\nA ko la ma tran thua");
	}
}

int main()
{
	mt a;
	char ip[30], op[30];
	printf("Nhap ten tep chua input: ");
	fflush(stdin);
	gets(ip);
	
	docfile(&a, ip);
	xuat(a);
	
	printf("Nhap ten tep chua output: ");
	fflush(stdin);
	gets(op);
	tbc(a, op);
	
	mt_tgt(a,op);
	mt_thua(a, op);
	
	return 0;
	
}

