#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct nv{
	int ma;
	char ht[50];
	char td[10];
	int age;
	int time;
};

nv nhap1nv(FILE *f)
{
	nv a;
	fscanf(f, "%d\n", &a.ma);
	fscanf(f, "%[^\n]\n", &a.ht);
	fscanf(f, "%s\n", &a.td);
	fscanf(f, "%d\n", &a.age);
	fscanf(f, "%d\n", &a.time);
	
	return a;
}

void nhap(nv *&ds, int &n, float &lcb, char name[30])
{
	FILE *fi = fopen(name, "r");
	if (fi == NULL)
		printf("Loi doc tep");
	fscanf(fi, "%d", &n);
	fscanf(fi, "%f\n", &lcb);
	ds = (nv*) calloc ((n+2), sizeof(nv));
	for (int i=0; i<n; i++)
	{
		ds[i] = nhap1nv(fi);
	}
}

void xuat(nv *ds, int n)
{
	for (int i=0; i<n; i++)
	{
		printf("\n%d %10s %10s %5d %5d", ds[i].ma, ds[i].ht, ds[i].td, ds[i].age, ds[i].time);
	}
}

void nv_tangca(nv *ds, int n)
{
	int max = 0;
	for (int i=0; i<n; i++)
	{
		if (ds[i].time >= max)
			max = ds[i].time;
	}
	printf("\n\nNhung nhan vien tang ca nhieu nhat la: ");
	for (int i=0; i<n; i++)
		if (max == ds[i].time)
			printf("\n%d %10s %10s %5d %5d", ds[i].ma, ds[i].ht, ds[i].td, ds[i].age, ds[i].time);
}

int hsl(nv a)
{
	if (strcmp(a.td, "Fresher") == 0)
		return 2;
	if (strcmp(a.td, "Junior") == 0)
		return 3;
	if (strcmp(a.td, "Senior") == 0)
		return 4;
}

double luong1nv(nv a, float lcb)
{
	double T = hsl(a) * lcb + a.time*20;
	return T;	
}

void dsach(nv *ds, int n, float lcb)
{
	for (int i=0; i<n; i++)
	{
		printf("\n%d %10s %10s %5d %5d \t %.2f$", ds[i].ma, ds[i].ht, ds[i].td, ds[i].age, ds[i].time, luong1nv(ds[i], lcb));
	}
}

void find(nv *ds, int n)
{
	char x[50], t[10]; int ok=0;
	printf("\nNhap ten nhan vien can tim: ");
	fflush(stdin);
	gets(x);
	printf("\nNhap trinh do moi: ");
	gets(t);
	for (int i=0; i<n; i++)
	{
		if (strcmp(ds[i].ht, x) == 0)
		{
			printf("\n%d %10s %10s %5d %5d \t ", ds[i].ma, ds[i].ht, t, ds[i].age, ds[i].time);
			ok = 1;
		}
	}
	if (ok == 0)
		printf("\nKo co nhan vien can tim");
}

int main()
{
	nv *ds; int n;
	float lcb;
	char input[30];
	
	printf("Nhap ten tep chua input: ");
	fflush(stdin);
	gets(input);
	
	nhap(ds, n, lcb, input);
	xuat(ds,n);
	
	nv_tangca(ds, n);
	printf("\n\nDanh sach nhan vien sau khi tinh luong:\n");
	dsach(ds, n, lcb);
	
	find(ds,n);
	return 0;
	
}

