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

    void set(int a[], int n)
    {
        // size = n;

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
    }

    void display()
    {
        linkedlist *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next_node;
        }
        cout << endl;
    }

    void insert(int index, int value)
    {
        linkedlist *use = new linkedlist;
        use->data = value;

        if (index != 0)
        {
            linkedlist *current = head;
            int n = 1;

            while (current != nullptr)
            {
                if (n == index)
                {
                    use->next_node = current->next_node;
                    current->next_node = use;
                    size++;
                }
                n++;
                current = current->next_node;
            }
        }
        else
        {
            size++;
            use->next_node = head;
            head = use;
        }
    }

    void sort_linkedlist()
    {
        for (int i = 0; i < 10; i++)
        {
            linkedlist *use = head;
            while (use != NULL && use->next_node != NULL)
            {
                if (use->data > use->next_node->data)
                {
                    int temp;
                    temp = use->data;
                    use->data = use->next_node->data;
                    use->next_node->data = temp;
                }
                use = use->next_node;
            }
        }
    }

    void insert_sorted(int number)
    {
        linkedlist *use = head;
        linkedlist *temp = new linkedlist;

        while (use != NULL)
        {
            if (use->next_node->data >= number)
            {
                temp->data = number;
                temp->next_node = use->next_node;
                use->next_node = temp;
                size++;
                break;
            }
            use = use->next_node;
        }
    }

    void delete_node(int index)
    {
        linkedlist *use = head;
        int count = 1;
        if (index == 1)
        {
            size--;
            head = head->next_node;
        }
        else
        {
            while (use != NULL)
            {
                if (count == index - 1)
                {
                    size--;
                    use->next_node = use->next_node->next_node;
                    use = use->next_node;
                    use = nullptr;
                    break;
                }
                count++;
                use = use->next_node;
            }
        }
    }

    void check_sort()
    {
        linkedlist *use = head;
        int temp = 0;
        while (use != NULL)
        {
            if (use->data < temp)
            {
                cout << "Not Sorted...!" << endl;
            }
            temp = use->data;
            use = use->next_node;
        }
        cout << "Sorted....!" << endl;
    }

    void duplicate()
    {
        linkedlist *use = head;
        while (use != NULL && use->next_node != NULL)
        {
            if (use->data == use->next_node->data)
            {
                use->next_node = use->next_node->next_node;
                size--;
            }
            else
            {
                use = use->next_node;
            }
        }
    }

    void reverse_by_array()
    {
        linkedlist *use = head;
        int *a = new int[size];
        int i = 0;
        while (use != NULL)
        {
            a[i] = use->data;
            i++;
            use = use->next_node;
        }

        linkedlist *temp = head;
        int j = size - 1;

        while (temp != 0)
        {
            temp->data = a[j];
            j--;
            temp = temp->next_node;
        }
    }

    void reverse_by_sliding_pointer()
    {
        linkedlist *p = NULL;
        linkedlist *q = NULL;
        linkedlist *r = head;

        while (r != 0)
        {
            p = q;
            q = r;
            r = r->next_node;
            q->next_node = p;
        }
        head = q;
    }

    void concatenate(linkedlist *second)
    {

        linkedlist *first = head;
        while (first->next_node != nullptr)
        {
            first = first->next_node;
        }

        linkedlist *use = second->head;
        while (use != nullptr)
        {
            linkedlist *temp = new linkedlist;
            temp->data = use->data;
            temp->next_node = nullptr;

            first->next_node = temp;
            first = first->next_node;
            use = use->next_node;
            size++;
        }
    }

};

int main()
{
    linkedlist myList;
    int arr[] = {6, 8, 8, 9, 9, 9, 7, 3};

    myList.set(arr, 8);
    myList.display();

    myList.insert(0, 69);
    myList.display();

    myList.insert(2, 17);
    myList.display();

    myList.sort_linkedlist();
    myList.display();

    myList.check_sort();

    myList.insert_sorted(6);
    myList.display();

    myList.delete_node(1);
    myList.display();

    myList.duplicate();
    myList.display();

    myList.reverse_by_sliding_pointer();
    myList.display();

    linkedlist myList2;
    int arr2[] = {1, 2, 3};

    myList2.set(arr2, 3);
    myList2.display();

    myList.concatenate(&myList2);
    myList.display();
}