#include<iostream>
#include<conio.h>
using namespace std;
class A
{
    public:
        virtual void show()
        {
            cout<<"\nTruong A:";
        }
        void display()
        {
            cout<<"\nLop A:" ;
        }
};
 
class kethua:public A
{
    public:
        void display()
        {
            cout<<"\nLop B:";
        }
        void show()
        {
            cout<<"\nTruong B:";
        }
};
 
int main()
{   
   A obj1;
   A *p;
   cout<<"\nP tro toi A:"  ;
   p=&obj1;
   p->display();
   p->show();
 
   cout<<"\n\nP tro toi B:";
   kethua obj2;
   p=&obj2;
   p->display();
   p->show();
   return 0;
}
