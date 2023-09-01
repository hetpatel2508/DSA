#include <iostream>
using namespace std;

class linkedlist
{
public:
    int data;
    linkedlist *next_node;
    linkedlist *prev;
    int size = 1;

    linkedlist *head;
    linkedlist *m;

    linkedlist()
    {
        head = nullptr;
        m = nullptr;
    }

    void circular_set(int a[], int n)
    {
        // size = n;

        linkedlist *p = head;
        linkedlist *temp = new linkedlist;
        temp->data = a[0];
        temp->next_node = nullptr;

        head = temp;
        m = head;

        for (int i = 1; i < n; i++)
        {
            linkedlist *t = new linkedlist;
            t->data = a[i];
            t->next_node = nullptr;

            size++;
            m->next_node = t;
            m = t;
        }
        m->next_node = head;
    }

    void circular()
    {
        linkedlist *p = head;

        while (p->next_node != head)
        {
            cout << p->data << " ";
            p = p->next_node;
        }
        cout << p->data << " "; // for last element
        cout << endl;
    }

    void circular_insert(int index, int num)
    {

        if (index == 0)
        {
            linkedlist *use = new linkedlist;
            use->data = num;
            use->next_node = head;

            linkedlist *temp = head;
            while (temp->next_node != head)
            {
                temp = temp->next_node;
            }
            temp->next_node = use;
            head = use;
            size++;
        }
        else
        {
            linkedlist *temp = head;
            // use->next_node=head;
            for (int i = 1; i < index; i++)
            {
                temp = temp->next_node;
            }

            linkedlist *use = new linkedlist;
            use->data = num;
            use->next_node = temp->next_node;
            temp->next_node = use;
            size++;
        }
    }

    void circular_delete_node(int index)
    {
        if (index == 1)
        {
            head = head->next_node;
            size--;
        }
        else
        {
            linkedlist *p = head;
            linkedlist *q = NULL;
            int temp = 2;

            while (p->next_node != head)
            {
                if (temp == index)
                {
                    p->next_node = p->next_node->next_node;
                }
                temp++;
                p = p->next_node;
            }
        }
    }
};

int main()
{
    linkedlist myList3;
    int arr3[] = {1, 2, 3, 4, 5};

    myList3.circular_set(arr3, 5);
    myList3.circular();

    myList3.circular_insert(2, 69);
    myList3.circular();

    myList3.circular_delete_node(3);
    myList3.circular();
}