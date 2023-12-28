#include<bits/stdc++.h>
#define ll long long
using namespace std;
class DaThuc{
	int n;
	float *dt;
	public:
		void nhap(){
			cout<<"Nhap bac cua da thuc: ";
			cin>>n;
			dt = new float[n+4];
			for(int i=0;i<=n;i++){
				cout<<"Nhap he so bdtc "<<i<<" : ";
				cin>>dt[i];
			}
		}
		void xuat(){
			cout<<"Da thuc : "<<dt[0]<<" + ";
			for(int i=1; i<n;i++)cout<<dt[i]<<"x^"<<i<<" + ";
			cout<<dt[n]<<"x^"<<n<<endl;
		}
		int getn(){return n;}
		int getpt(int i){return dt[i];}
};
float tinh(DaThuc a, float x){
	float sum=0;
	for(int i=0; i<=a.getn(); i++)
		sum+=a.getpt(i)*pow(x,i);
	return sum;
}
int main()
{
	DaThuc a;
	float x;
	a.nhap();
	a.xuat();
	cout<<"Nhap x= "; cin>>x;
	cout<<"Tong day = "<<tinh(a,x);
}


