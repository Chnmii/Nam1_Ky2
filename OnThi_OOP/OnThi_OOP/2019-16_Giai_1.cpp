#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Diem{
	float x, y;
	public:
		float getx(){return x;}
		float gety(){return y;}
		void nhap();
		void xuat();
		
		
};
void Diem::nhap(){
	cout<<"Nhap toa do x, y: ";
	cin>>x>>y;
}
void Diem::xuat(){
	cout<<"("<<x<<","<<y<<")\t";
}
float tinh(Diem a, Diem b){
	return sqrt((a.getx()-b.getx())*(a.getx()-b.getx()) + (a.gety()-b.gety())*(a.gety()-b.gety()) );
}
int main()
{
	int n;
	cout<<"Nhap so diem: "; cin>>n;
	Diem a[n+5];
	for(int i=0;i<n;i++) a[i].nhap();
	for(int i=0;i<n;i++) a[i].xuat();
	if(n<3){
		cout<<"\nKhong co duong gap khuc!";
		return 0;
	}
	float sum = 0;
	for(int i=1; i<n-1; i++)
		sum += tinh(a[i],a[i+1]);
	sum += tinh(a[n-1],a[1]);
	cout<<"\nDo dai duong gap khuc la: "<<sum;
}


