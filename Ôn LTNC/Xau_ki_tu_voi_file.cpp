#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct Monhoc{
    char tenmon[20];
};

int main()
{
	 /*
        Nhap xau ki tu:
        + Khong dau cach:
            %s
        + Co dau cach:
            ^: gap thi dung
            %[ ^\n ]        : doc den khi nao gap dau \n thi dung   

        Nhap mot xau ki tu co dau cach tu file input.txt
        va xuat ra file output.txt
    */

    FILE *fi = fopen("input.txt","r");
    FILE *fo = fopen("output.txt","w");

    char xaukitu[20];
    fscanf(fi,"%[^\n]",&xaukitu);
    fprintf(fo,"%s",xaukitu);
	
	/*Nhap thong tin mon hoc tu file input.txt gom:
        + Dong dau tien: la so nguyen dai dien cho so phan tu
        + N dong tiep theo: moi dong se chua ten mon hoc

        Xuat thong tin ra file ouput.txt
    */
    FILE *fi = fopen("input.txt","r");
    FILE *fo = fopen("output.txt","w");
    int n;
    Monhoc a[20];

    //Nhap tu file
    fscanf(fi,"%d\n",&n);
    for(int i=1;i<=n;i++){
        fscanf(fi,"%[^\n]\n",&a[i].tenmon);
    }

    //Xuat ra file
    for(int i=1;i<=n;i++){
        fprintf(fo,"%s\n",a[i].tenmon);
    }

}


