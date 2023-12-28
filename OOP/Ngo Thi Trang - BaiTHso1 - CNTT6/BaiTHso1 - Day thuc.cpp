#include <bits/stdc++.h>
using namespace std;

class DayThuc
{
	int n;
	float *x;
	public:
		friend istream& operator>> (istream &in, DayThuc &a)
		{
			cout << "Nhap so phan tu: "; in >> a.n;
			a.x = new float[a.n+2];
			for (int i=0; i<a.n; i++)
				in >> a.x[i];
			return in;
		}
		friend ostream& operator <<(ostream &out,const DayThuc &a)
		{
			cout << "Day thuc vua nhap: ";
			for (int i=0; i<a.n; i++)
				cout << a.x[i] << "\t";
			return out;
		}
		float TongDay()
		{
			float s=0;
			for (int i=0; i<n; i++)
				s += x[i];
			return s;
		}
};

int main()
{
	DayThuc A;
	cin >> A;
	cout << A;
	cout << "Tong day thuc = "; A.TongDay();
}

