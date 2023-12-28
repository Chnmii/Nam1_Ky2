#include <bits/stdc++.h>
using namespace std;
 
class Huychuong{
	int hcv, hcb, hcd;
	public:
 
		int getHCV(){
			return hcv;
		}
		int getHCB(){
			return hcb;
		}
		int getHCD(){
			return hcd;
		}
 
		int tongHc(){
			return hcv + hcb + hcd;
		}
 
		void input(){
			cout << "Nhap so luong huy chuong vang : ";
			cin >> hcv;
			cout << "Nhap so luong huy chuong bac : ";
			cin >> hcb;
			cout << "Nhap so luong huy chuong dong : ";
			cin >> hcd;	
		}
 
		void output(){
			cout << setw(16) << left << hcv << "|" << setw(16) << hcb << "|" << setw(16) << hcd << "|";			
 		}
};
class ThongKe
{
	string tennuoc;
	int HCV, HCB, HCD;
	public:
		ThongKe(){
 
		}
		ThongKe(string tennuoc, int HCV, int HCB, int HCD){
			this->tennuoc = tennuoc;
			this->HCV = HCV;
			this->HCB = HCB;
			this->HCD = HCD;			
		}
		int getHCV(){
			return HCV;
		}
		int getHCB(){
			return HCB;
		}
		int getHCD(){
			return HCD;		
		}
		string getTenNuoc(){
			return tennuoc;
		}
		void out(){
			cout << tennuoc << " " << HCV << " " << HCB << " " << HCD << endl;
		}
 
};
class Nguoi{
	string ht, ngaysinh, gt, nuoc;
 
	public:
		void input(){
			cin.ignore();
			cout << "Nhap ho ten : ";
			fflush(stdin);
			getline(cin, ht);
			cout << "Nhap ngay sinh : ";
			fflush(stdin);
			getline(cin, ngaysinh);
			cout << "Nhap gioi tinh : ";
			fflush(stdin);
			getline(cin, gt);
			cout << "Nhap nuoc : ";
			fflush(stdin);
			getline(cin, nuoc);
		}
 
		void output(){
			cout << endl << "|" << setw(20) << left << ht << "|" << setw(10) << ngaysinh << "|" << setw(10) << gt << "|" << setw(20) << nuoc << "|";
		}
 
		string getNuoc(){
			return nuoc;
		}
 
};
 
class Vandongvien:public Nguoi{
	string monthidau;
	int height, weight;
	Huychuong hc;
	public:
		void input(){
			Nguoi::input();
//			cin.ignore();
			cout << "Nhap mon thi dau : ";
			fflush(stdin);
			getline(cin, monthidau);
			cout << "Nhap can nang : ";
			cin >> weight;
			cout << "Nhap chieu cao : ";
			cin >> height;
			cout << "Nhap huy chuong : " << endl;
			hc.input();		
		}
 
		int getChieucao(){
			return height;
		}
 
		Huychuong getHc() {
			return hc;
		}
 
 
		void output(){
			Nguoi::output();
			cout << setw(20) << left << monthidau << "|" << setw(10) << weight << "|" << setw(10) << height << "|";
			hc.output();
		}
};
 
void Sapxep(Vandongvien *a, int n){
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++){
			if(a[i].getChieucao() > a[j].getChieucao()){
				Vandongvien tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
}
 
void Max_HCV(Vandongvien *a, int n){
	int max = 0;
	for(int i=1; i<=n; i++){
		if(a[i].getHc().getHCV() > max) 	max = a[i].getHc().getHCV();
	}
	for(int i=1; i<=n; i++){
		if(a[i].getHc().getHCV() == max){
			a[i].output();
		}
	}
}
 
void tongHuyChuong( Vandongvien *a, int n) {
            string *b = new string[n+1];
            int k = 0;
            for(int i = 1; i <= n; i++) {
            	int ok = 0;
            	for(int j = 1; j <= k; j++){
            		if(b[j] == a[i].getNuoc()){
            			ok = 1;
            			break;
					}
				}
                if (!ok) b[++k] = a[i].getNuoc();
            }
 
            for(int i = 1; i <= k; i++) {
                    int Tong = 0;
		        	for (int j = 1; j <= n; j++) {
		                if(a[j].getNuoc() == b[i]) {
		                    Tong += a[j].getHc().tongHc();
		                }
		            }
		            cout << "\n[ ' " << b[i] << " ' ]" << " : " << "[ ' " << Tong << " ' ]";
	            }
        }
 
int main(){
	int n;
	cout << "Nhap so luong van dong vien : ";
	cin >> n;
	cout << endl;
	Vandongvien *a = new Vandongvien[n+1];
	for(int i=1; i<=n; i++){
		a[i].input();
		cout << endl << "-----------------------" << endl << endl;
	}

	tongHuyChuong(a, n);
 
	return 0;
}
