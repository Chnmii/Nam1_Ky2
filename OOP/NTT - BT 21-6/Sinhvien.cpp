#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct sv{
	int tuoi;
	float diem;
};

sv nhap1sv(FILE *fi)
{
	sv x;
	fscanf(fi, "%d%f\n", &x.tuoi, &x.diem);
	
	return x;
}

void nhapds(char tentep[30], int *n, sv *&ds)
{
	FILE *f; int i;
	f=fopen(tentep,"rt");
	fscanf(f,"%d\n", n);
	ds = (sv*) malloc (sizeof(sv)*((*n)+5));
	for (i=0; i<*n; i++) 
		ds[i] = nhap1sv(f);
}

void xuatds(int n, sv *ds)
{
	for (int i=0; i<n; i++)
	{
		printf("%d\t%.2f\n", ds[i].tuoi, ds[i].diem);
	}
}

void diemcao(int n, sv *ds)
{
	for (int i=0; i<n-1; i++)
	{
		for (int j=i+1; j<n; j++){
			if (ds[i].diem < ds[j].diem)
			{
				sv t = ds[i];
				ds[i] = ds[j];
				ds[j] = t;
			}
		}
	}
	printf("5 sinh vien co diem ca nhat la:");
	for (int i=0; i<5; i++)
	{
		printf("\n%d\t%.2f", ds[i].tuoi, ds[i].diem);
	}
}

void diemtb(int n, sv *ds, int age)
{
	int d=0; float S=0;
	for (int i=0; i<n; i++)
	{
		if (ds[i].tuoi == age)
		{
			d++;
			S += ds[i].diem;
		}
	}
	printf("\nDiem tb cua cac sinh vien co diem %d la: %.2f", age, 1.0*S/d);
}

int main()
{
	sv *ds;
	int n,t;
	nhapds("Sinhvien.txt", &n, ds);
	xuatds(n,ds);
	diemcao(n,ds);
	printf("\nNhap so tuoi can tim: ");
	scanf("%d", &t);
	diemtb(n,ds,t);
	
	return 0; 
	
}

