#include<bits/stdc++.h>
#define ll long long
using namespace std;
class DaThuc{
	int n;
	int *A;
	public:
		DaThuc(){int n=0;A=0;}
		~DaThuc(){if(n) delete []A; A=0;}
		void nhap(){
			cout<<"Nhap n: "; cin>>n;
			cout<<"Nhap cac he so: \n";
			A = new int[n+5];
			for(int i=0;i<=n;i++){
				cout<<"He so n "<<i<<" : ";
				cin>>A[i];
			}
		}
		friend ostream &operator<<(ostream &os, DaThuc p){
			os<<p.A[0]<<" + ";
			for(int i=1; i<p.n; i++){
				os<<p.A[i]<<"x^"<<i<<" + ";
			}
			os<<p.A[p.n]<<"x^"<<p.n;
			return os;
		}
		friend int tinh(DaThuc p ,int x){
			int sum=0;
			for(int i=0; i<=p.n; i++){
				sum+= p.A[i]*pow(x,i);
			}
			return sum;
		}
};
int main()
{
	int x, y;
	DaThuc d1,d2;
	cout<<"Nhap da thuc 1: \n";
	d1.nhap();
	cout<<d1;
	cout<<"\nNhap x = "; cin>>x;
	cout<<"Nhap y = "; cin>>y;
	cout<<"\nKetQua: "<<1.0/(tinh(d1,x)-tinh(d1,y));
	

}


