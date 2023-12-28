#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct ThiSinh
{
	char ht[30],truong[50];
	float sd;
};

typedef struct DSTS
{
	int n;
	ThiSinh *ds;
};

typedef struct truong
{
	char x[100];
};

ThiSinh nhap()
{	ThiSinh ts;
    printf("\nHo va ten: ");
    fflush(stdin);
	gets(ts.ht);

    printf("Truong: ");
    gets(ts.truong);

    printf("Diem: ");
    scanf("%f", &ts.sd);
    
    return ts;
}

DSTS nhapds()
{	DSTS x;
	printf("\nNhap so thi sinh: ");
	scanf("%d", &x.n);
	x.ds= (ThiSinh*)malloc(sizeof(ThiSinh)*(x.n));
	for (int i=0; i<x.n; i++)
	{
		printf("Nhap thi sinh thu %d: ", i+1);
		x.ds[i]=nhap();
	}
	return x;
}

void in1ts(ThiSinh a)
{
	printf("\n%s\t%s\t%.2f", a.ht, a.truong, a.sd);
}

void inds(DSTS x)
{	
	for (int i=0; i<x.n; i++)
		in1ts(x.ds[i]);
}

void nhaptrg(truong *&b, int &m)
{
	printf("Nhap so truong: ");
	scanf("%d", &m);
	b = (truong*)malloc(sizeof(truong)*(m+1));
	for(int i=0; i<m; i++){	
		printf("Nhap ten truong thu %d:  ", i+1);
		fflush(stdin);
		gets(b[i].x);
	}
}

float diem_1trg(DSTS x)
{	
	char truong[50];
	float T=0;
	printf("\nNhap truong can tim:\n");
	fflush(stdin);
	gets(truong);
	
	for (int i=0; i<x.n; i++){
		if (strcmp(x.ds[i].truong, truong)==0){
			T+= x.ds[i].sd;
		}
	}
	return T;
} 

void sap_xep(DSTS x)
{	
	for (int i=0; i<x.n-1; i++){
		for (int j=i+1; j<x.n; j++)
		{
			if (x.ds[i].sd < x.ds[j].sd)
			{
				ThiSinh t=x.ds[i];
				x.ds[i]=x.ds[j];
				x.ds[j]=t;
			}
		}
	}
}

int main()
{	
	DSTS A;
	int m;
	truong *b;
	nhaptrg(b,m);
	A = nhapds();
	sap_xep(A);
	printf("\nDanh sach thi sinh theo thu tu diem giam dan:\n");
	inds(A);
	
	getch();
	float c[100];
	for(int i=0;i<m;i++){
		c[i]=diem_1trg(A);
	}
	float max=c[0];
	int v; 
	for(int i=0;i<m;i++){
		if(c[i]>=max)
		 	v=i;
		printf("\nTong diem cua truong %s= %.2f", b[i].x, c[i]); 
	}
	printf("\nTruong co tong diem cao nhat la: %s", b[v].x);
	
	getch();
	return 0;
}
