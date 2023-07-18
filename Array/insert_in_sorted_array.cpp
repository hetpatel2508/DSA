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

void insert_in_sorted_array(struct array *arr,int num)
{
    arr->len++;
    arr->a[arr->len-1]=num;

    for(int i=0;i<arr->len;i++)
    {
        for(int j=0;j<arr->len-1;j++)
        {
            if(arr->a[j]>arr->a[j+1])
            {
                swap(arr->a[j],arr->a[j+1]);
            }
        }
    }
}

int main()
{
array arr={{1,2,3,5,6},5};
display(&arr);

insert_in_sorted_array(&arr,4);
display(&arr);
}