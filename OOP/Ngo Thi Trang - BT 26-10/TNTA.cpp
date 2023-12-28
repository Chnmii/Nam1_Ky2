#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h> 
using namespace std;

void set_color ( int code ) 
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( color , code );
}

class cauhoi
{
	string de;
	string daA, daB, daC, daD;
	string dad; 
	public:
		friend istream &operator>>(istream &is, cauhoi &x)
		{
			fflush(stdin);
			getline(is, x.de);
			fflush(stdin);
			getline(is, x.daA);			
			fflush(stdin);
			getline(is, x.daB);
			fflush(stdin);
			getline(is, x.daC);
			fflush(stdin);
			getline(is, x.daD);
			fflush(stdin);
			getline(is, x.dad);
			return is;			
		}
		string docde()
		{
			return de; 
		} 
		friend ostream &operator<<(ostream &os, cauhoi x)
		{
			os << x.de << endl; 
			os << x.daA << setw(30) << x.daB << setw(30) << x.daC << setw(30) << x.daD;
			return os;
		}
		void xuatdapan()
		{
			daA="A", daB="B", daC="C", daD="D";
			cout << de << endl;
			if(daA==dad)
			{
				set_color(2);
				cout << "\t" << daA;
				set_color(7);
			}
			else
				cout<<"\t"<<daA;
			if(daB==dad)
			{
				set_color(2);
				cout << "\t" << daB;
				set_color(7);
			}
			else
				cout << "\t" << daB;
			if(daC==dad)
			{
				set_color(2);
				cout << "\t" << daC;
				set_color(7);
			}
			else
				cout << "\t" << daC;
			if(daD==dad)
			{
				set_color(2);
				cout << "\t" << daD;
				set_color(7);
			}
			else
				cout << "\t" << daD;
		}
		string getdapan()
		{
			return dad;
		}
}; 

class dethi
{
	int n;
	string x; 
	string *dachon;
	cauhoi *a;
	public:
		static int tinhdiem;
		void nhap(const string &fn)
		{
			ifstream fin(fn);
			fin >> n;
			a = new cauhoi[n+5];
			for(int i=0; i<n; i++)
			{
				fin.ignore(1);
				fin >> a[i];
			}
			fin.close();
		}
		
		void chuongtrinh()
		{
			getch();
			system("cls");
			dachon = new string[n+5];
			for(int i=0; i<n; i++)
			{
			
				cout << "\nCau hoi thu: " << i+1 << " :\n";
				cout << a[i] << endl;
				cout << "\nNhap dap an cua ban(A,B,C,D): ";
				fflush(stdin);
				getline(cin, x);
				while(x!= "A" && x!= "B" && x!= "C" && x!= "D")
				{
					set_color(4); 
					cout << "Dap an khong hop le \n Moi ban nhap lai : ";
					cin >> x;
				}
				set_color(7); 
				dachon[i] = x;
				if(x==a[i].getdapan())
				{
					set_color(2); 
					cout << "Ban da tra loi dung!";
					tinhdiem += 2;	
				}
				else
				{
					set_color(4);
					cout << "Ban da tra loi sai!";			
				}
				set_color(7);

			}
		}
		void xuatdapan()
		{		
			cout << "\nDap an cua de la (mau xanh hien thi dap an dung): " << endl;
			for(int i=0; i<n; i++)
			{
				cout << "\nCau hoi thu " << i+1 << "\t";
				a[i].xuatdapan();
				set_color(5);
				cout << "\nDap an cua ban la: ";
				if(dachon[i]==a[i].getdapan())
				{
					set_color(2);
					cout << dachon[i] << " (ban da tra loi dung)";						
				}
				else
				{
					set_color(4);
					cout << dachon[i] << " (ban da tra loi sai)";	
				}
				set_color(7);			
			}
			
		}
		static int getdiem()
		{
			return tinhdiem;
		}
}; 

int dethi::tinhdiem= 0;

int main()
{
	dethi de;
	int chon, dem=0;
	string file;
	int c; 
	while(c!=27)
	{ 
		cout << "Ki thi trac nghiem tieng anh";
		cout << "\nCac goi cau hoi:\n"; 
		cout << "1. Goi cau hoi 10 cau \n2. Goi cau hoi 15 cau \n3. Goi cau hoi 20 cau" << endl;
		cout << "\nMoi cau tra loi dung ban se nhan duoc 2 diem!\n";
		cout << "Moi ban chon:";
		cin >> chon;
		if(chon==1)
		{
			file = "bo10cau.txt";	
			cout << "Ban da chon goi 10 cau hoi\nNhan phim bat ki de bat dau thi\n";			
		}
		if(chon==2)
		{
			file = "bo15cau.txt";	
			cout << "Ban da chon goi 15 cau hoi\nNhan phim bat ki de bat dau thi\n";			
		}
		if(chon==3)
		{
			file = "bo20cau.txt";	
			cout << "Ban da chon goi 20 cau hoi\nNhan phim bat ki de bat dau thi\n";			
		}	
		de.nhap(file);
		de.chuongtrinh();
		
		set_color(1);
		cout << "\n\nDiem cua ban la: " << dethi::getdiem();
		
		set_color(7);
		de.xuatdapan();
		
		cout << "\n\nNhan ESC de thoat khoi chuong trinh\nNhan phim bat ki de tiep tuc" << endl; 
		c=getch();		
	}
	return 0;
}

