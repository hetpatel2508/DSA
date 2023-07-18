#include <iostream>
using namespace std;

int main()
{
int a[5]={5,3,1,2,4};

for(int i=0;i<5;i++)
{

    for(int j=0;j<5;j++)
    {
        if(a[j]>a[j+1])
        {
            swap(a[j],a[j+1]);
        }
    }

}

    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<"  ";
    }


}