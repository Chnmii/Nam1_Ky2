#include <bits/stdc++.h>
using namespace std;

class diem
{
	float x,y;
	public:
		void nhap(int &n, diem *&a)
		{
			cout << "Nhap so diem: ";
			cin >> n;
			a = new diem[n+2];
			for (int i=1; i<=n; i++)
			{
				cout << "Nhap tung do: ";
				cin >> a[i].y;
				cout << "Nhap hoanh do: ";
				cin >> a[i].x;
			}	
		}

		float kc(int n, diem *a)
		{
			float s=0;
			for (int i=1; i<=n; i++)
			{
				s += sqrt(pow(a[i].x-a[i+1].x, 2) + pow(a[i].y-a[i+1].y, 2));
			}
			return s;
		}
};

int main()
{
	diem *a;
	int n;
	a->nhap(n,a);
	cout << a->kc(n,a);

}

