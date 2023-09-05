#include <iostream>
using namespace std;

class LINKEDLIST
{
private:
    int data;
    LINKEDLIST *next_node;

    int size;
    LINKEDLIST *head;
    LINKEDLIST *top;

public:
    LINKEDLIST()
    {
        data = 0;
        next_node = nullptr;
    }

    LINKEDLIST(int a[], int n)
    {
        size = n;
        LINKEDLIST *temp = new LINKEDLIST;
        temp->data = a[0];
        temp->next_node = nullptr;
        head = temp;
        LINKEDLIST *use = head;

        for (int i = 1; i < n; i++)
        {
            LINKEDLIST *t = new LINKEDLIST;
            t->data = a[i];
            t->next_node = nullptr;

            use->next_node = t;
            use = t;
            top = use;
        }
    }

    void display()
    {
        LINKEDLIST *use = head;
        while (use != nullptr)
        {
            cout << use->data << " ";
            use = use->next_node;
        }
        cout << endl;
    }

    void push(int num)
    {
        LINKEDLIST *use = head;
        while (use->next_node != 0)
        {
            use = use->next_node;
        }
        LINKEDLIST *temp = new LINKEDLIST;
        temp->data = num;
        temp->next_node = nullptr;

        use->next_node = temp;
        top = temp;
    }

    void pop()
    {
        LINKEDLIST *use = head;
        while (use->next_node->next_node != 0)
        {
            use = use->next_node;
        }
        use->next_node = nullptr;
        top = use;
    }
};

int main()
{
    int a2[] = {25, 8, 2003};
    LINKEDLIST l1(a2, 3);
    l1.display();
    l1.push(45);
    l1.display();
    l1.pop();
    l1.display();
}