#include <bits/stdc++.h>
using namespace std;

struct ps
{
	int a,b;
};

void nhap(ps &A)
{
	cout << "Nhap tu so: ";
	cin >> A.a;
	do{
		cout << "Nhap mau so khac 0: "; 
		cin >> A.b;
	} 
	while(A.b == 0); 
} 

void nhap(ps *&ds, int n)
{
	ds = new ps[n+5]; 
	for(int i=0; i<n; i++)
	{
		cout << "Nhap phan so thu " << i+1 << ": "; 
		nhap(ds[i]);
	} 
} 

void xuat(ps A)
{
	cout << A.a << "/" << A.b << endl; 
} 

void xuat(ps *ds, int n)
{
	for(int i=0; i<n; i++)
		xuat(ds[i]);
} 

void sx(ps *ds, int n)
{
	for (int i=0; i<n-1; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if ((1.0*ds[i].a/ds[i].b) > (1.0*ds[j].a/ds[j].b))
				swap(ds[i], ds[j]);
		}
	}
}

main()
{
	int n;
	ps *ds;
	cout << "Nhap so phan so: "; cin >> n;
	nhap(ds,n);
	cout << "Danh sach phan so sau khi sap xep tang dan:\n";
	sx(ds,n);
	xuat(ds,n);
	
	return 0;
}
