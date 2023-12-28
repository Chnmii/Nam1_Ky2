#include<bits/stdc++.h>
using namespace std;
class Diem{
	private:
		double x, y;
	public:
		Diem(){
			x = 0;
			y = 0;
		}
		void nhap(){
			cout << "Nhap hoanh do: "; cin >> x;
			cout << "Nhap tung do: "; cin >> y;			
		}
		void xuat(){
			cout << "(" << x << ", " << y << ")";			
		}
		double kc(Diem a){
			return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
		}
		int Check(){
			if(x * 3 + 5 > y) return 1;
			if(x * 3 + 5 < y) return 2;
			return 3;
		}
};
class DS_Diem{
	private:
		int n;
		Diem *a;
	public:
		void nhap(){
			cout << "Nhap vao so diem: "; cin >> n;
			a = new Diem[n+1];
			for(int i = 0; i < n; i++){
				a[i].nhap();
			}
		}
		void xuat(){
			for(int i = 0; i < n; i++){
				a[i].xuat();
			}
		}
		void Dgk(){
			double s = 0;
			for(int i = 0; i < n - 1; i++){
				s += a[i].kc(a[i + 1]);
			}
			cout << "Duong khap khuc: " << s << endl;
		}
		Diem xn(Diem x){
			double max = 0;
			Diem tmp;
			for(int i = 0 ; i < n; i++){
				if(max < a[i].kc(x)){
					max = a[i].kc(x);
					tmp = a[i];
				}
			}
			return tmp;
		}
		Diem gn(Diem x){
			double min = DBL_MAX;
			Diem tmp;
			for(int i = 0 ; i < n; i++){
				if(min > a[i].kc(x)){
					min = a[i].kc(x);
					tmp = a[i];
				}
			}
			return tmp;
		}
		void Kc_x(){
			Diem x;
			x.nhap();
			cout << "\nDiem xa x nhat la: "; xn(x).xuat();
			cout << "\nDiem gan x nhat la: "; gn(x).xuat();			
		}
		void Sol(){
			int cnt1, cnt2, cnt3;
			cnt1 = cnt2 = cnt3 = 0;
			for(int i = 0; i < n; i++){
				if(a[i].Check() == 1) cnt1++;
				else if(a[i].Check() == 2) cnt2++;
				else cnt3++;				
			}
			cout << endl << cnt1 * cnt2 + cnt1 * cnt3 + cnt2 * cnt3;
		}
};
int main(){
	DS_Diem x;
	x.nhap();
	x.xuat();
	x.Dgk();
	x.Kc_x();
	x.Sol();
}
