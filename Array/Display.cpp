#include <iostream>
using namespace std;

struct array
{
int a[20];
int len;
};

void display(struct array *arr)
{
    for(int i=0;i<(arr->len);i++)
    {
        cout<<arr->a[i]<<"  ";
    }
}

int main()
{
array arr={{1,2,3,4,5},5};
display(&arr);
}