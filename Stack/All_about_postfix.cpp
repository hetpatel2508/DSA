#include <iostream>
using namespace std;

class stack
{
private:
    int size;
    int top = -1;
    char *a;

public:
    stack()
    {
        size = 0;
        a = nullptr;
    }

    stack(char c[], int n)
    {
        size = n;
        a = new char[size];
        for (int i = 0; i < size; i++)
        {
            a[i] = c[i];
        }
    }

    // void push(char num)
    // {
    //     top++;
    //     use[top] = num;
    // }

    // void pop()
    // {
    //     use[top] = 0;
    //     top--;
    // }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << a[i] << "  ";
        }
        cout << endl;
    }

    int isOperand(char a)
    {
        if (a == '+' || a == '-' || a == '/' || a == '*' || a == '(' || a == ')')
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    int presendence(char a)
    {
        if (a == '+' || a == '-')
        {
            return 1;
        }
        else if (a == '*' || a == '/')
        {
            return 2;
        }
        else if (a == '(' || a == ')')
        {
            return 7;
        }
        else
        {
            return 0;
        }
    }
    bool paranthesis()
    {
        char *use = new char[size];
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
        char *use = new char[size];
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
                else if ((a[i] == 41 && a[i] != temp[hig] + 1) || ((a[i] == 125 || a[i] == 93) && a[i] != temp[hig] + 2))
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

    char *Infix_to_postfix()
    {
        char *temp = new char[20]; // this will be returned at last  & j=top
        int j = -1;
        char *use = new char[size]; // this will be used as stack for +-/*  &  hig=top
        int hig = -1;

        for (int i = 0; i < size; i++)
        {
            if (isOperand(a[i]))
            {
                j++;
                temp[j] = a[i];
            }
            else
            {
                while (hig != -1 && presendence(a[i]) <= presendence(use[hig]))
                {
                    j++;
                    temp[j] = use[hig];
                    hig--;
                }
                hig++;
                use[hig] = a[i];
            }
        }
        while (hig != -1)
        {
            j++;
            temp[j] = use[hig];
            hig--;
        }
        return temp;
    }

    char *Infix_to_postfix_advance()
    {
        char *temp = new char[20]; // this will be returned at last  & j=top
        int j = -1;
        char *use = new char[size]; // this will be used as stack for +-/*  &  hig=top
        int hig = -1;

        for (int i = 0; i < size; i++)
        {
            if (isOperand(a[i]) && a[i] != '(' && a[i] != ')')
            {
                j++;
                temp[j] = a[i];
            }
            else if (a[i] == '(')
            {
                hig++;
                use[hig] = a[i];
            }
            else if (a[i] == ')')
            {
                while (use[hig] != '(' && hig != -1)
                {
                    j++;
                    temp[j] = use[hig];
                    hig--;
                }
                if (use[hig] == '(' && hig != -1)
                {
                    use[hig] = 0;
                    hig--;
                }
            }
            else
            {
                while (hig != -1 && presendence(a[i]) <= presendence(use[hig]) && use[hig] != '(' && use[hig] != ')')
                {
                    j++;
                    temp[j] = use[hig];
                    hig--;
                }
                hig++;
                use[hig] = a[i];
            }
        }
        while (hig != -1)
        {
            j++;
            temp[j] = use[hig];
            hig--;
        }
        return temp;
    }

    /*
        char *Infix_to_postfix()
    {
        char *temp = new char[size]; // The size of the output can be equal to the size of the input
        int j = -1;
        char *use = new char[size]; // Stack for operators
        int hig = -1;

        for (int i = 0; i < size; i++)
        {
            if (isOperand(a[i]))
            {
                j++;
                temp[j] = a[i];
            }
            else
            {
                if (presendence(a[i]) > presendence(use[hig]))
                {
                    hig++;
                    use[hig] = a[i];
                }
                else
                {
                    while (hig != -1)
                    {
                        if (presendence(a[i]) > presendence(use[hig]))
                        {
                            hig++;
                            use[hig] = a[i];
                        }

                        j++;
                        temp[j] = use[hig];
                        hig--;
                    }

                    hig++;
                    use[hig] = a[i];
                }
            }
        }

        // Add any remaining operators from the stack to temp
        while (hig != -1)
        {
            j++;
            temp[j] = use[hig];
            hig--;
        }

        return temp;
    }
    */

    int evaluation_of_postfix()
    {
        char *temp = new char[20]; // this will be returned at last  & j=top
        int j = -1;
        char *use = new char[size]; // this will be used as stack for +-/*  &  hig=top
        int hig = -1;

        for (int i = 0; i < size; i++)
        {
            if (isOperand(a[i]))
            {
                hig++;
                use[hig] = a[i] - '0';
            }

            else if (a[i] == ' ')
            {
                // Ignore spaces
            }
            // else if(hig!=0)
            else
            {
                int x = use[hig];
                int y = use[hig - 1];
                hig--;
                hig--;
                int result;
                switch (a[i])
                {
                case '+':
                    result = y + x;
                    hig++;
                    use[hig]=result;
                    break;

                case '-':
                    result = y - x;
                    hig++;
                    use[hig]=result;
                    break;

                case '*':
                    result = y * x;
                    hig++;
                    use[hig]=result;
                    break;

                case '/':
                    if (x != 0) // Check for division by zero
                        result = y / x;
                    hig++;
                    use[hig]=result;
                    break;
                }
            }
        }
        return use[hig];
    }
};

int main()
{

    char temp[] = {'(', '(', 'a', '+', 'b', ')', '*', '(', 'c', '+', 'd', ')', ')'};
    int n = sizeof(temp);
    stack s1(temp, n);
    s1.display();

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

    // char temp2[] = {'a','+','b','*','c','-','d','/','e'};
    char temp2[] = {'(', '(', 'a', '+', 'b', ')', '*', 'c', ')', '-', 'd', '/', 'e'};
    int m1 = sizeof(temp2);
    stack s3(temp2, m1);
    s3.display();

    char *t = s3.Infix_to_postfix_advance();
    cout << t << endl;

    string het = t;
    int m2 = het.length();

    stack s4(t, m2);
    s4.display();


    char temp3[] = {'3','5','*','6','2','/','+','4','-'};
    int m4 = sizeof(temp3);
    stack s5(temp3, m4);
    s5.display();
    cout << "Evaluation: " << s5.evaluation_of_postfix() << endl;
}