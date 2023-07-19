#include <iostream>
using namespace std;

struct array
{
int a[25];
int len;
};


void check_same_element(struct array arr)
{
    for(int j=0;j<arr.len;j++)
    {
    int k=0;
       for(int i=j;i<arr.len;i++)
        {
            if(arr.a[j]==arr.a[i])
            {
                k++;
            }
        }
        if(k>1)
        {
                cout<<"Matching Element is "<<arr.a[j]<<" repeated "<<k<<" times"<<endl;
        }
    }
}

int main()
{
array arr={{3,7,7,10,13,3,10,11},8};
check_same_element(arr);
}