#include<bits/stdc++.h>
#define ll long long
using namespace std;
class  PhanSo{
	int tu, mau;
	public:
		PhanSo(){tu = 0;mau = 1;}
		PhanSo(int a,int b){this->tu=a;this->mau=b;}
		void nhap();
		int ucln(){
			return __gcd(tu,mau);
		}
	friend ostream &operator<<(ostream &os, PhanSo p){
		os<<p.tu/p.ucln()<<"/"<<p.mau/p.ucln()<<endl; 
	}
	friend PhanSo operator * (PhanSo a, PhanSo b){
		int x, y;
		x = a.tu * b.mau + a.mau * b.tu;
		y = a.mau*b.mau;
		return PhanSo(x,y);
	} 
};
void PhanSo::nhap(){
	cout<<"Nhap tu so: "; cin>>tu;
	cout<<"Nhap mau so: "; cin>>mau;
}

int main()
{
	PhanSo a(2,5), b;
	b.nhap();
	cout<<"Phan so 1: "<<a<<"Phan so 2: "<<b;
	cout<<"Tich 2 phan so la: "<<(a*b); 

}


