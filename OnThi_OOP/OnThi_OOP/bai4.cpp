#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,x1,x2;
	printf("nhap so a =");scanf("%f",&a);
    printf("nhap so b =");scanf("%f",&b);
    printf("nhap so c =");scanf("%f",&c);
    
    float delta=b*b-4*a*c;
    if(delta<0)
    printf("phuong trinh vo nghiem");
    else
    if(delta==0)
    printf("phuong trinh co nghiem kep %f",-b/(2*a));
    else
    if(delta>0)
    {
    	x1=(float)(-b + sqrt(delta))/(2*a);
    	x2=(float)(-b - sqrt(delta))/(2*a);
    	printf("phuong trinh co hai nghiem x1=%f,x2=%f",x1,x2);
    	
	}
}


