#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct bnhan{
	char hten[50];
	int benh;
	int tuoi;
};

bnhan nhap1bn(FILE *fi)
{
	bnhan x; char ten[50];
	fgets(ten,50,fi);
	ten[strlen(ten)-1]='\0';
	strcpy(x.hten, ten);
	//fscanf(fi, "%s", &x.hten);
	fscanf(fi, "%d\n%d\n", &x.benh, &x.tuoi);
	
	return x;
}

void nhapds(char tentep[30], int *n, bnhan *&ds)
{
	FILE *f; int i;
	f=fopen(tentep,"rt");
	fscanf(f,"%d\n", n);
	ds = (bnhan*) malloc (sizeof(bnhan)*((*n)+5));
	for (i=0; i<*n; i++) 
		ds[i] = nhap1bn(f);
}

void xuatds(int n, bnhan *ds)
{
	for (int i=0; i<n; i++)
	{
		printf("%s\t%d\t%d\n", ds[i].hten, ds[i].benh, ds[i].tuoi);
	}
}

void inratep(int n, bnhan *ds)
{
	FILE *f1 = fopen("BenhA.txt","a");
	FILE *f2 = fopen("BenhB.txt","a");
	FILE *f3 = fopen("BenhC.txt","a");
	for (int i=0; i<n; i++)
	{
		if (ds[i].benh == 1)
		{
			fprintf(f1, "%s\t%d\t%d\n", ds[i].hten, ds[i].benh, ds[i].tuoi);
		}
		if (ds[i].benh == 2)
		{
			fprintf(f2, "%s\t%d\t%d\n", ds[i].hten, ds[i].benh, ds[i].tuoi);
		}
		if (ds[i].benh == 3)
		{
			fprintf(f3, "%s\t%d\t%d\n", ds[i].hten, ds[i].benh, ds[i].tuoi);
		}
	}
}

int main()
{
	bnhan *ds;
	int n;
	nhapds("BenhNhan.txt", &n, ds);
	xuatds(n,ds);
	inratep(n,ds);
	
	return 0; 
	
}

