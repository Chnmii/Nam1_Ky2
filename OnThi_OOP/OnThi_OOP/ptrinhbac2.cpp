#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{float a,b,c;
scanf("%d%d%d",&a,&b,&c);
 float denta = b*b-4*a*c;
  if (denta <0 )
  {
   printf(" phuong trinh vo nghiem");
  }
  if (denta == 0)
  { 
  float x= -b/(2*a);
  printf(" phuong trinh co nghiem kep la: %0.f",x);
   } 
   if (denta >0)
   { float x1,x2;
   x1= (-b+sqrt(denta))/(2*a);
   x2= (-b-sqrt(denta))/(2*a);
   printf ( "phuong trinh co 2 nghiem la: %1.0f %2.0f",x1,x2);
   }
}


