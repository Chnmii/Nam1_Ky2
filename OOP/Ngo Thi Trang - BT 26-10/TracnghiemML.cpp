#include <bits/stdc++.h>
using namespace std;

class multiques
{
	private:
		string ques, choice[4];
		char ans;
	public:
		void read(ifstream &Cin)
		{
			getline(Cin, ques);
			for(int i = 0; i < 4; i++)
			{
				getline(Cin, choice[i]);
			}
			Cin >> ans;
			Cin.ignore(1);
		}
		friend ostream &operator << (ostream &Cout, const multiques &x)
		{
			Cout << x.ques << endl;
			for(int i = 0; i < 4; i++)
			{
				Cout << x.choice[i] << endl;
			}
			return Cout;
		}
		bool check(char _ans)
		{
			_ans = toupper(_ans);
			if(_ans == ans)	return 1;
			return 0;
		}
		char get_ans()
		{
			return ans;
		}
};

class eng_Test
{
	int n, diem = 0;
	multiques *a;
	public:
		nhaptest()
		{
			ifstream Cin; Cin.open("detest.cpp");
			a = new multiques[n];
			for(int i = 0; i < n; i++)
			{
				a[i].read(Cin);
			}		
		}
		void testing()
		{
			int k;
			char dap_an;
			cout << "Moi nhap goi cau hoi:\nGoi 1.(10 cau hoi)\nGoi 2.(15 cau hoi)\nGoi 3.(20 cau hoi) ";
			cout << "\nMoi nhap sua chon cua ban (1, 2, 3): ";
			do
			{
				cin >> k;
				if(k < 1|| k > 3) cout << "Moi nhap lai: ";
			}while(k < 1||k > 3); 
			
			n = (k + 1) * 5;
			nhaptest();
			for(int i = 0; i < n; i++)
			{
				cout << endl << a[i];
				cout << "Moi nhap dap an: ";
				cin >> dap_an;
				if(a[i].check(dap_an))
				{
					cout << "Dung +2 points\n";
					diem += 2;
				}
				else cout << "Sai +0 points\n";
			}
		}
		void cau_tra_loi()
		{	
			cout << "\nDap an cua ban thi:\n";
			for(int i = 0; i < n; i++)
			{
				cout << i + 1 << ". " << a[i].get_ans() << endl;
			}
		}
		int get_diem()
		{
			return diem;
		}
};

int main()
{
	eng_Test v;
	v.testing();
	cout << "\nDiem so: " << v.get_diem();
	v.cau_tra_loi();
	return 0;
}

