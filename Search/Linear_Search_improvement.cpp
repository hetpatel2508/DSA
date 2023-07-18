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

int linear_search_transpose(struct array *arr,int value)
{
    for(int index=0;index<arr->len;index++)
    {
        if(arr->a[index]==value)
        {
            swap(arr->a[index],arr->a[index-1]);
            return index;
        }
    }
    return -1;
}


int linear_search_move_to_first(struct array *arr,int value)
{
    for(int index=0;index<arr->len;index++)
    {
        if(arr->a[index]==value)
        {
            swap(arr->a[index],arr->a[0]);
            return index;
        }
    }
    return -1;
}

int main()
{
array arr={{1,2,3,4,5},5};
display(&arr);

cout<<"Key= 4"<<"   "<<"index= "<<linear_search_transpose(&arr,4)<<endl<<endl;
display(&arr);
cout<<"Key= 5"<<"   "<<"index= "<<linear_search_move_to_first(&arr,5)<<endl<<endl;
display(&arr);

}