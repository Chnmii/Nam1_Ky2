#include <bits/stdc++.h>
using namespace std;
#include <math.h>

int main()
{
    double a[10];
    for (int i=0; i<10; i++)
        cin >> a[i];
    for (int i=0; i<10; i++)
    {
        if (a[i]<=10)
        {
        	if (a[i] == (int)a[i])
        		cout << "A[" << i << "] = " << a[i] << endl;
        	else
        		cout << "A[" << i << "] = " << setprecision(1) << fixed << a[i] << endl;
		}
    }
}
