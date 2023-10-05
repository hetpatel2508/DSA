#include <iostream>
using namespace std;

class queue
{
private:
    int size;
    int *arr;
    int front = -1;
    int rare = -1;

public:
    queue()
    {
        arr = nullptr;
    }
    
    queue(int a[], int s)
    {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i]=a[i];
            rare++;
        }
    }

    void display()
    {
            for(int i=0;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;

    }

    void enqueue(int num)
    {
        if(rare==front)
        {
            cout<<"Queue Overflow"<<endl;
        }
        else
        {
            rare=(rare+1)%size;
            arr[rare]=num;
        }
    }

    void dequeue()
    {
        if(front==(rare+1%size))
        {
            cout<<"Queue Underflow";
        }
        else
        {
            front=(front+1)%size;
            arr[front]=0;
        }
    }
};

int main()
{
    int temp[]={1,2,3,4,5};
    queue q1(temp,sizeof(temp)/sizeof(temp[0]));
    q1.display();

    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.display();

    q1.enqueue(7);
    q1.display();

}