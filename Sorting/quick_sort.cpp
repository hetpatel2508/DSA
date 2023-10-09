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

    int getsize() { return size; }

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

    int partision(int low, int hig)
    {
        int pivot = arr[low];
        int l = low + 1;
        int h = hig;

        do
        {

            while (arr[l] <= pivot)
            {
                l++;
            }

            while (arr[h] > pivot)
            {
                h--;
            }

            if (l < h)
            {
                swap(&arr[l], &arr[h]);
            }
            // display(); // to check the total numbers of steps perfomed

        } while (l < h);
        swap(&arr[low], &arr[h]);
        return h;
    }

    void quick_sort(int low, int hig)
    {
        int PivotAtSortedIndex;
        if (low < hig)
        {
            PivotAtSortedIndex = partision(low, hig);
            quick_sort(low, PivotAtSortedIndex - 1);
            quick_sort(PivotAtSortedIndex + 1, hig);
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

    s1.quick_sort(0, (s1.getsize() - 1));
    s1.display();
}