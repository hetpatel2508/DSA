#include<iostream>
using namespace std;

int fibonacci(int num)
{
    if(num<=1)
    {
        return num;
    }
    else
    {
        return fibonacci(num-2)+fibonacci(num-1);
    }
}


int main()
{
    cout<<"Febonacci Series= "<<fibonacci(7)<<endl;
}