#include <iostream>
using namespace std;

struct array
{
int a[25];
int len;
};

void intersection_array(struct array *arr1,struct array *arr2)
{

for(int i=0;i<arr2->len;i++)
{
    for(int j=0;j<arr1->len;j++)
    {
        if(arr2->a[i]==arr1->a[j])
        {
            cout<<arr1->a[j]<<"  ";
        }
    }
}

}

int main()
{
array arr1={{1,2,3,4,5},5};
array arr2={{6,2,7,4,3},5};

cout<<"After Union of two set: "<<endl;
intersection_array(&arr1,&arr2);

}