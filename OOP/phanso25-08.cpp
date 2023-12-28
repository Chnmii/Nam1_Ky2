
#include<iostream>
using namespace std;
struct PHANSO
{
	int TS;
	int MS;
};
void NhapPS(PHANSO &x)
{
	cout<<"Nhap Tu so: ";
    cin>>x.TS;
    do{
    	cout<<"Nhap Mau so khac 0: "; 
		cin>>x.MS;
	}
	while(x.MS==0);
	//	cout<<"Nhap sai, yeu cau nhap lai mau so: ";
}
istream& operator>>(istream &Cin,PHANSO &x)
{
	cout<<"Nhap Tu so: ";
    Cin>>x.TS;
    do{
    	cout<<"Nhap Mau so khac 0: "; 
		Cin>>x.MS;
	}
	while(x.MS==0);
	return Cin;
	//	cout<<"Nhap sai, yeu cau nhap lai mau so: ";
}
/*void NhapPS(PHANSO *x)
{
	cout<<"Nhap Tu so: ";
    cin>>x->TS;
    do{
    	cout<<"Nhap Mau so khac 0: "; 
		cin>>x->MS;
	}
	while(x->MS==0);
	//	cout<<"Nhap sai, yeu cau nhap lai mau so: ";
}*/

ostream& operator<<(ostream &Cout,const PHANSO& x)
{
	Cout<<x.TS<<"/"<<x.MS;
	return Cout;
}

PHANSO operator+(const PHANSO &x1,const PHANSO &x2)
{
	int Tu, Mau;PHANSO x;
	Tu = x1.TS*x2.MS + x1.MS*x2.TS;
	Mau = x1.MS*x2.MS;
	x.TS =Tu; x.MS =Mau;
	return x;
}
PHANSO TongPS(const PHANSO &x1,const PHANSO &x2)
{
	int Tu, Mau;PHANSO x;
	Tu = x1.TS*x2.MS + x1.MS*x2.TS;
	Mau = x1.MS*x2.MS;
	x.TS =Tu; x.MS =Mau;
	return x;
}
PHANSO operator*(const PHANSO &x1,const  PHANSO& x2)
{
	int Tu, Mau;PHANSO x;
	Tu = x1.TS * x2.TS;
	Mau = x1.MS * x2.MS;
	x.TS =Tu; x.MS =Mau;
	return x;
}


int main() 
{ 
	PHANSO ps1, ps2 , ps3,ps;

	cout<<"Nhap phan so:\n ";
cin>>ps1;
//	NhapPS(ps1);
//	NhapPS(&ps1);
	//NhapPS(ps2); 
	cin>>ps2>>ps3;
	//NhapPS(ps3);
	cout<<"Phan so 1 la: "<<ps1;// XuatPS(ps1);//cout<<ps1;
	cout<<"\nPhan so 2 la: "<<ps2;// XuatPS(ps2);
//cout<<"\nPhan so 3 la: "; XuatPS(ps3);
	//ps=Tich(TongPS(ps1, ps2),ps3);
	ps=(ps1+ps2)*ps3;
	cout<<"\nTong 2 phan so la: "<<ps1+ps2;//XuatPS(TongPS(ps1,ps2));

	cout<<"\nTich 2 phan so la: "<<ps1*ps2;//XuatPS(TichPS(ps1, ps2));
	cout<<"\n(p1+p2)*p3="<<ps;// XuatPS(ps);
	
	cout<<endl;
} 
