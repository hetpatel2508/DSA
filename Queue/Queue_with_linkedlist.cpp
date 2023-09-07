#include <iostream>
using namespace std;

class queue
{
private:
    int data;
    int size;
    queue *head;
    queue *next_node;
    queue *front;
    queue *rare;

public:
    int fr()
    {
        return front->data;
    }
    int rr()
    {
        return rare->data;
    }

    queue()
    {
        data = 0;
        head = nullptr;
        front = nullptr;
        rare = nullptr;
        next_node = nullptr;
    }
    queue(int a[], int size_of_a, int n)
    {
        size = n;
        queue *t = new queue;
        t->data = 0;
        t->next_node = nullptr;
        head = t;
        front = head;
        rare = head;

        queue *use = head;

        for (int i = 1; i < size; i++)
        {
            queue *temp = new queue;
            temp->data = 0;
            temp->next_node = nullptr;
            use->next_node = temp;
            use = temp;
        }

        use->next_node = head;

        for (int j = 0; j < size_of_a; j++)
        {

            rare = rare->next_node;
            rare->data = a[j];
        }
    }

    void display()
    {
        queue *p = head;

        while (p->next_node != head)
        {
            cout << p->data << " ";
            p = p->next_node;
        }
        cout << p->data << " "; // for last element
        cout << endl;
    }

    void enqueue_or_push(int num)
    {
        if(rare->next_node!=front)
        {
            rare=rare->next_node;
            rare->data=num;
        }
        else
        {
            cout<<"Queue is Full";
        }
    }

    void dequeue_or_pop()
    {
        front=front->next_node;
        front->data=0;
    }
};

int main()
{
    int temp1[] = {2, 4, 6};
    queue q1(temp1, sizeof(temp1) / sizeof(temp1[0]), 6);
    q1.display();
    // cout << q1.fr()<<"  "<<q1.rr()<<endl;
    q1.enqueue_or_push(7);
    q1.enqueue_or_push(9);
    q1.display();

    q1.dequeue_or_pop();
    q1.display();
    
    q1.enqueue_or_push(69);
    q1.display();
}