#include<bits/stdc++.h>
#define ll long long
using namespace std;
class MatHang{
	string maHang, tenHang, nsx;
	int soluong, dongia;
	public:
		MatHang(string maHang="", string tenHang="", string nsx="", int soluong=0, int dongia=0){
			this->maHang=maHang;
			this->tenHang=tenHang;
			this->nsx=nsx;
			this->soluong=soluong;
			this->dongia=dongia;
		}
		int getDongia(){return dongia;}
		string getMahang(){return maHang;}
		string getTenhang(){return tenHang;}
		void nhap();
		void xuat();
}; 

void MatHang::nhap(){
	cout<<"Nhap ma hang: "; fflush(stdin); cin>>maHang;
	fflush(stdin);
	cout<<"Nhap ten hang: "; getline(cin,tenHang);
	cout<<"Nhap nha san xuat: "; getline(cin,nsx);
	cout<<"Nhap so luong hang: ";cin>>soluong;
	cout<<"Nhap don gia: ";cin>>dongia;
}
void MatHang::xuat(){
	cout<<"Ma hang: "; cout<<maHang<<endl;
	cout<<"Ten hang: ";cout<<tenHang<<endl;
	cout<<"Nha san xuat: ";cout<<nsx<<endl;
	cout<<"So luong hang: ";cout<<soluong<<endl;
	cout<<"Don gia: ";cout<<dongia<<endl;
}
class MayTinh:public MatHang{
	string loaicpu, hdh;
	int trongluong;
	public:
		void nhap();
		void xuat();
};
void MayTinh::nhap(){
	MatHang::nhap();
	cout<<"Nhap loai cpu: "; fflush(stdin); cin>>loaicpu;
	cout<<"Nhap he dieu hanh: "; cin>>hdh;
	cout<<"Nhap trong luong: "; cin>>trongluong;
}
void MayTinh::xuat(){
	MatHang::xuat();
	cout<<"Loai cpu: "; cout<<loaicpu<<endl;
	cout<<"He dieu hanh: "; cout<<hdh<<endl;
	cout<<"Trong luong: "; cout<<trongluong<<endl;
}
void find(MayTinh *a, int n){
	string x;
	int ok=0;
	cout<<"Nhap ma hang or ten hang can tin: "; fflush(stdin);
	getline(cin, x);
	for(int i=0; i<n; i++)
		if(a[i].getMahang() == x || a[i].getTenhang() == x){
			ok = 1;
			a[i].xuat();
			cout<<endl;
		}
	if(!ok) cout<<"Khong tin thay!";
}
int maxGia(MayTinh *a, int n){
	int max = a[0].getDongia();
	for(int i=1; i<n; i++)
		max = max > a[i].getDongia()?max : a[i].getDongia();
	return max;
}
int main()
{
	MayTinh a[100];
	int n;
	cout<<"Nhap so may tinh: ";
	cin>>n;
	for(int i=0; i<n; i++) a[i].nhap();
	cout<<"\n----------------DS MAY TINH-----------------\n";
	for(int i=0; i<n; i++) a[i].xuat();
	cout<<"\n----------------DS MAY CAN TIM-----------------\n";
	find(a,n);
	
	cout<<"\n----------------DS MAY DAT NHAT-----------------";
	int max = maxGia(a, n);
	for(int i=0; i<n; i++)
		if(a[i].getDongia() == max) a[i].xuat();
}


