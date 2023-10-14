#include <iostream>
using namespace std;

class linkedlist
{
private:
    int data;
    linkedlist *next_node;
    int size;
    linkedlist *head;

public:
    linkedlist()
    {
        next_node = nullptr;
        head = nullptr;
        size = 0;
    }

    linkedlist(int a[], int s)
    {
        size = s;
        linkedlist *temp = new linkedlist;
        temp->data = a[0];
        temp->next_node = nullptr;
        head = temp;

        linkedlist *use = head;

        for (int i = 1; i < size; i++)
        {
            linkedlist *t = new linkedlist;
            t->data = a[i];
            t->next_node = nullptr;

            use->next_node = t;
            use = t;
        }
    }

    void display()
    {
        linkedlist *use = head;

        if (use != nullptr)
        {
            while (use != nullptr)
            {
                cout << use->data << " ";
                use = use->next_node;
            }
        }
        else{
            cout<<"0";
        }
        cout << endl;
    }

    void insert(int num, int index)
    {
        if (index == 0)
        {
            linkedlist *temp = new linkedlist;
            temp->data = num;
            temp->next_node = head;
            head = temp;
            size++;
        }

        else
        {
            linkedlist *use = head;
            if (index > size)
            {
                size++;
                while (use->next_node != nullptr)
                {
                    use = use->next_node;
                }
                linkedlist *temp = new linkedlist;
                temp->data = num;
                temp->next_node = nullptr;
                use->next_node = temp;
            }
            else
            {
                for (int i = 1; i < index; i++)
                {
                    use = use->next_node;
                }
                linkedlist *temp = new linkedlist;
                temp->data = num;
                temp->next_node = use->next_node;
                use->next_node = temp;
                size++;
            }
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

    void insert_in_sorted(int num)
    {
        linkedlist *use = head;
        if (use == nullptr)
        {
            linkedlist *temp = new linkedlist;
            temp->data = num;
            temp->next_node = nullptr;
            head = temp;
        }
        else
        {
            size++;
            while (use->data < num && use->next_node != nullptr)
            {
                use = use->next_node;
            }

            if (use->next_node == nullptr)
            {
                linkedlist *temp = new linkedlist;
                temp->data = num;
                temp->next_node = nullptr;

                use->next_node = temp;
            }
            else
            {
                int t = use->data;
                use->data = num;

                linkedlist *temp = new linkedlist;
                temp->data = t;
                temp->next_node = use->next_node;
                use->next_node = temp;
            }
        }
    }
};

class Hash_table
{
private:
    int table_size = 10;
    linkedlist *rows = new linkedlist[table_size];

public:
    int hashfunction(int key)
    {
        return key % table_size;
    }

    void insert(int key)
    {
        int index = hashfunction(key);
        rows[index].insert_in_sorted(key);
    }

    void display()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << "Row " << i << ":  ";
            rows[i].display();
        }
    }
};

int main()
{
    Hash_table h1;
    h1.insert(12);
    h1.insert(32);
    h1.insert(22);
    h1.insert(2);
    h1.insert(42);
    h1.insert(13);
    h1.insert(33);
    h1.insert(3);
    h1.insert(23);
    h1.insert(43);
    h1.insert(53);
    h1.insert(35);
    h1.insert(15);
    h1.insert(27);
    h1.insert(49);

    h1.display();

}