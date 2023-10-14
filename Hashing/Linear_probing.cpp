#include <iostream>
using namespace std;

class Hash_table
{
private:
    int table_size = 10;
    int *arr = new int[table_size];

public:
    Hash_table()
    {
        for (int i = 0; i < table_size; i++)
        {
            arr[i] = 0;
        }
    }

    int hash(int key)
    {
        return key % table_size;
    }

    void insert(int key)
    {
        int index = hash(key);
        int original_index = index;
        int i = 0;

        while (arr[((index + i) % table_size)] != 0)
        {
            i++;
            if (((index + i) % table_size) == original_index)
            {
                cout << "Hash Table is full..!" << endl;
                return;
                break;
            }
        }
        arr[(index + i) % table_size] = key;
    }


void display()
{
    for (int i = 0; i < table_size; i++)
    {
        cout << "Row " << i << ": " << arr[i] << " ";
        cout << endl;
    }
}

};

int main()
{
    Hash_table h;
    h.insert(1);
    h.insert(3);

    h.insert(12);
    h.insert(32);
    h.insert(22);
    h.insert(2);
    h.insert(42);

    h.display();
}