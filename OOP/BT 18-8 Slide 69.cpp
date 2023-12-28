#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

struct sv{
	string ht, sbd;
	float m1, m2, m3;
};

void nhapds(int &n, sv *&a)
{
	cout << "\nNhap so thi sinh: "; cin >> n;
	a = new sv[n+5];
	for (int i=0; i<n; i++)
	{
		cout << "Ho ten: ";
		fflush(stdin);
		getline(cin, a[i].ht);
		cout << "SBD: ";
		getline(cin, a[i].sbd);
		cout << "Diem mon1: "; cin >> a[i].m1;
		cout << "Diem mon2: "; cin >> a[i].m2;
		cout << "Diem mon3: "; cin >> a[i].m3;	
	}
}

float tong(sv a)
{
	return a.m1+a.m2+a.m3;
}

void xuat(sv a)
{
	cout << setw(20) << left << a.ht << "||" << setw(15) << a.sbd << "||" << setw(10) << setprecision(2) << fixed << a.m1 << "||" << setw(10) << a.m2 << "||" << setw(10) << a.m3 << "||" << setw(10) << tong(a) << endl;
}

void dstt(int n, sv *a)
{
	float d, dem = 0;
	cout << "\nMoi nhap diem chuan: "; cin >> d;
	cout << "\nCac thi sinh trung tuyen la:\n";
	for (int i=0; i<n; i++)
	{
		if (tong(a[i]) >= d)
		{
			xuat(a[i]);
			dem++;
		}	
	}
	if (dem == 0)
		cout << "\nKo co thi sinh nao trung tuyen";
}

void diembq(int n, sv *a)
{
	float T=0;
	for (int i=0; i<n; i++)
		T += tong(a[i]);
	cout << "\nDiem binh quan la: " << setprecision(2) << fixed << T/n;
}

void diem_max(int n, sv *a)
{
	float max = 0;
	cout << "\nCac thi sinh co diem cao nhat la:\n";
	for (int i=0; i<n; i++)
	{
		if (tong(a[i]) >= max)
			max = tong(a[i]);
	}
	for (int i=0 ;i<n; i++)
	{
		if (max == tong(a[i]))
			xuat(a[i]);
	}
}

void find(int n, sv *a)
{
	string x; int d=0;
	cout << "\nNhap SBD can tim: "; 
	fflush(stdin);
	getline(cin,x);
	for (int i=0; i<n; i++)
	{
		if (x == a[i].sbd)
		{
			xuat(a[i]);
			d++;
		}	
	}
	if (d==0)
		cout << "\nSBD ko co trong danh sach thi sinh" << endl;
}

void sx(int n, sv *a)
{
	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (tong(a[i]) < tong(a[j]))
				swap(a[i], a[j]);
		}
	}
	for (int i=0; i<n; i++)
		xuat(a[i]);
}

main()
{
	int n, c;
	bool k = false;
	sv *a;
	do
	{
		cout << "1.Nhap danh sach thi sinh\n2.In danh sach trung tuyen\n3.Tinh diem binh quan\n4.Tim cac thi sinh co diem cao nhat\n5.Tim thi sinh co SBD x\n6.Sap xep danh sach theo thu tu diem giam dan\n7.Thoat\nMoi ban chon: ";
		cin >> c;
		switch(c)
		{
			case 1:
			{
				system("cls");
				cout << "Ban da chon nhap danh sach thi sinh!";
				nhapds(n,a);
				cout << "\nBan da nhap thanh cong!";
				k = true;
				cout << "\nBam phim bat ky de tiep tuc!";
				
				getch();
				break;
			}
			case 2:
			{
				system("cls");
				if (k) 
				{
					cout << "Ban da chon in danh sach trung tuyen!";
					dstt(n,a);
				}
				else
					cout << "Ban can nhap danh sach truoc";
				cout << "\nBam phim bat ky de tiep tuc!";
				
				getch();
				break;
			}
			case 3:
			{
				system("cls");
				if (k) 
				{
					cout << "Ban da chon tinh diem binh quan!";
					diembq(n,a);
				}
				else
					cout << "Ban can nhap danh sach truoc";
				cout << "\nBam phim bat ky de tiep tuc!";
				
				getch();
				break;
			}
			case 4:
			{
				system("cls");
				if (k) 
				{
					cout << "Ban da chon tim cac thi sinh co diem cao nhat!";
					diem_max(n,a);
				}
				else
					cout << "Ban can nhap danh sach truoc";
				cout << "\nBam phim bat ky de tiep tuc!";
				
				getch();
				break;
			}
			case 5:
			{
				system("cls");
				if (k) 
				{
					cout << "Ban da chon tim thi sinh co SBD x!";
					find(n,a);
				}
				else
					cout << "Ban can nhap danh sach truoc";
				cout << "\nBam phim bat ky de tiep tuc!";
				
				getch();
				break;
			}
			case 6:
			{
				system("cls");
				if (k) 
				{
					cout << "Ban da chon Sap xep danh sach theo thu tu diem giam dan!" << endl;
					sx(n,a);
				}
				else
					cout << "Ban can nhap danh sach truoc";
				cout << "\nBam phim bat ky de tiep tuc!";
				
				getch();
				break;
			}
			case 7:
				return 0;
		}
		system("cls");
		getch();
	}
	while (c>=1 && c<=7);
	
	return 0;
}
