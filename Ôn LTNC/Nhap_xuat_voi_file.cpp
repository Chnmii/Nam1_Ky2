#include"stdio.h"
#include"math.h"
#include"string.h"
#include"stdlib.h"
/*
    Nhap xuat file

    Ly thuyet:

    - Lam viec voi file text ( duoi la .txt )

    -Thao tac thu cong: thao tac co the nhin thay qua trinh thuc hien 
        + Tao file
        + Ghi thong tin
        + Dong,mo
        VD:    file Input.txt
        + .txt => dang tao file text
        + ten la Input

    -Thao tac voi code:    thao tac khong the nhin thay qua trinh thuc hien
        + Kieu du lieu moi: FILE ( dung de lam viec voi file )    
        + Su dung con tro kieu FILE de quan ly file
        VD:    Khai bao mot con tro kieu FILE co ten la fi
            + fi:    file input : file chua thong tin dau vao
            + fo: file ouput    : file chua thong tin dau ra

        FILE(kieu du lieu) *fi;

        **Ham fopen(xau ki tu chua duong dan file, xau ki tu chua thao tac voi file) " "
            + La ham tra ve gia tri
            + Mo file tra ve mot con tro kieu FILE 

        **Duong dan:
            -Duong dan tuyet doi ( gioi thieu )
                VD:    C:\\Users\\Duyanh\\Desktop\\Input.txt
                Uu diem:
                    + Tuong tac voi tat ca cac file
                Nhuoc diem:
                    + Mat cong di lay duong dan

            -Duong dan tuong doi:    ten cua file can mo ( hay dung )
                VD: Input.txt
                Chu y: code va file muon su dung phai duoc luu cung mot thu muc

        **Thao tac voi file:
            + r: read ( doc thong tin tu file )
            Ham giup nhap thong tin tu file:

            fscanf(con tro quan ly file muon nhap, "%d" , & )

            + w: write ( ghi thong tin ra file )

            printf("...");
            fprintf(con tro quan ly file muon ghi, "noi dung can ghi");
*/

struct Diem{
    double x;
    double y;
};

int main(){
    /*
        Nhap mot so nguyen x tu file SoNguyen.txt va in no ra man hinh
    */
    int x;
    FILE *fi;    
    fi = fopen("SoNguyen.txt","r");    
    //con tro *fi quan ly file SoNguyen.txt, mo file SoNguyen.txt va thuc hien viec "r" doc tu file
    //fscanf(con tro quan ly file muon nhap, "%d" , & )
    fscanf(fi,"%d",&x);
    printf("X = %d",x);
 
    /*
        Doc vai thong tin tu file input.txt gom cac thong tin sau: 
        + Mot so nguyen x
        + Mot so thuc y
        + Mot Diem a
        + Mot xau ki tu s khong co dau cach

        Va in ra file output.txt
    */
    int x;
    double y;
    Diem a;
    char s[20];

    FILE *fi = fopen("input.txt","r");
    fscanf(fi,"\n%d",&x);
    fscanf(fi,"\n%lf",&y);
    fscanf(fi,"\n%lf%lf",&a.x,&a.y);
    fscanf(fi,"\n%s",&s);
    
	FILE *fo = fopen("output.txt","w");
    fprintf(fo,"X = %d\n",x);
    fprintf(fo,"Y = %lf\n",y);
    fprintf(fo,"A = (%lf, %lf)\n",a.x,a.y);
    fprintf(fo,"S = %s\n",s);
 	
}
