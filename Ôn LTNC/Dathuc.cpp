#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct dt{
	int n;
	float *hs;
};

void nhap(dt &a, char name[30])
{
	FILE *fi = fopen(name,"r");
	fscanf(fi, "%d\n", &a.n);
	a.hs = (float*) calloc ((a.n+2), sizeof(float));
	for (int i=0; i<=a.n; i++)
	{
		fscanf(fi, "%f", &a.hs[i]);
	}
	
}

void xuat(dt a, char name[30])
{
	FILE *fo = fopen(name,"a");
	fprintf(fo, "%.2f", a.hs[0]);
	for (int i=1; i<=a.n; i++)
	{
		if (a.hs[i] > 0)
			fprintf(fo, " + %.2fx^%d", a.hs[i], i);
		else
			fprintf(fo, " - %.2fx^%d", a.hs[i], i);
	}
}

void daoham(dt a, dt &b)
{
	b.hs = (float*) calloc ((a.n+2), sizeof(float));
	for (int i=1; i<=a.n; i++)  // a = 6x^2 + 3x + 2 --> b = 2*6x + 1*3 + 0*2
	{
		// b.hs[1-1] = a.hs[1] * 1; --> co tu bac 0
		// b.hs[2-1] = a.hs[2] * 2;
		b.hs[i-1] = a.hs[i] * i; // dathuc daoham cua a la dathuc b: neu bac cua a = 1 thi bac cua b = 0
	}
	printf("Da thuc dao ham la: %.2f", b.hs[0]);
	for (int i=1; i<=a.n; i++)
	{
		printf(" + %.2fx^%d", b.hs[i], i);
	}
}

void ngham(dt a, dt &c)
{
	c.hs = (float*) calloc ((a.n+2), sizeof(float));
	for (int i=0; i<=a.n; i++)
	{
		c.hs[i+1] = a.hs[i] / (i+1);
	}
	printf("\nDa thuc nguyen ham la: %.2f", c.hs[1]);
	for (int i=2; i<=a.n+1; i++)
	{
		printf(" + %.2fx^%d", c.hs[i], i);
	}
}

int main()
{
	dt a,b,c;
	nhap(a,"nhap.txt");
	xuat(a, "xuat.txt");
	daoham(a,b);
	ngham(a,c);
	
	return 0;
	
}

