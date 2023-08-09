#include<iostream>
using namespace std;

void display1(int num)
{
    if(num>0)
    {
        cout<<num<<"  ";
        display1(num-1);
    }
}

void display2(int num)
{
    if(num>0)
    {
        display2 (num-1);
        cout<<num<<"  ";
    }
}

int main()
{
display1(10);
cout<<endl<<endl;

display2(10);
}