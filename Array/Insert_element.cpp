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
}

void insert(struct array *arr,int index,int value)
{
    arr->len++;

    for(int i=(arr->len-1);i>index;i--)
    {
        arr->a[i]= arr->a[i-1]; 
    }
    arr->a[index]=value;
}

int main()
{
array arr={{1,2,3,4,5},5};
display(&arr);
cout<<endl<<endl;
insert(&arr,2,11);
// insert(&arr,3,13);
display(&arr);
}