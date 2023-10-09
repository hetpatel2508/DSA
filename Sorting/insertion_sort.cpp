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


    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    void insertion_sort()
    {
        for (int i = 1; i < size; i++)
        {
            int j = i - 1;
            int temp = arr[i];

            for (; j >= 0 && arr[j] > temp; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
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

    s1.insertion_sort();
    s1.display();

}