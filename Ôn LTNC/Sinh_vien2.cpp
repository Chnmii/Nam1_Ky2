#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct SV{
	int MA;
	char HT[50];
	char TRUONG;
	float TOAN, VAN, ANH;
};

SV nhap1sv(FILE *f)
{
	SV a;
	fscanf(f, "%d\n", &a.MA);
	fscanf(f, "%[^\n]\n", &a.HT);
	fscanf(f, "%c\n", &a.TRUONG);
	fscanf(f, "%f\n", &a.TOAN);
	fscanf(f, "%f\n", &a.VAN);
	fscanf(f, "%f\n", &a.ANH);
	
	return a;
}

void nhap(SV *&ds, int &n, char name[30])
{
	FILE *fi = fopen(name, "r");
	if (fi == NULL)
		printf("Loi doc tep");
		
	fscanf(fi, "%d\n", &n);
	ds = (SV*) calloc ((n+2), sizeof(SV));
	for (int i=0; i<n; i++)
	{
		ds[i] = nhap1sv(fi);
	}
}

void xuat(SV *ds, int n)
{
	printf("Danh sach thi sinh:");
	for (int i=0; i<n; i++)
		printf("\n%d  %s  %c  %.2f  %.2f  %.2f", ds[i].MA, ds[i].HT, ds[i].TRUONG, ds[i].TOAN, ds[i].VAN, ds[i].ANH); 
}

float tong(SV a)
{
	float T = a.TOAN + a.VAN + a.ANH;
	return T;
}

void thu_khoa(SV *ds, int n)
{
	float max = -1, m1, m2, m3; 
	int d[3]={};
	for (int i=0; i<n; i++)
	{
		if (tong(ds[i]) >= max && ds[i].TRUONG == 'A')
		{
			m1 = tong(ds[i]);
		}
		if (tong(ds[i]) >= max && ds[i].TRUONG == 'B')
		{
			m2 = tong(ds[i]);
		}
		if (tong(ds[i]) >= max && ds[i].TRUONG == 'C')
		{
			m3 = tong(ds[i]);
		}
	}
	for (int i=0; i<n; i++)
	{
		if (m1 == tong(ds[i]))
			d[0]++;
		if (m2 == tong(ds[i]))
			d[1]++;
		if (m3 == tong(ds[i]))
			d[2]++;	
	}
	if (d[0] == d[1] && d[1] == d[2])
		printf("\nCac trg deu co %d thu khoa", d[0]);
	else
	{
		int M = d[0];
		for (int i=0; i<3; i++)
		{
			if (d[i] >= M)
				M = d[i];
		}
		printf("\nCac trg co nhieu thu khoa nhat la: ");
		for (int i=0; i<3; i++)
			if (M == d[i])
				printf("\nTruong %c co %d thu khoa", i+'A', d[i]);
	}	
}

void diemtb_max(SV *ds, int n)
{
	float S[3]={}, Tb[3]; int d[3]={};
	for (int i=0; i<n; i++)
	{
		if (ds[i].TRUONG == 'A')
		{
			S[0] += 1.0*tong(ds[i])/3;
			d[0]++;
		}
		if (ds[i].TRUONG == 'B')
		{
			S[1] += 1.0*tong(ds[i])/3;
			d[1]++;
		}
		if (ds[i].TRUONG == 'C')
		{
			S[2] += 1.0*tong(ds[i])/3;
			d[2]++;
		}
	}
	for (int i=0; i<3; i++)
	{
		Tb[i] = S[i]/d[i];
	}
	if (Tb[0] == Tb[1] && Tb[1] == Tb[2])
		printf("\nCac trg deu co diem tb bang nhau");
	else
	{
		float M = Tb[0];
		for (int i=0; i<3; i++)
		{
			if (Tb[i] >= M)
				M = Tb[i];
		}
		printf("\nCac trg co diem tb cao nhat la: ");
		for (int i=0; i<3; i++)
			if (M == Tb[i])
				printf("\nTruong %c", i+'A');
	}	
}

void DoDH(SV *ds, int n)
{
	float a, tb[n];
	printf("\n\nNhap diem san: ");
	scanf("%f", &a);
	printf("\nNhung thi sinh do dai hoc la:");
	for (int i=0; i<n; i++)
	{
		tb[i] = 1.0*tong(ds[i])/3;
		if (tb[i] >= a && ds[i].ANH >= 1 && ds[i].TOAN >= 1 && ds[i].VAN >= 1)
			printf("\n%d  %s  %c  %.2f  %.2f  %.2f", ds[i].MA, ds[i].HT, ds[i].TRUONG, ds[i].TOAN, ds[i].VAN, ds[i].ANH); 
	}
}

int main()
{
	SV *ds; int n;
	char ip[30], op[30];
	
	printf("Nhap ten tep chua input: ");
	fflush(stdin);
	gets(ip);
	
	nhap(ds, n, ip);
	xuat(ds,n);
	
	thu_khoa(ds,n);
	diemtb_max(ds,n);
	DoDH(ds,n);
	
	return 0;
	
}

