#include<iostream>
using namespace std;

int add1(int num)
{

if(num>0)
return num+add1(num-1);

}

int y=0;

double factorial(int num)
{
    if(num>0)
    {
        y++;
        return factorial(num-1)*num;
    }
    return 1;
}


double power(int m , int n)
{
    if(n>0)
    {
        return power(m,n-1)*m;
    }
    else
    {
        return 1;
    }
}

double tyler(double x,double n)
{
    if(n>0)
    {
        return (tyler(x,n-1)+(power(x,n)/factorial(n)));
    }
    else 
    {
        return 1;
    }
}

double ty(int x,int n)
{
    static double e;
    static double p=1;
    static double  f=1;
    if(n>0)
    {
        e=ty(x,n-1);
        p=p*x;
        f=f*n;
        return e+(p/f);
    }
    else 
    {
        return 1;
    }
}

int main()
{
    cout<<"Additision= "<<add1(4)<<endl;

    cout<<"Additision= "<<factorial(4)<<endl;

    cout<<"Power=  "<<power(2,4)<<endl;

    cout<<"Tyler Series= "<<tyler(2,5)<<endl;
    
    cout<<"Tyler Series= "<<ty(2,5)<<endl;

}