#include <iostream>
using namespace std;

struct array
{
int a[25];
int len;
};

void diffrence_array(struct array *arr1,struct array *arr2)
{

for(int i=0;i<arr1->len;i++)
{
    int k=arr2->len;
    for(int j=0;j<arr2->len;j++)
    {
        if(arr1->a[i]==arr2->a[j])
        {
            k--;
        }
    }
    if(k==arr2->len)
    {
        cout<<arr1->a[i]<<"  ";
    }
}

}

int main()
{
array arr1={{1,2,3,4,5},5};
array arr2={{6,2,7,4,8},5};

cout<<"After Union of two set: "<<endl;
diffrence_array(&arr1,&arr2);

}