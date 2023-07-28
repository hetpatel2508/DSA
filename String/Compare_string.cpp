#include<iostream>
using namespace std;

class task
{
private:
char a[25];

public:

task(char t[25])
{

int temp=0;
    for(int i=0;t[i]!='\0';i++)
    {
        a[i]=t[i];
        temp++;
    }
    a[temp]='\0';
}

void display();

int length();

void compare(task t1,task t2);

};

void task::display()
{
    for(int i=0;a[i] !='\0';i++)
    {
        cout<<a[i];
    }
}

int task::length()
{

int temp=0;
    for(int i=0;a[i]!='\0';i++)
    {
        temp++;
    }
    return temp;
}

void task::compare(task t1,task t2)
{
    int temp=0;
    for(int i=0;i<t1.length();i++)
    {
        if(t1.a[i]==t2.a[i])
        {
            temp++; 
        }
    }
    if(temp==t1.length())
    {cout<<"String is same....!";}
    else
    {cout<<"String is not same....!";}
}

int main()
{

char temp1[25]="Hetp$1234";
char temp2[25]="Hetp$1234";
char temp3[25]="Het";
task t1(temp1);
task t2(temp2);
task t(temp3);

t.compare(t1,t2);
return 0;
}