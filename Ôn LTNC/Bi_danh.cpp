//Nhap mon ve bi danh
 
#include"stdio.h"	
#include"math.h"	
#include"string.h"	
#include"stdlib.h"	
 
void nhapSoNguyen(int &x){	//&x nghia la bi danh de quan ly so nguyen x
	printf("Nhap so nguyen: ");
	scanf("%d", &x);   //scanf("%d",x)	&+* = ko can ghi
}
 
void tangNamDonVi(int &n){
	n = n + 5;	
}
 
void nhapVaTinhTongHieu(int &a, int &b, int &tong, int &hieu){
	//Nhap a,b => a,b co gia tri
	printf("\n\nNhap 2 so nguyen: ");
	scanf("%d%d",&a, &b);
 
	//Gan gia tri 4 bien tong, hieu, tich, thuong
	tong = a + b;
	hieu = a - b;
 
}
 
int main(void) {
	//VD 1: nhap so nguyen x va tang them 5 don vi
	int x;
	nhapSoNguyen(x);
	printf("X = %d",x);
	tangNamDonVi(x);
	printf("\nX sau khi tang 5 don vi la %d",x);
 
	//VD 2: nhap 2 so nguyen a,b va tinh tong hieu
	int a,b;
	int tong,hieu;
	nhapVaTinhTongHieu(a,b,tong,hieu);
	printf("a = %d, b = %d",a,b);
	printf("\ntong = %d, hieu = %d",tong,hieu);
}
