#include <iostream>
using namespace std;

class stack
{
private:
    int size;
    int top = -1;
    char *a;
    char *use;

public:
    stack()
    {
        size = 0;
        a = nullptr;
    }

    stack(char c[], int n)
    {
        size = n;
        a = new char(size);
        use = new char(size);
        for (int i = 0; i < size; i++)
        {
            a[i] = c[i];
        }
    }

    void push(char num)
    {
        top++;
        use[top] = num;
    }

    void pop()
    {
        use[top] = 0;
        top--;
    }

    bool paranthesis()
    {
        for (int i = 0; i < size; i++)
        {
            if (a[i] == '(')
            {
                top++;
                use[top] = a[i];
            }
            else if (a[i] == ')')
            {
                if (top == -1)
                {
                    return false;
                }
                use[top] = 0;
                top--;
            }
        }
        if (top == -1)
        {
            return true;
        }
    }

    bool Advance_paranthesis()
    {
        char *temp = new char[20];
        int hig = -1;
        for (int i = 0; i < size; i++)
        {
            if (a[i] == '(' || a[i] == '[' || a[i] == '{')
            {
                top++;
                use[top] = a[i];
                hig++;
                temp[hig] = a[i];
            }
            else if (a[i] == ')' || a[i] == ']' || a[i] == '}')
            {
                if (top == -1)
                {
                    return false;
                }
                else if ((a[i] == 41 && a[i] != temp[hig] + 1)   ||  ((a[i] == 125 || a[i] == 93) && a[i] != temp[hig] + 2))
                {
                    temp[hig] = 0;
                    hig--;
                    return false;
                }
                temp[hig] = 0;
                hig--;
                use[top] = 0;
                top--;
            }
        }
        if (top == -1)
        {
            return true;
        }
    }
};

int main()
{

    char temp[] = {'(', '(', 'a', '+', 'b', ')', '*', '(', 'c', '+', 'd', ')', ')'};
    int n = sizeof(temp);
    stack s1(temp, n);

    if (s1.paranthesis())
    {
        cout << "All ok...!" << endl;
    }
    else
    {
        cout << "not ok...!" << endl;
    }

    char temp1[] = {'(', '{', 'a', '+', 'b', '}', '[', 'c', '+', 'd', ']', ')'};
    int m = sizeof(temp);
    stack s2(temp, m);

    if (s2.Advance_paranthesis())
    {
        cout << "All ok...!" << endl;
    }
    else
    {
        cout << "not ok...!" << endl;
    }
}