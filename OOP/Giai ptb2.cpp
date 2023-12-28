#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

class PTB2{
	double a,b,c;
	public:
		void nhap();
		void xuat();
		void gpt();
};

void PTB2::nhap(){
	cout << "Nhap cac he so: ";
	cin >> a >> b >> c;
	while (a==0)
	{
		cout << "Nhap a khac 0"; cin >> a;
	}
}

void PTB2::xuat(){
	cout << "Pt la: ";
	cout << a << "x^2 + " << b << "x + " << c << " = 0";
}

void PTB2::gpt(){
	float delta;
	if (a==0)
		cout << "a=0";
	delta= b*b-4*a*c;
	if (delta <0)
		cout << "\nPT vo nghiem";
	else if (delta > 0)
			cout << "\nPT co 2 nghiem x1 = " << (-b-sqrt(delta))/(2*a) << " va x2 = " << (-b+sqrt(delta))/(2*a) ;
	
}
int main()
{
	PTB2 x;
	x.nhap();
	x.xuat();
	x.gpt();
	char d = _getch(); // den khi gap ESC thi ket thuc
	if (d==27) exit(0);
}
