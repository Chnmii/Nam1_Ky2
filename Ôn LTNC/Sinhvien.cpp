#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct sv{
	char hodem[30];
	char ten[20];
	char que;
	float toan, ly, hoa;
};

void docfile(int &n, sv *&a, char name[30])
{
	FILE *fi = fopen(name, "r");
	fscanf(fi, "%d\n", &n);
	if (fi == NULL)
		printf("Loi doc tep");
	a = (sv*) calloc (n+5, sizeof(sv));
	
	for (int i=0; i<n; i++)
	{
		fscanf(fi, "%[^\n]\n", &a[i].hodem);
		fscanf(fi, "%[^\n]\n", &a[i].ten);
		fscanf(fi, "%c\n", &a[i].que);
		fscanf(fi, "%f\n%f\n%f\n", &a[i].toan, &a[i].ly, &a[i].hoa);
	}
}

void xuat(int n, sv *a, char name[30])
{
	FILE *fo = fopen(name, "a");
	if (fo == NULL)
		printf("Loi doc tep");
	printf("\nDanh sach cac sinh vien vua nhap la:");
	fprintf(fo, "\nDanh sach cac sinh vien vua nhap la:");
	
	for (int i=0; i<n; i++)
	{
		printf("\n%-5s %-10s %-5c %-5.2f %-5.2f %-5.2f", a[i].hodem, a[i].ten, a[i].que, a[i].toan, a[i].ly, a[i].hoa);
		fprintf(fo, "\n%-5s %-10s %-5c %-5.2f %-5.2f %-5.2f", a[i].hodem, a[i].ten, a[i].que, a[i].toan, a[i].ly, a[i].hoa);
	}
}

void tong(int n, sv *a)
{
	float T[n] = {};
	for (int i=0; i<n; i++)
	{
		T[i] += a[i].toan + a[i].ly + a[i].hoa;
		printf("\nTong diem cua sv thu %d: %.2f", i+1, T[i]);
	}
	
	float max = T[0];
	for (int i=0; i<n; i++)
	{
		if (T[i] > max)
			max = T[i];
	}
	for (int i=0; i<n; i++)
		if (max == T[i])
			printf("\nSV thu %d co tong diem cao nhat\n", i+1);
}

void sapxep(sv *a, int n)
{
	for(int i=0;i<n;i++){
		for(int j=i+1; j<n;j++)
		{
			if(strcmp(a[i].ten, a[j].ten)>0) // hong > hang
			{ 
				sv c = a[i];
				a[i] = a[j];
				a[j]=c;
			}
		}
	}
	printf("\nSau khi sap xep ten theo thu tu a-z");
	xuat(n,a,"outsv.txt");
}

int dem[5] = {}; 
void demsv(sv *a, int n)
{
 	for(int i = 0; i<n; i++)
	{
		if (a[i].que == 'A')  dem[0]++;
		else if (a[i].que == 'B') dem[1]++;
		else if (a[i].que == 'C') dem[2]++;
		else dem[3]++;
	}
	
	for(int i=0;i<4;i++)
	{
		printf("\nSo sv cua vung que %c la: %d\n", i+'A', dem[i]);	
	}
}

void sv_max2(int n, sv *a)
{
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<4; j++)
		{
			if (dem[i] < dem[j])
			{
				int c = dem[i];
				dem[i] = dem[j];
				dem[j] = c;
			}	
		}
	}
	for (int i=1; i<2; i++)
		printf("\nVung que %c co so sv nhieu thu 2", i+'A');
}

int main()
{
	int n;
	sv *a;
	char input[30];
	
	printf("Nhap ten tep chua input: ");
	fflush(stdin);
	gets(input);
	
	docfile(n, a, input);
	xuat(n, a, "outsv.txt");
	
	tong(n,a);
	sapxep(a,n);
	demsv(a,n);
	sv_max2(n,a);
	
	return 0;
	
}

