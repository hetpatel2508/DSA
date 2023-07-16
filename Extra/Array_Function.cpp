#include<iostream>
using namespace std;

void dispaly(int a[5])
{
for(int i=0;i<5;i++)
{
    cout<<a[i]<<"  ";
}
}

int main()
{
    int b[5]={1,2,3,4,5};
    dispaly(b);
}