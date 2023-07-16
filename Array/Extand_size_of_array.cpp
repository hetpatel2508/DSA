#include <iostream>
using namespace std;

int main()
{
    int *a = new int[5]{1, 2, 3, 4, 5};
    cout << a[0] << endl;

    int *b = new int[10];
    b = a;

    for (int i = 5; i < 10; i++)
    {
        b[i] = i + 1;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << b[i] << "  ";
    }

    delete[] a;
    delete[] b;
}