#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct dt{
	int n;
	float *hs;
};

void nhap(dt *a, char name[30])
{
	FILE *fi = fopen(name, "r");
	fscanf(fi, "%d\n", &a->n);
	a->hs = (float*) calloc (((a->n)+5), sizeof(float));
	
	for (int i=0; i<=a->n; i++)
	{
		fscanf(fi, "%f", &a->hs[i]);
	}
}

void xuat(dt a, char name[30])
{
	FILE *fo = fopen(name, "a");
	fprintf(fo, "%.2f", a.hs[0]);
	for (int i=1; i<=a.n; i++)
	{
		if (a.hs[i] >= 0)
			fprintf(fo, " + %.2f*x^%d", a.hs[i], i);
		else
			fprintf(fo, " - %.2f*x^%d", (-a.hs[i]), i);	
	}
}

void daoham(dt a, dt &b, char name[30])
{
	FILE *fo = fopen(name, "a");
	b.n = a.n -1;
	b.hs = (float*) calloc (((b.n)+5), sizeof(float));
	for (int i=1; i<=a.n; i++)
	{
		b.hs[i-1] = i * a.hs[i];
	}
	fprintf(fo, "\nDa thuc dao ham la: %.2f", b.hs[0]);
	for (int i=1; i<=b.n; i++)
	{
		if (b.hs[i] >= 0)
			fprintf(fo, " + %.2f*x^%d", b.hs[i], i);
		else
			fprintf(fo, " - %.2f*x^%d", (-b.hs[i]), i);	
	}
}

void Tich(dt P, dt Q, dt &R, char name[30])
{
	FILE *fo = fopen(name, "a");
    R.n = P.n + Q.n;
    R.hs = (float*) calloc (((R.n)+5), sizeof(float));
    
    for(int i=0; i<=R.n; i++)
    {
        R.hs[i] = 0;
        for(int j=0; j<=P.n; j++)
        	if(i >= j && i-j <= Q.n) 
				R.hs[i] += P.hs[j] * Q.hs[i-j];
    }
    fprintf(fo, "\nTich 2 da thuc la: %.2f", R.hs[0]);
	for (int i=1; i<=R.n; i++)
	{
		if (R.hs[i] >= 0)
			fprintf(fo, " + %.2f*x^%d", R.hs[i], i);
		else
			fprintf(fo, " - %.2f*x^%d", (-R.hs[i]), i);	
	}
}

int main()
{
	dt a,b,c,d;
	
	nhap(&a, "input.txt");
	xuat(a, "dathuc.txt");
	
	daoham(a,c, "dathuc.txt");
	
	printf("\nNhap da thuc B(x): ");
	printf("\nNhap bac cua da thuc B(x): "); 
	scanf("%d", &b.n);
	b.hs = (float*) calloc (((b.n)+5), sizeof(float));
	
	for (int i=0; i<=b.n; i++)
	{
		printf("He so bac %d: ", i);
		scanf("%f", &b.hs[i]);
	}
	
	Tich(a, b, d, "dathuc.txt");
	
	return 0; 
	
}

