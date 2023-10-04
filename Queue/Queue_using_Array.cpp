#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front = -1;
    int rare = -1;
    int *arr;

public:
    Queue()
    {
        size = 0;
        arr = nullptr;
    }

    Queue(int a[], int size_of_a,int n)
    {
        size = n;
        arr = new int[size];
        for (int i = 0; i < size_of_a; i++)
        {
            arr[i] = a[i];
            rare++;
        }
    }

    bool isNotfull()
    {
        if (rare == size - 1)
        {
            return false;
        }
        return true;
    }

    bool isNotEmpty()
    {
        if (rare == front)
        {
            return false;
        }
        return true;
    }

    void display()
    {
        if (isNotEmpty())
        {
            for (int i = 0; i <size; i++)
            {
                cout << arr[i] << "  ";
            }
            cout << endl;
        }
        else
        {
            cout << "Empty Array" << endl;
        }
    }

    void enqueue_or_push(int num)
    {
        if (isNotfull())
        {
            // for (int i = rare + 1; i > 0; i--)
            // {
            //     arr[i] = arr[i - 1];
            // }
            // rare++;
            // arr[0] = num;
            rare++;
            arr[rare]=num;
        }
        else
        {
            cout<<"Full...!"<<endl;
        }
    }

    void dequeue_or_pop()
    {
        if (isNotEmpty())
        {
            front++;
            arr[front] = NULL;
        }
    }

    void enqueue_circular_queue(int num)
    {
        // if(front==-1)
        if(front!=rare)
        {
            rare=(rare+1)%size;
            arr[rare]=num;
        }
        else
        {
            cout << "Queue is Full...!" << endl;
        }
    }

    int fr()
    {
        return front;
    }
    int rr()
    {
        return rare;
    }
};

int main()
{
    Queue q;
    q.display();

    int temp1[] = {1, 2, 3, 4};
    Queue q1(temp1, sizeof(temp1)/sizeof(temp1[0]),7); // total num divide by single = size of an array
    q1.display();

    q1.enqueue_or_push(69);
    q1.enqueue_or_push(71);
    q1.enqueue_or_push(73);
    q1.display();

    q1.dequeue_or_pop();
    q1.dequeue_or_pop();
    q1.dequeue_or_pop();
    q1.display();

    q1.enqueue_circular_queue(7);
    q1.enqueue_circular_queue(9);
    q1.display();
}