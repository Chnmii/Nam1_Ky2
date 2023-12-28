#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<char, int>TK;
map<char, int>Dem;
class NGUOI{
	string hoten;
	int tuoi;
	public:
		string get_hoten(){return hoten;}
		int get_tuoi(){return tuoi;}
		void nhap(){
			fflush(stdin);
			cout<<"Nhap ten: ";
			getline(cin, hoten);
			cout<<"Nhap tuoi: ";
			cin>>tuoi;
		}
		void xuat(){
			cout<<hoten<<setw(10)<<tuoi<<setw(10);
		}
};
class BENHNHAN:public NGUOI{
	char Benh;
	public:
		char get_Benh(){return Benh;}
		void nhap(){
			NGUOI::nhap();
			cout<<"Nhap benh(A or B or C): "; cin>>Benh;
		}
		void xuat(){
			NGUOI::xuat();
			cout<<Benh<<endl;
		}
};
void tinhtb(BENHNHAN *B, int n){
	for(int i=0;i<n;i++){
		TK[B[i].get_Benh()] += B[i].get_tuoi();
		Dem[B[i].get_Benh()]++;
	}
}
void sx(BENHNHAN *&p, int n){
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if( p[i].get_tuoi() > p[j].get_tuoi())
				swap(p[i],p[j]);
}
int main()
{
	BENHNHAN *B;
	int n;
	cout<<"Nhap so benh nhan: "; cin>>n;
	B = new BENHNHAN[n+5];
	for(int i=0; i<n; i++){
		cout<<"\nNhap thong tin cua benh nhan "<<i+1<<" : "<<endl;
		B[i].nhap();
	}
	tinhtb(B,n);
	cout<<"Tuoi trung binh cua cac loai benh: "<<endl;
	
	TK['A']?cout<<"A = "<<TK['A']*1.0/Dem['A']<<endl : cout<<"A = 0"<<endl;
	TK['B']?cout<<"B = "<<TK['B']*1.0/Dem['B']<<endl : cout<<"B = 0"<<endl;
	TK['C']?cout<<"C = "<<TK['C']*1.0/Dem['C']<<endl : cout<<"C = 0"<<endl;
	cout<<"\nBa benh nhan nho tuoi nhat: "<<endl;
	sx(B,n);
	for(int i=0; i<3; i++){
		B[i].xuat();
	}

}


