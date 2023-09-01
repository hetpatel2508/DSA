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

    void doubly_linkedlist(int A[], int n)
    {
        size = n;

        linkedlist *t = new linkedlist;
        t->data = A[0];
        t->prev = nullptr;
        t->next_node = nullptr;

        head = t;
        linkedlist *p = head;

        for (int i = 1; i < n; i++)
        {
            linkedlist *use = new linkedlist;
            use->data = A[i];
            use->prev = p;
            use->next_node = nullptr;

            p->next_node = use;

            p = p->next_node;
        }
    }

    void doubly_display()
    {
        linkedlist *use = head;

        while (use != 0)
        {
            cout << use->data << "  ";
            use = use->next_node;
        }
        cout << endl;
    }

    void doubly_insert(int index, int value)
    {
        if (index == 0)
        {
            size++;

            linkedlist *temp = new linkedlist;
            temp->prev = nullptr;
            temp->data = value;
            temp->next_node = head;
            head = temp;
        }

        else if(index==size)
        {
            size++;
            linkedlist *use=head;

            for(int i=1;i<index;i++)
            {
                use=use->next_node;
            }


            linkedlist *temp = new linkedlist;
            temp->prev = use;
            temp->data = value;
            temp->next_node = nullptr;
            use->next_node=temp;
        }

        else
        {
            linkedlist *use = head;
            size++;

            for (int i = 1; i <= index; i++)
            {
                use = use->next_node;
            }
            linkedlist *temp = new linkedlist;
            temp->data = value;
            temp->next_node = use;
            temp->prev = use->prev;
            use->prev->next_node = temp;
        }
    }

    void doubly_delete(int index)
    {
        if(index==1)
        {
            head=head->next_node;
            head->prev=nullptr;
        }
        else if(index==size)
        {
            linkedlist *p=nullptr;
            linkedlist *q=head;
            for(int i=1;i<index;i++)
            {
                p=q;
                q=q->next_node;
            }
            p->next_node=nullptr;
            delete q;
        }
        else
        {
            linkedlist *p=nullptr;
            linkedlist *q=head;
            for(int i=1;i<index;i++)
            {
                p=q;
                q=q->next_node;
            }
            p->next_node=q->next_node;
            q->next_node->prev=p;
        }
    }

    void doubly_reverse()
    {
        linkedlist *p=nullptr;
        linkedlist *q=head;

        while(q!=NULL)
        {
            q->prev=q->next_node;
            q->next_node=p;

            p=q;
            q=q->prev;  //karan ke prev = next :>
        }
        head=p;
    }


};

int main()
{
    linkedlist myList4;
    int arr4[] = {25, 8, 2003};
    myList4.doubly_linkedlist(arr4, 3);
    myList4.doubly_display();
    myList4.doubly_insert(1, 69);
    myList4.doubly_display();

    myList4.doubly_delete(2);
    myList4.doubly_display();

    myList4.doubly_reverse();
    myList4.doubly_display();
}