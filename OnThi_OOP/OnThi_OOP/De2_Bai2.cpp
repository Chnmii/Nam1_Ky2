#include<bits/stdc++.h>
#define ll long long
using namespace std;
class QLH{
	string maH, tenH, sx;
	int loaiH, sol;
	public:
		void nhap(){
			cout<<"Nhap ma hang: "; fflush(stdin);
			getline(cin,maH);
			cout<<"Nhap ten hang: "; fflush(stdin);
			getline(cin,tenH);
			cout<<"Nhap san xuat: "; fflush(stdin);
			getline(cin,sx);
			cout<<"Nhap loai hang: "; cin>>loaiH;
			cout<<"Nhap so luong: "; cin>>sol;
		} 
		void xuat(){
			cout<<maH<<setw(15)<<tenH<<setw(15)<<sx<<setw(10)<<loaiH<<setw(5)<<sol<<setw(10);
		}	
		string getten(){return tenH;}
		int getL(){return loaiH;}
		int getsol(){return sol;}
};
class DienTu:public QLH{
	int tgbh;
	public:
		void nhap(){
			QLH::nhap();
			cout<<"Nhap tg bao hanh(thang): "; cin>>tgbh;
		}
		void xuat(){
			QLH::xuat();
			cout<<tgbh<<endl;
		}
		int gettgbh(){return tgbh;}
};
int main()
{
	int n;
	DienTu a[100];
	cout<<"Nhap so luong mat hang: "; cin>>n;
	for(int i=0; i<n; i++) a[i].nhap();
	cout<<"---------------DS------------------\n";
	cout<<"MaH"<<setw(15)<<"TenH"<<setw(15)<<"Sx"<<setw(10)<<"LoaiH"<<setw(5)<<"SOL"<<setw(10)<<"TGBH"<<endl;
	for(int i=0; i<n; i++) a[i].xuat();
	
	map<int, int> Q;
	for(int i=0; i<n; i++){
		if(a[i].gettgbh() > 12) Q[a[i].getL()] += a[i].getsol();
	}
	cout<<"Thong ke cac loai mat hang co thbh > 12 thang la: \n";
	for(int i=1; i<=3; i++)
		if(Q[i]) cout<<"Mat hang "<<i<<" : "<<Q[i]<<endl;
		
	string x; int ok=0;
	cout<<"Nhap ten hang can tim: ";fflush(stdin);getline(cin,x);
	cout<<"---------------DS MAT HANG------------------\n";
	cout<<"MaH"<<setw(15)<<"TenH"<<setw(15)<<"Sx"<<setw(10)<<"LoaiH"<<setw(5)<<"SOL"<<setw(10)<<"TGBH"<<endl;
	for(int i=0; i<n; i++)
		if(a[i].getten() == x) a[i].xuat(), ok=1;
	if(!ok) cout<<"Khong co mat hang can tim!";
}


