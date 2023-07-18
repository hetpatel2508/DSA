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


void sort(struct array *arr)
{
    for(int i=0;i<arr->len;i++)
    {
        for(int j=0;j<arr->len-1;j++)
        {
            if(arr->a[j]>arr->a[j+1])
            {
                swap(&arr->a[j],&arr->a[j+1]);
            }
        }
    }
}



int binary_search(struct array *arr,int key)
{
    int low=0;
    int high=arr->len;

    for(int i=0;i<arr->len;i++)
    {
        int mid=(low+high)/2;
        
        if(key<arr->a[mid])
        {high=mid-1;}
    
        if(key>arr->a[mid])
        {low=mid+1;}
    
        if(key==arr->a[mid])
        {
        return mid;
        break;
        }
    }
    return -1;
}



int main()
{
array arr={{5,3,1,2,4},5};

display(&arr);

cout<<"After Sorting: "<<endl;
sort(&arr);
display(&arr);

int key=3;
cout<<"Binary Search Operation for "<<key<<" :"<<endl;
cout<<"Index= "<<binary_search(&arr,key)<<endl;


int key1=6;
cout<<"Binary Search Operation for "<<key1<<" :"<<endl;
cout<<"Index= "<<binary_search(&arr,key1);

}