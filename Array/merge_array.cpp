#include <iostream>
using namespace std;

struct array
{
int a[25];
int len;
};

void display(struct array *arr)
{
    for(int i=0;i<arr->len;i++)
    {
        cout<<arr->a[i]<<"  ";
    }

    cout<<endl<<endl;
}

void merge(struct array *arr,struct array *arr1)
{
    int temp=arr->len;
    int j=0;
    arr->len=arr->len+arr1->len;
    for(int i=temp;i<arr->len;i++)
    {
        arr->a[i]=arr1->a[j];
        j++;
    }
}

int main()
{
array arr1={{1,2,3,4,5},5};
array arr2={{6,7,8,9,10},5};
array arr={{},0};

merge(&arr,&arr1);
display(&arr);

merge(&arr,&arr2);
display(&arr);
cout<<arr.len;
}