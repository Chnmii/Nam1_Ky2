#include <bits/stdc++.h>
using namespace std;

class KH
{
	    int ngay;		    
		string ma, ten, dchi;
    	double sotrc, sosau, tiendong;
	public:
		string getten(){return ten;}
		
		double tien()
		{
 	       	int x = sosau - sotrc;
 	       	int tong = 0;
 	       	int moc[4]={200, 100, 50, 0};
 	       	int money[4]={400, 300, 200, 100};
 	       
 	       	for (int i=0; i<4; i++)
 	       	{
 	       		if(x > moc[i])
 	       		{
 	       			int temp = x - moc[i];
 	       			tong += temp * money[i];
 	       			x = moc[i];
				}
			}
			return tong*1.1/1.0;
		}
		
    	friend istream &operator >> (istream &Cin, KH &A)
		{
     	   	cout << "Ma khach : ";
			fflush(stdin);
			getline(Cin, A.ma);
     	   	cout << "Ten khach : ";
			fflush(stdin);
			getline(Cin, A.ten);
     	   	cout << "Dia chi : ";
			getline(Cin, A.dchi);
     	   	cout << "Ngay chot : ";
			Cin >> A.ngay;
     	   	cout << "So dien thang truoc : ";
			Cin >> A.sotrc;
     	   	cout << "So dien thang sau : ";
			Cin >> A.sosau;
     	   	A.tiendong = A.tien();
     	   	return Cin;
    	}
    	
    	friend ostream &operator << (ostream &Cout, const KH &A)
		{
     	   Cout << setw(15) << left << A.ma << "||" << setw(20) << A.ten << "||" << setw(15) << A.dchi << "||" << setw(8) << A.ngay << "||" << setw(8) << A.sotrc << "||" << setw(8) << A.sosau << "||" << setw(15) << A.tiendong;
     	   return Cout;
    	}
};

class QLKH
{
    int n;
    KH *A;
	public:
 		QLKH() { n=-1; A = NULL; }
    	void nhap()
		{
        	cout << "Nhap so khach hang: ";
			cin >> n;
        	A = new KH[n+1];
        	for(int i=0; i<n; i++)
			{
        	    cout<<"Khach hang " << i+1 << ":\n";
            	cin >> A[i];
        	}
    	}
		void find()
		{
			int d=0;
			string x;
			cout << "Nhap ho ten khach hang muon tim : ";
			fflush(stdin);
			getline(cin, x);
			for(int i=0; i<n; i++)
			{
				if(A[i].getten() == x)
				{
					cout << A[i];
					d++;
				}
			}
			if (d==0) cout << "Khach hang " << x << " hien chua co trong danh sach";
		}
		
    	~QLKH(){ if(A) delete[]A; }
};

int main()
{
	QLKH A;
	A.nhap();
	A.find();
	
	return 0;
}
