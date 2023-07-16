#include<iostream>
using namespace std;

void Pass_by_value(int x,int y)
{
int temp;
temp=x;
x=y;
y=temp;
}

void Pass_by_reference(int &x,int &y)
{
int temp;
temp=x;
x=y;
y=temp;
}

void Pass_by_address(int *x,int *y)
{
int temp;
temp=*x;
*x=*y;
*y=temp;
}

int main()
{
    // Pass By Value
    
    int a=2,b=3;
    Pass_by_value(a,b);
    cout<<a<<"  "<<b<<endl;     //value will not be swapped


    // Pass By reference

    int e=6,f=7;
    Pass_by_reference(e,f);
    cout<<e<<"  "<<f<<endl;     //value will be swapped

    
    
    // Pass By Address

    int c=4,d=5;
    Pass_by_address(&c,&d);
    cout<<c<<"  "<<d<<endl;  //values wil be swapped 
}