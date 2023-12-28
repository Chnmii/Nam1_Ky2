#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct sv{
	char MSV[30];
	char TEN[30];
	int TIN;
	float HPDN, HPPN;
};

void docfile(int *n, float *m, sv **ds, char name[30]) 
{
	FILE *fi = fopen(name,"rt");
	if (fi == NULL)
		printf("Loi doc tep");
		
	fscanf(fi, "%d%f\n", n, m); 
	(*ds) = (sv*) malloc (sizeof(sv) * ((*n)+5));
	for (int i=0; i<(*n); i++) 
	{
		fscanf(fi, "%[^\n]\n" , &(*ds)[i].MSV);
		fscanf(fi, "%[^\n]\n", &(*ds)[i].TEN);
		fscanf(fi, "%d\n", &(*ds)[i].TIN);
		fscanf(fi, "%f\n", &(*ds)[i].HPDN);
	}
}

float hphi(sv a, float m)
{
	float t = a.TIN * m;
}

void HocPhi(int n, float m, sv *ds)
{
	printf("Danh sach sinh vien:");
	for (int i=0; i<n; i++)
	{
		ds[i].HPPN = hphi(ds[i], m);
		printf("\n%s %10s %5d %10.2f$ %10.2f$", ds[i].MSV, ds[i].TEN, ds[i].TIN, ds[i].HPDN, ds[i].HPPN);
	}
}

void tin_max(int n, sv *ds)
{
	int max = 0;
	for (int i=0; i<n; i++)
	{
		if (ds[i].TIN >= max)
			max = ds[i].TIN;
	}
	printf("\nCac sinh sinh vien dang ky nhieu tin chi nhat:");
	for (int i=0; i<n; i++)
	{
		if (max == ds[i].TIN)
			printf("\n%s  %10s %5d %10.2f$ %10.2f$", ds[i].MSV, ds[i].TEN, ds[i].TIN, ds[i].HPDN, ds[i].HPPN);
	}
}

void CamThi(int n, float m, sv *ds)
{
	int d=0;
	printf("\nCac sinh vien con no hoc phi:");
	for (int i=0; i<n; i++)
	{
		if (ds[i].HPDN < hphi(ds[i],m))
		{
			printf("\n%s  %10s %5d %10.2f$ %10.2f$", ds[i].MSV, ds[i].TEN, ds[i].TIN, ds[i].HPDN, ds[i].HPPN);
			d++;
		}
	}
	if (d == 0)
		printf("\nKo co");
}

int main()
{
	int n; float m;
	sv *ds;
	char ip[30], op[30];
	
	printf("Nhap ten tep chua input: ");
	fflush(stdin);
	gets(ip);
	
	docfile(&n, &m, &ds, ip);
	HocPhi(n, m, ds);
	tin_max(n, ds);
	CamThi(n, m, ds);
	
	return 0;
	
}

