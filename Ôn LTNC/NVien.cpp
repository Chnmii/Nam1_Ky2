#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct nv{
	char mnv[30], que[30];
	char ht[30];
	int tuoi, ds;
	float luong, tong;
};

void docfile(int *n, nv **ds, char name[30]) 
{
	FILE *fi = fopen(name,"rt");
	if (fi == NULL)
		printf("Loi doc tep");
		
	fscanf(fi, "%d\n", n); 
	(*ds) = (nv*) malloc (sizeof(nv) * ((*n)+5));
	for (int i=0; i<(*n); i++) 
	{
		fscanf(fi, "%[^\n]\n" , &(*ds)[i].mnv);
		fscanf(fi, "%[^\n]\n", &(*ds)[i].ht);
		fscanf(fi, "%d\n", &(*ds)[i].tuoi);
		fscanf(fi, "%[^\n]\n", &(*ds)[i].que);
		fscanf(fi, "%d\n", &(*ds)[i].ds);
		fscanf(fi, "%f\n", &(*ds)[i].luong);
	}
}

float tong(nv a, float x)
{
	float t = a.luong + a.ds * x/100;
	return t;
}

void tongluong(int n, nv *ds, float x, char name [30])
{
	FILE *fo = fopen(name, "a");
	for(int i=0; i<n; i++)
	{
		ds[i].tong = tong(ds[i], x);
		fprintf(fo,"\n%s  %s  %d  %s  %d  %.2f$  %.2f$", ds[i].mnv, ds[i].ht, ds[i].tuoi, ds[i].que, ds[i].ds, ds[i].luong, ds[i].tong);
	}
}

void find(int n, nv *ds, float x)
{
	int d=0;
	printf("\nNhan vien que Ha Noi va co doanh so tren 10:");
	for (int i=0; i<n; i++)
	{
		if (strcmp(ds[i].que, "Ha Noi") == 0 && ds[i].ds > 10)
		{
			d++;
			ds[i].tong = tong(ds[i], x);
			printf("\n%s  %s  %d  %s  %d  %.2f$  %.2f$", ds[i].mnv, ds[i].ht, ds[i].tuoi, ds[i].que, ds[i].ds, ds[i].luong, ds[i].tong );
		}
	}
	if (d == 0)
		printf("\nKo co");
}

void ds_max(int n, nv *ds, float x)
{
	int max = 0;
	printf("\nCac nhan vien co doanh so cao nhat: ");
	for (int i=0; i<n; i++)
	{
		if (max <= ds[i].ds)
			max = ds[i].ds;
	}	
	for (int i=0; i<n; i++)
	{
		if (ds[i].ds == max)
		{
			ds[i].tong = tong(ds[i], x) + 200;
			printf("\n%s  %s  %d  %s  %d  %.2f$  %.2f$", ds[i].mnv, ds[i].ht, ds[i].tuoi, ds[i].que, ds[i].ds, ds[i].luong, ds[i].tong );
		}
	}
}

int main()
{
	nv *ds;
	int n; float x;
	
	docfile(&n, &ds, "input.txt");
	printf("Nhap phan tram hoa hong: ");
	scanf("%f", &x);
	tongluong(n, ds, x, "output.txt");
	find(n, ds, x);
	ds_max(n, ds, x);
	
	return 0;
	
}

