#include<iostream>
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

int linear_search(struct array *arr,int value)
{
    for(int index=0;index<arr->len;index++)
    {
        if(arr->a[index]==value)
        {
            return index;
        }
    }
    return -1;
}

int main()
{
array arr={{1,2,3,4,5},5};
display(&arr);

cout<<"Key= 3"<<"   "<<"index= "<<linear_search(&arr,3)<<endl<<endl;
cout<<"Key= 6"<<"   "<<"index= "<<linear_search(&arr,6)<<endl<<endl;
display(&arr);

}