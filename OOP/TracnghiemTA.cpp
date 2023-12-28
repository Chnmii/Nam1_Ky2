#include <bits/stdc++.h>
using namespace std;

class Tracnghiem
{
	string cauhoi, daA, daB, daC, daD, dad;
	public:
		void tao_cauhoi()
		{
			
			
		}
		static int tinhdiem;
};

int main()
{
	int chon;
	cout << "Moi ban chon goi cau hoi:\n 1.Goi 10 cau hoi\n2.Goi 15 cau hoi\n3.Goi 20 cau hoi\n";
	cin >> chon;
	string file;
	switch(chon){
		case 1:
		{
			file = "bo10cau.txt";
			cout << "Ban da chon goi 10 cau hoi" << endl; 
			break;
		}
		case 2:
		{
			file = "bo15cau.txt";
			cout << "Ban da chon goi 15 cau hoi" << endl; 
			break;
		}
		case 3:
		{
			file = "bo20cau.txt";
			cout << "Ban da chon goi 20 cau hoi" << endl; 
			break;
		}
	}
}

