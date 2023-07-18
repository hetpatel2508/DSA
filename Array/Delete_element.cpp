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

void delete_element(struct array *arr,int index)
{
    for(int i=index;i<((arr->len)-1);i++)
    {
        arr->a[i]=arr->a[i+1];
    }
    arr->a[arr->len-1]=0;
    arr->len--;
}

int main()
{
array arr={{1,2,3,4,5},5};
display(&arr);
cout<<endl<<endl;
delete_element(&arr,2);
display(&arr);
}