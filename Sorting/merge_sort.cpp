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

   void merge(int low, int mid, int hig)
    {
        int *temp = new int[hig + 1];
        int l = low;
        int m = mid + 1;
        int h = hig;
        int t = low;

        while (l <= mid && m <= h)
        {
            if (arr[l] > arr[m])
            {
                temp[t++] = arr[m++];
            }
            else
            {
                temp[t++] = arr[l++];
            }
        }

        while(l<=mid)
        {
            temp[t++] = arr[l++];
        }

        // for (; m <= h; m++)
        while(m<=hig)
        {
            temp[t++] = arr[m++];
        }

        for (int i = low; i <= hig; i++)
        {
            if (i > size-1)
            {
                size++;
            }
            arr[i] = temp[i];
        }
        
    }

    void mergesort_sorting(int low, int high)
    {
        if (low < high)
        {
            int mid =(high + low) / 2;
            mergesort_sorting(low, mid);
            mergesort_sorting(mid + 1, high);
            merge(low, mid, high);
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
   
    s1.mergesort_sorting(0, (s1.getsize() - 1));
    s1.display();
}