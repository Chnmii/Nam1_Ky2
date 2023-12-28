#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Toado{
	float hoanh, tung;
	public:
		void nhap(){
			cout<<"Nhap hoanh do va tung do: ";
			cin>>hoanh>>tung;
		}
		void xuat(){
			cout<<"("<<hoanh<<","<<tung<<")";
		}
		float tinh(){
			return sqrt(hoanh*hoanh + tung*tung);
		}
};
class DiemMau:public Toado{
	int mau;
	public:
		void nhap(){
			Toado::nhap();
			cout<<"Nhap mau: ";
			cin>>mau;
		}
		void xuat(){
			Toado::xuat();
			cout<<" : mau "<<mau<<endl;
		}
	int getmau(){return mau;}
};
int main()
{
	DiemMau *a;
	int n;
	cout<<"Nhap n = "; cin>>n;
	a = new DiemMau[n+5];
	for(int i=0; i<n;i++) a[i].nhap();
	cout<<"-----------DS DIEM-------------\n";
	for(int i=0; i<n;i++) a[i].xuat();
	
	map<int, int>Q;
	float maxx = a[0].tinh();
	for(int i=0; i<n; i++){
		Q[a[i].getmau()]++;
		maxx = maxx> a[i].tinh() ?maxx : a[i].tinh();
	}
	Q[1]? cout<<"\nMau 1 co so luong la: "<<Q[1] : cout<<"\nKhong co mau 1!";
	Q[2]?cout<<"\nMau 2 co so luong la: "<<Q[2] : cout<<"\nKhong co mau 2!";
	Q[3]?cout<<"\nMau 3 co so luong la: "<<Q[3] : cout<<"\nKhong co mau 3!";
	
	cout<<"\n\nDiem xa nhat la: "<<maxx;
}


