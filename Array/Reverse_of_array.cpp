#include <iostream>
using namespace std;

struct array
{
int a[25];
int len;
};

void display(struct array *arr)
{
    for(int i=0;i<(arr->len);i++)
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

void reverse_of_array(struct array *arr)
{
    for(int i=0;i<arr->len/2;i++)
    {
        int j=arr->len-1-i;
        swap(arr->a[i],arr->a[j]);
    }
}

int main()
{
array arr={{1,2,3,4,5,6},6};
display(&arr);

reverse_of_array(&arr);
display(&arr);

}