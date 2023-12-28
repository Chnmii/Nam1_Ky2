#include <bits/stdc++.h>
using namespace std;
 
// day la lop co so 
class Hinh 
{
	protected:
   		int chieurong;
   		int chieucao;
	public:
   
   	virtual int tinhDienTich() = 0;
   	void setChieuRong(int rong)
   	{
    	chieurong = rong;
   	}
   	void setChieuCao(int cao)
   	{
    	chieucao = cao;
   	}

};
 
// cac lop ke thua
class HinhChuNhat: public Hinh
{
	public:
   		int tinhDienTich()
   		{ 
    		return (chieurong * chieucao); 
   		}
};

class TamGiac: public Hinh
{
	public:
   		int tinhDienTich()
   		{ 
      		return (chieurong * chieucao)/2; 
   		}
};
 
int main()
{
   HinhChuNhat hcn;
   TamGiac  tg;
 
   hcn.setChieuRong(25);
   hcn.setChieuCao(4);
   
   // in dien tich cua doi tuong 1
   cout << "Dien tich HinhChuNhat la: " << hcn.tinhDienTich() << endl;

   tg.setChieuRong(20);
   tg.setChieuCao(15);
   
   // in dien tich cua doi tuong 2
   cout << "Dien tich TamGiac la: " << tag.tinhDienTich() << endl; 

   return 0;
}
