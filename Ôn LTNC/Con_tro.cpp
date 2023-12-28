#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
/*
Ly thuyet:
    Con tro: ki hieu *
Cong dung 1: Dung de quan ly cac gia tri dau vao neu nhu ham co chuc nang thay doi gia tri dau vao:
            + Nhap
            + Cap phat (bien con tro tro thanh mang mot chieu)
            + Giai phong ( nguoc lai cua cap phat)
        Cach dung:
            + Ham: cho nao co con tro thi phai ghi them dau *
            + Main: cho nao can truyen con tro thi phai them dau & */


/*Ham nhap so nguyen
    Dau vao: con tro de quan ly mot so nguyen(ko co gia tri)
    Thuc hien:  thuc hien nhap so nguyen ma minh truyen vao
    Dau ra:    thu duoc so nguyen sau khi da nhap ( co gia tri )
*/
 
void nhapSoNguyen(int *x){	//*x nghia la con tro de quan ly so nguyen x
	printf("Nhap so nguyen: ");
	scanf("%d", &(*x) );   //scanf("%d",x)	&+* = ko can ghi
}
 
void tangNamDonVi(int *n){	//*n la con tro quan ly so nguyen n
	(*n) = (*n) + 5;	//Tang *n them 5 don vi
}
 
void nhapVaTinhTongHieu(int *a, int *b, int *tong, int *hieu){
	//Nhap a,b => a,b co gia tri
	printf("Nhap 2 so nguyen: ");
	scanf("%d%d",&(*a), &(*b));
 
	//Gan gia tri 4 bien tong, hieu, tich, thuong
	(*tong) = (*a) + (*b);
	(*hieu) = (*a) - (*b);
 
}
 
int main(void) {
	//VD 1: nhap so nguyen x va tang them 5 don vi
	int x;
	nhapSoNguyen(&x);
	printf("X = %d",x);
	tangNamDonVi(&x);
	printf("\nX sau khi tang 5 don vi la %d\n",x);
 
	//VD 2: nhap 2 so nguyen a,b va tinh tong hieu
	int a,b;
	int tong,hieu;
	nhapVaTinhTongHieu(&a,&b,&tong,&hieu);
	printf("a = %d, b = %d",a,b);
	printf("\ntong = %d, hieu = %d",tong,hieu);
}

