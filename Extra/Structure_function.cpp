#include<iostream>
using namespace std;


struct rect
{
int len;
int bre;
};

int area(rect temp)
{
return (temp.len)*(temp.bre);
}

int main()
{
rect r1{5,6};
cout<<"Area= "<<area(r1);
}