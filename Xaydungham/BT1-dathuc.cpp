#include <iostream>
#include <math.h>
using namespace std;

class DaThuc
{
    int bac;
    float *hs;
 	public:
		void nhapdt(char);
		void indt();
		float tinhgt(float);
		void hieudt(DaThuc, DaThuc);
};

void DaThuc :: nhapdt(char c)
{   
    cout << "\nNhap bac cua da thuc " << c << ": ";
    cin >> bac;
    hs= new float[bac+1];
    int i;
    for(i=0; i <= bac; i++)
    {
        cout << "Nhap hs ung voi bac " << i << ": ";
        cin >> hs[i];
    }
    while (hs[bac] == 0)
    {
    	cout << "nhap he so thu " << bac << "khac 0: ";
    	cin >> hs[bac];
	}
}

void DaThuc :: indt(){
    cout << hs[0];
	
	for (int i=1; i <= bac; i++){
		cout << "+ " << hs[i] << "x^" << i;
	}
}

float tinhgt( float d)
{
    float s=hs[0];
    for (int i=1; i <= bac; i++)
    {
        s+= hs[i]*pow(d,i);
    }
    return s;
}

void hieudt(DaThuc Q,DaThuc &R)
{
	int max = bac > Q.bac ? bac : Q.bac;
	int min = bac < Q.bac ? bac : Q.bac;
	R.hs = new float[R.bac+1];
	R.bac = max;
	for (int i=0; i <= min; i++)
    {
		R.hs[i]= P.hs[i] - Q.hs[i];
	}
	for (int i = min+1; i <= max; i++)
    {
		R.hs[i]= P.bac > Q.bac ? P.hs[i] : -Q.hs[i];
	}
}

int main()
{
	float d;
    DaThuc P,Q,R;
    P= P.nhapdt('P');
	cout << "\nP(x)= "; P.indt();
    
    Q= Q.nhapdt('Q');
    cout << "\nQ(x)= "; Q.indt();

	R.hieudt(P,Q,R);
	cout << "\nP(x)-Q(x)= "; R.indt();
	
	cout << "\nNhap so thuc d: "; cin >> d;
	cout << "R(d) = " << R.tinhgt(d);
    return 0;
}
