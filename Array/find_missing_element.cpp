#include <iostream>
using namespace std;

struct array
{
int a[25];
int len;
};

void check_element(struct array arr)
{
int low=arr.a[0];

    for(int i=0;i<arr.len;i++)
    {
        if((arr.a[i]-i)!=low)
        {
            cout<<"Missing Element=  "<<arr.a[i]-1<<endl;
            low++;
        }
    }
}

int main()
{
array arr={{1,2,3,5,6,8,9,10,12,13,14},11};
check_element(arr);

}