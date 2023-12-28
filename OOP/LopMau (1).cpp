#include<bits/stdc++.h>
using namespace std;
template <class T> class DemoLopMau{
	int n1;
	T *pt1;
	public:
		DemoLopMau(const int &a=0)
		{
			n1=a;
			pt1=new T[n1+2];
		}
		DemoLopMau(const DemoLopMau &ob)
		{
			n1=ob.n1;
			pt1=new T[n1+2];
			for(int i=0;i<n1;i++) pt1[i]=ob.tp[1];
		}
		void operator=(const DemoLopMau &ob)
		{
			n1=ob.n1;
			pt1=new T[n1+2];
			for(int i=0;i<n1;i++) pt1[i]=ob.tp[1];
		}
		~DemoLopMau(){
			delete []pt1;
		}
		void nhap()
		{
			cout<<"Nhap so pt";cin>>n1;
			pt1=new T[n1];//<<" phan tu nguyen\n";
			for(int i=0; i<n1; i++)
			{
				cout<<"Nhap phan tu "<<i+1<<" ";
				cin>>pt1[i];
			}
		}
		
		void xuat()
		{
			cout<<"Day nguyen "<<n1<<" phan tu: ";
			for(int i=0; i<n1; i++)
			{
				cout<<pt1[i]<<" ";
			}
			cout<<endl;
		}
		
		T Max();
};
template <class T> T DemoLopMau <T>::Max()
		{
			T max=pt1[0];
			for(int i=0; i<n1; i++)
				if(pt1[i]>max)
					max=pt1[i];
			return max;
		}

class thisinh{
	string ten, mts;
	float diem;
	public:
		float get_diem()
		{
			return diem;
		}
		
		friend istream &operator>>(istream &is, thisinh &a)
		{
			cout<<"Nhap ho ten: ";fflush(stdin);getline(is, a.ten);
			cout<<"Nhap ma thi sinh: ";fflush(stdin);getline(is, a.mts);
			cout<<"Nhap diem: ";is>>a.diem;
			return is;
		}
		
		friend ostream &operator<<(ostream &os,const thisinh &a)
		{
			os<<setw(30)<<left<<a.ten<<" || "<<setw(7)<<a.mts<<" || "<<setw(4)<<a.diem<<endl;
			return os;
		}
	int operator>(const thisinh ts2)
		{
			return diem>ts2.diem;
		}
};
class  diem{
	float x, y;
	friend	istream &operator>>(istream &is, diem &a)
		{
			cout<<"Nhap hoanh do: ";is>>a.x; 
			cout<<"Nhap tung do: ";is>>a.y; 
			return is;
		}
		
friend	ostream &operator<<(ostream &os,const diem &a)
		{
			os<<"("<<setw(7)<<left<<a.x<<","<<a.y<<")"<<endl;
			return os;
		}
	public:	int operator>(const diem& ts2)
		{
			return (x*x+y*y)>(ts2.x*ts2.x+ts2.y*ts2.y) ;
		}
};



int main(){
	DemoLopMau <diem> dn;

	dn.nhap();
	dn.xuat();
	cout<<"\n max day n "<<dn.Max();

}

