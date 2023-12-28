#include <bits/stdc++.h>
using namespace std;

int giaiptb1(float a, float b, float *x)
{ 	int k;
	if(a!=0) 
	{	*x=-b/a; 
		k=1;
	}
	else if(b!=0) 
			k=0;
		 else 
		 	k=2;
		 	
	return k;
}

int main()
{	
	float a, b, x;
	cout << "Moi ban nhap cac he so cua pt ax+b=0:\n";
	cout << "a = "; cin >> a;	
	cout << "b = "; cin >> b;	
	
	if (giaiptb1(a,b,&x)==1)
	{
		cout << "Pt co nghiem x= " << setprecision(2) << fixed << x << endl;
	}
	else 
	{
		if (giaiptb1(a,b,&x)==0)
			cout << "Pt vo nghiem" << endl;
		else
			cout << "Pt co vo so nghiem" << endl;
	}
	
	return 0;
}
