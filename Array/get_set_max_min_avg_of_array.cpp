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

int get(struct array *arr,int index)
{
    return arr->a[index];
}

void set(struct array *arr,int index,int value)
{
    arr->a[index]=value;
}

int maxx(struct array *arr)
{
    int maximum=arr->a[0];
    for(int i=1;i<arr->len;i++)
    {
        if(arr->a[i]>maximum)
        {
            maximum=arr->a[i];
        }
    }
    return maximum;
}

int minn(struct array *arr)
{
    int minimum=arr->a[0];
    for(int i=1;i<arr->len;i++)
    {
        if(arr->a[i]<minimum)
        {
            minimum=arr->a[i];
        }
    }
    return minimum;
}

int summ(struct array *arr)
{
    int add=0;
    for(int i=0;i<arr->len;i++)
    {
        add=add+arr->a[i];
    }
    return add;
}

int average(struct array *arr)
{
    int add=0;
    for(int i=0;i<arr->len;i++)
    {
        add=add+arr->a[i];
    }
    return add/arr->len;
}


int main()
{
array arr={{5,3,1,2,4},5};

cout<<get(&arr,2)<<endl;

set(&arr,4,6);

cout<<"Maximum= "<<maxx(&arr)<<endl;

cout<<"Minimum= "<<minn(&arr)<<endl;

cout<<"Average= "<<average(&arr)<<endl;

}