#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int arr_size;
    int front = -1;
    int rare = -1;
    int *arr;

public:
    Queue()
    {
        size = 0;
        arr = nullptr;
    }

    Queue(int a[], int size_of_a, int n)
    {
        size = n;
        arr_size = size_of_a;
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

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }

    void enqueue_or_push(int num)
    {
        if (isNotfull())
        {
            for (int i = rare + 1; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }
            rare++;
            arr[0] = num;
        }
        else
        {
            cout << "Full...!" << endl;
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
        if (front == -1)
        {
            enqueue_or_push(num);
        }
        else if ((rare + 1) % size != front)
        {
            rare = (rare + 1) % size;
            arr[rare] = num;
        }
        else
        {
            cout << "Queue is Full...!" << endl;
        }
    }

    void priority_delete()
    {
        int min = arr[0];
        int index;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                front = i;
            }
        }
        // arr[front]=0;
        for (int j = front; j < size; j++)
        {
            arr[j] = arr[j + 1];
            index = j;
        }
        arr[index] = NULL;
        rare--;
    }

    void priority_push()
    {
        for (int i = 0; i < arr_size; i++)
        {
            for (int j = 0; j < arr_size - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp;
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
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
    Queue q1(temp1, sizeof(temp1) / sizeof(temp1[0]), 7); // total num divide by single = size of an array
    q1.display();

    q1.enqueue_circular_queue(69);
    q1.enqueue_circular_queue(71);
    q1.enqueue_circular_queue(73);
    q1.display();

    q1.dequeue_or_pop();
    q1.dequeue_or_pop();
    q1.dequeue_or_pop();
    q1.display();

    q1.enqueue_circular_queue(7);
    q1.enqueue_circular_queue(9);
    q1.display();

    q1.priority_delete();
    q1.display();

    int temp2[] = {9, 8, 2, 1, 6, 7};
    Queue q2(temp2, sizeof(temp2) / sizeof(temp2[0]), 6);
    q2.display();
    q2.priority_delete();
    q2.display();
    q2.enqueue_or_push(69);
    q2.display();
    q2.enqueue_or_push(69);
    q2.display();

    int temp3[] = {9, 8, 2, 1, 6, 7};
    Queue q3(temp3, sizeof(temp3) / sizeof(temp3[0]), 6);
    q3.display();
    q3.priority_push();
    q3.display();
    q3.dequeue_or_pop();
    q3.display();
    q3.dequeue_or_pop();
    q3.display();
    q3.enqueue_circular_queue(69);
    q3.display();
}