#include <iostream>
using namespace std;

class sorting
{
private:
    int *arr;
    int size;

public:
    sorting()
    {
        arr = nullptr;
        size = 0;
    }
    sorting(int a[], int s)
    {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = a[i];
        }
    }

    int getsize()
    {
        return size;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void swap(int *a, int *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

    void Bubble_Sort()
    {

        for (int i = 0; i < size - 1; i++)
        {
            int temp = 0;
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(&arr[j], &arr[j + 1]);
                    temp++;
                }
            }
            if (temp == 0)
            {
                // cout << "Array is already sorted..!" << endl;
                break;
            }
        }
    }

};

int main()
{
    //  int temp1[]={1,2,3,4,5,6};
    // int temp1[] = {7, 2, 10, 1, 5, 3};
    int temp1[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    // int temp1[] = {6, 2, 4, 1, 5, 3};

    sorting s1(temp1, sizeof(temp1) / sizeof(temp1[0]));

    s1.display();

    s1.Bubble_Sort();
    s1.display();

}