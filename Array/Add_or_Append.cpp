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

void append(struct array *arr,int value)
{
    // arr->a[arr->len++]=value;
            //or

    arr->a[arr->len]=value;
    arr->len++;
}

int main()
{
array arr={{1,2,3,4,5},5};
display(&arr);
cout<<endl<<endl;
append(&arr,6);
append(&arr,7);
append(&arr,8);
append(&arr,9);
display(&arr);
}