#include <bits/stdc++.h>
using namespace std;

class diemthi
{
	public:
		float diem;
		string ma, ten;
		int tin;
		float dqt, dt;
		
		friend istream & operator >> (istream &is, diemthi &s)
		{
			cout << "Nhap diem: ";
			cin >> s.diem;
			cout << "Nhap ma mon: ";
			fflush(stdin);
			getline(cin, s.ma);
			cout << "Nhap ten mon: ";
			getline(cin, s.ten);
			cout << "Nhap so tin chi: ";
			cin >> s.tin;
			
			return is;
		}
		friend ostream & operator << (ostream &os, diemthi s)
		{
			os << setw(10) << left << s.diem << "||" << setw(8) << s.ma << "||" << setw(10) << s.ten << "||" << setw(8) << s.tin << endl;
			return os;	
		}
};

class dsdiem
{
	int n;
	diemthi *a;
	public:
		dsdiem(){n=0;a=NULL;}
		~dsdiem(){if(a) delete[]a;}
		
		void nhap()
		{
			cout << "Nhap so mon: ";
			cin >> n;
			a = new diemthi[n+2];
			for (int i=0; i<n; i++)
				cin >> a[i];
		}
		void dsthilai()
		{
			cout << "\nDanh sach cac mon thi lai:\n";
			for (int i=0; i<n; i++)
			{
				if (a[i].diem < 5)
					cout << a[i];
			}
		}
};

class dsdiem2
{
	int n;
	diemthi *a;
	public:
		dsdiem2(){n=0;a=NULL;}
		~dsdiem2(){if(a) delete[]a;}
		
		void nhaplai()
		{
			cout << "Nhap so mon: ";
			cin >> n;
			a = new diemthi[n+2];
			for (int i=0; i<n; i++)
			{
				cout << "Nhap ma mon: ";
				fflush(stdin);
				getline(cin, a[i].ma);
				cout << "Nhap ten mon: ";
				getline(cin, a[i].ten);
				cout << "Nhap so tin chi: ";
				cin >> a[i].tin;
				cout << "Nhap diem qua trinh: ";
				cin >> a[i].dqt;
				cout << "Nhap diem thi: ";
				cin >> a[i].dt;
				a[i].diem = 0.3*a[i].dqt + 0.7*a[i].dt;
			}
		}
		void thilai()
		{
			cout << "\nDanh sach cac mon thi lai theo yeu cau moi: ";
			for (int i=0; i<n; i++)
			{
				if (a[i].diem < 4)
					cout << a[i];
			}
		}
};

int main()
{
	dsdiem a;
	a.nhap();
	a.dsthilai();
	dsdiem2 b;
	b.nhaplai();
	b.thilai();
}

