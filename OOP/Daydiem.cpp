#include <bits/stdc++.h>
using namespace std;

struct diem{
	float x,y;
};

float kc_2diem(diem A, diem B)
{
	float k = sqrt(pow(A.x-B.x, 2) + pow(A.y-B.y, 2));
	return k;
}

float kc(diem A)
{
	float t1 = sqrt(pow(A.x, 2) + pow(A.y, 2));
	return t1;
}

float tongkc(diem *&a, int &n)
{
	float t2=0;
	for (int i=0; i<n; i++)
	{
		t2 += sqrt(pow(a->x, 2) + pow(a->y, 2));
	}
	return t2;
}

void xuat(diem a)
{
	cout << "(" << a.x << "," << a.y << ")" << endl;
}
main()
{
	int n;
	diem *a;
	cout << "Nhap so diem: "; cin >> n;
	a = new diem[n+5];
	for (int i=0; i<n; i++)
	{
		cout << "Diem " << i+1 << ": ";
		cin >> a[i].x >> a[i].y;
	}
	float max = kc_2diem(a[0],a[1]);
	for (int i=0; i<n-1; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (max <= kc_2diem(a[i], a[j]))
				max = kc_2diem(a[i], a[j]);
		}
	}
	cout << "Doan dai nhat : " << setprecision(2) << fixed << max << endl;
	for (int i=0; i<n-1; i++)
		for (int j=i+1 ;j<n; j++)
			if (max == kc_2diem(a[i], a[j]))
			{
				xuat (a[i]); xuat(a[j]); cout << endl;
			}
				
	
	cout << "Tong kc den goc toa do = " << setprecision(2) << fixed << tongkc(a,n);
	
	return 0;
}
