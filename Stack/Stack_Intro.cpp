#include<iostream>
using namespace std;

struct stack
{
int size;
int top=-1;
int *a;
};

void set(stack *s1,int temp[20])
{
    for(int i=0;i<s1->size;i++)
    {
        s1->top++;
        s1->a[i]=temp[i];
    }
}

void display(stack s)
{
    for(int i=0;i<=s.top;i++)
    {
        cout<<s.a[i]<<"  ";
    }
    cout<<endl;
}

void push_element(stack *s,int num)
{
    s->size++;
    s->top++;
    s->a[s->top]=num;
}

void pop(stack *s)
{
    s->a[s->top]=0;
    s->size--;
    s->top--;
}

bool peep(stack s,int num)
{
    for(int i=0;i<=s.top;i++)
    {
        if(s.a[i]==num)
        {
            return true;
        }
    }
    return false;
}

void chang_element(stack *s, int index,int number)
{

    s->a[index]=number;

}

void if_empty(stack s)
{
    if(s.top==-1)
    {
        cout<<"Stack is Empty......"<<endl;
    }
    else
        cout<<"Stack is not Empty......"<<endl;
    {

    }
}


void if_full(stack s)
{    
    if(s.top==s.size-1)
    {
        cout<<"Stack is Full......"<<endl;
    }
    else
        cout<<"Stack is not Full......"<<endl;
    {

    }
}


int main()
{
    stack s;
    s.size=5;
    s.a=new int[s.size];

    int temp[20]={1,2,3,4,5};

    set(&s,temp);

    display(s);

    push_element(&s,6);
    
    display(s);


    pop(&s);
    display(s);


    if(peep(s,3))
    {
        cout<<"Element Found..."<<endl;
    }

    else
    {
        cout<<"Element Not Found..."<<endl;

    }

    chang_element(&s,2,6);
    display(s);

    if_empty(s);
    if_full(s);

    delete s.a;
    s.a=nullptr;

}