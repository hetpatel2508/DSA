#include <iostream>
using namespace std;

struct array
{
int a[25];
int len;
};


void check_same_element(struct array arr)
{
    for(int i=0;i<arr.len-1;i++)
    {
        if(arr.a[i]==arr.a[i+1])
        {
            cout<<"Matching Element=  "<<arr.a[i]<<endl;
        }
    }
}

int main()
{
array arr={{1,2,4,4,5,6,7,7,9,10},10};
check_same_element(arr);
}