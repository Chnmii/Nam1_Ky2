#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

float dtich(const float &r)
{
	return r*r*3.14;
}

float dtich(const float &a, const float &b)
{
	return a*b;
}

float dtich(const float &a, const float &b, const float &c)
{
	float p = (a+b+c)/2;
	float s = sqrt(p* (p-a) * (p-b) * (p-c));
	return s;
}

main()
{
	float r, cd, cr, a, b, c;
	int v;
	cout << setprecision(2) << fixed;
	do
	{
		cout << "1.Tinh dien tich hinh tron\n2.Tinh dien tich HCN\n3.Tinh dien tich HTG\n4.Thoat\nMoi ban chon: ";
		cin >> v;
		switch (v)
		{
			case 1:
			{
				system("cls");
				cout << "Ban da chon tinh dien tich hinh tron!" << endl;
				cout << "Nhap ban kinh: "; cin >> r;
				cout << "Dien tich hinh tron = " << dtich(r);
				cout << "\nBam phim bat ky de tiep tuc";
				
				getch();
				break;
			}
			case 2:
			{
				system("cls");
				cout << "Ban da chon tinh dien tich HCN!" << endl;
				cout << "Nhap chieu dai: "; cin >> cd;
				cout << "Nhap chieu rong: "; cin >> cr;
				cout << "Dien tich HCN = " << dtich(cd,cr);
				cout << "\nBam phim bat ky de tiep tuc";

				getch();
				break;
			}
			case 3:
			{
				system("cls");
				cout << "Ban da chon tinh dien tich HTG!" << endl;
				cout << "Nhap do dai 3 canh: "; cin >> a >> b >> c;
				cout << "Dien tich HTG = " << dtich(a,b,c);
				cout << "\nBam phim bat ky de tiep tuc";
		
				getch();
				break;
			}
			case 4:
				return 0;
		}
		system("cls");
		getch();
	}
	while (v>=1 && v<=3);
	
	return 0;
}
