#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class Eng{
	private:
		string ques, ans[4], ansC;
	public:
		
		friend istream &operator >> (istream &is, Eng &x){
			fflush(stdin);
			getline(is, x.ques);
			for(int i = 0; i < 4; i++){
				fflush(stdin);
				getline(is, x.ans[i]);
			}
		//	fflush(stdin);
			getline(is, x.ansC);
		//	is.ignore(1);
			return is;
		}
		friend ostream &operator << (ostream &os, Eng x ){
			os << x.ques <<endl;
			for(int i = 0; i < 4; i++){
				os << x.ans[i]<<endl;
			}
			return os;
		} 
		void dapan(){
			for(int i = 0; i < 4; i++){
				ans[0]="A";
				ans[1] ="B";
				ans[2] ="C";
				ans[3] ="D";
				
				if(ans[i] == ansC){
					cout << ans[i] << endl;
				}
			}
		}
		string get_ansC(){
			return ansC;
		}
} ;
class Eng_n{
	int n;
	Eng *a;
	string *dacb;
	public:
		static int diem;
		void nhap_file(string fn){
			ifstream fin(fn);
			fin >> n;
			a = new Eng[n+1];
			for(int i = 0; i < n; i++){
				fflush(stdin);
				fin >> a[i]; 
				fin.ignore(1);
			}
			fin.close();
		}
		void test(){
			dacb = new string[n+1];
			for(int i = 0; i < n; i++){
				cout << "\nCau hoi thu " << i+1 << ":";
				cout << a[i];
				cout << "Hay chon dap an dung: ";
			//	cin.ignore(1);
				fflush(stdin);
				getline(cin,dacb[i]);
				
				
			}
		}
		void xuatdapan(){
			cout << "\n-------DAP AN DUNG CUA TEST---------";
			for(int i = 0; i < n; i++){
				cout << "\nCau hoi thu " << i+1 << ": ";
				a[i].dapan();
				cout << "\nDap an ban chon:"; 
				cout << dacb[i];
				if(dacb[i] == a[i].get_ansC()){
					cout << "\nCau tra loi dung!";
					diem+=2;
				}
				else{
					cout << "\nCau tra loi sai!";
				}
				
			}
			
		}
		static int get_diem(){
			return diem;
		}
};
int Eng_n::diem = 0;
int main(){
	Eng_n x;
	int sel;
	do{
		cout << "\nMoi chon goi cau hoi:\n1.Goi 10 cau hoi\n2.Goi 15 cau hoi\n3.Goi 20 cau hoi\n4.Thoat\n";
		cin >> sel;
		switch(sel)
		{
			case 1:
				cout << "\n1.Goi 10 cau hoi";
				x.nhap_file("bo10cau.txt"); 
				x.test();
				x.xuatdapan();
				cout << "\nTong diem cua ban: " << Eng_n::get_diem();
				getch();
				system("cls");
				break;
			case 2:
				cout<< "\n2.Goi 15 cau hoi";
				x.nhap_file("bo15cau.txt");
				x.test();
				x.xuatdapan();
				cout << "\nTong diem cua ban: " << Eng_n::get_diem();
				getch();
				system("cls");
				break;
			case 3:
				cout<< "\n3.Goi 20 cau hoi";
				x.nhap_file("bo20cau.txt");
				x.test();
				x.xuatdapan();
				cout << "\nTong diem cua ban: " << Eng_n::get_diem();
				getch();
				system("cls");
				break;
			case 4:
				cout << "Bye!";
				getch();
				system("cls");
				break;
		}
	}
	while(sel>=1 and sel <=4);
	
}


