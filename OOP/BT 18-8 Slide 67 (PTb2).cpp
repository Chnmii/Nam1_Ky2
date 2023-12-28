#include <bits/stdc++.h>
using namespace std;

void giaiptb2(int a, int b, int c)
{
	int del;
    float x1, x2;
    del = b*b-4*a*c;
    if (a==0)
	{
        if (b==0)
		{
            if (c==0)
        		cout << "Pt co vo so nghiem" << endl;
            else cout << "Pt vo nghiem" << endl;
        }
      	else 
            if (c!=0)
			{
                x1 = -c/b;
                cout << "Pt co nghiem x = " << fixed << setprecision(2) << x1 << endl;
            }
            else
                cout << "Pt co nghiem x = 0";
    }
    else
    {
    	if (del<0)
 	       cout << "Pt vo nghiem" << endl;
    	else if (del>0)
			{
	        	x1 = (-b+sqrt(del))/(2*a);
    	    	x2 = (-b-sqrt(del))/(2*a);
	        	cout << "Pt co 2 nghiem x1 = " << fixed << setprecision(2) << x1 << " va x2 = " << x2 << endl;                      
    		}
        else
		{
        	x1 = -b/(2*a);
        	cout << "Pt co nghiem duy nhat x = " << fixed << setprecision(2) << x1 << endl;          
        }
    }
}

main()
{
	int a, b, c;
	cout << "Moi ban nhap cac he so cua pt ax^2+bx+c=0:\n";
	cout << "a = "; cin >> a;	
	cout << "b = "; cin >> b;	
	cout << "c = "; cin >> c;	
	giaiptb2(a,b,c);
	
	return 0;
}
