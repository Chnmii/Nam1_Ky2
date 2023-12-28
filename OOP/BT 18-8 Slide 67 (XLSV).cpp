#include <bits/stdc++.h>
using namespace std;

void xlsv(float d)
{
	if (d>=9)
		cout << "Sinh vien nay xep loai xuat sac" << endl;
	else if (d<9 && d>=8) 
			cout << "Sinh vien nay xep loai gioi\n";
		 else  if (d<8 && d>=7) 
		 			cout << "Sinh vien nay xep loai kha\n";
			   else  if (d<7 && d>=6) 
			   			cout << "Sinh vien nay xep loai trung binh\n";
					 else cout << "Sinh vien nay xep loai yeu\n";
}

main()
{
	float diem;
	cout << "Moi nhap diem: " << endl;
	cin >> diem;
	xlsv(diem);
	
	return 0;
}
