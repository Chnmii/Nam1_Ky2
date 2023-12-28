#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Diem{
	float hoanh, tung;
	public:
		friend istream &operator>>(istream &is, Diem &p){
			is>> p.hoanh>> p.tung;
			return is;
		}
		friend ostream &operator<<(ostream &os, Diem p){
			os<<"("<<p.hoanh<<","<< p.tung<<")";
			return os;
		}
		float tinh(){
			return sqrt(hoanh*hoanh + tung*tung);
		}
};

int main()
{
	int n;
	Diem *a;
	cout<<"Nhap n = "; cin>>n;
	a=new Diem[n+5];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<"------DS DIEM----------\n";
	for(int i=0; i<n; i++)
		cout<<a[i]<<"\t";
	float sum=0, max = a[0].tinh();
	for(int i=0; i<n; i++){
		sum+=a[i].tinh();
		max = max>a[i].tinh() ? max : a[i].tinh();
	}
	cout<<"\nTong kc = "<<sum;
	cout<<"\nMax = "<<max;
}


