#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Nguoi{
	string hoten;
	int tuoi;
	public:
		void nhap();
		void xuat();
};
void Nguoi::nhap(){
	cout<<"Nhap ho va ten: ";fflush(stdin);getline(cin,hoten);
	cout<<"Nhap tuoi: "; cin>>tuoi;
}
void Nguoi::xuat(){
	cout<<hoten<<setw(15)<<tuoi<<setw(10);
}
class QLNV:public Nguoi{
	int snct, luong;
	public:
		void nhap();
		void xuat();
};
void QLNV::nhap(){
	Nguoi::nhap();
	cout<<"Nhap so nam cong tac: "; cin>>snct;
	cout<<"Nhap luong: "; cin>>luong;
}
void QLNV::xuat(){
	Nguoi::xuat();
	cout<<snct<<setw(10)<<luong<<endl;
}
class DSNV{
	int n;
	QLNV *a;
	public:
		void nhap();
		void xuat();
		void tinhluongtb();
		void find();
};
void DSNV::nhap(){
	cout<<"Nhap so nhan vien: "; cin>>n;
	a = new QLNV[n+5];
	for(int i=0; i<n;i++) a[i].nhap();
}
void DSNV::xuat(){
	for(int i=0; i<n; i++) a[i].xuat();
}
int main()
{
	DSNV p;
	p.nhap();
	cout<<"-----------------DANH SACH NHAN VIEN----------------\n";
	cout<<"He ten"<<setw(15)<<"Tuoi"<<setw(10)<<"SNCT"<<setw(10)<<"Luong"<<endl;
	p.xuat();
	
}


