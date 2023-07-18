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

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void right_shift(struct array *arr)
{
    for(int i=arr->len-1;i>0;i--)
    {
        arr->a[i]=arr->a[i-1];
    }
    arr->a[0]=0;
}

int main()
{
array arr={{1,2,3,4,5,6},6};
display(&arr);

right_shift(&arr);
display(&arr);
}