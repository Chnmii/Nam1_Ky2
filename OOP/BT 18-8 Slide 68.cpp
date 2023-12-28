#include <bits/stdc++.h>
using namespace std;

main()
{
	// cau 1
	int d=0;
	float T=0, diem;
	cout << "Moi nhap diem: " << endl;
	while (diem!=-1)
	{
		cin >> diem;
		if (diem == -1) break;
		T += diem;
		d++;
	}
	if (d>0)
		cout << "DTB cua cac svien la: " << setprecision(2) << fixed << T/d << endl;
	else
		cout << "Chua nhap diem";
	
	// cau 2
	int chon, d=0;
	float diem;
	cout << "Moi nhap diem: "; cin >> diem;
	float T = diem;
	if (diem < 0)
	{
		cout << "Nhap lai diem > 0: ";
		cin >> diem;
	}
		
	do
	{
		cout << "1.Nhap tiep\n2.Thoat\nMoi ban chon: ";
		cin >> chon;
		switch (chon)
		{
			case 1:{
				cout << "Moi nhap diem: "; 
				cin >> diem;
				T += diem;
				d++;
				break;
			}
			case 2:
				cout << "DTB cua cac svien la: " << setprecision(2) << fixed << T/(d+1) << endl;
				return 0;
		}
		
	} while(chon == 1 || chon ==2);
	
	return 0;
}
