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
void reverse(int len);
void pelindrom(task t);
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

void task::reverse(int len)
{
    int temp=len;
    for(int i=0;i<len/2;i++)
    {
        int j=temp-1-i;
        int t=0;
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
}

void task::pelindrom(task t)
{
    int temp2=0;
    task temp=t;

    t.reverse(t.length());

    for(int i=0;i<t.length();i++)
    {
        if(temp.a[i]==t.a[i])
        {
            temp2++;
        }
    }

    if(temp2==(t.length()))
    {
        cout<<"String is pelindrome...!"<<endl;
    }

    else
    {
        cout<<"String is not pelindrome...!"<<endl;
    }
}

int main()
{

char temp1[25]="HeeH";
char temp2[25]="Hee";
char temp3[25]="He";
task t1(temp1);
task t2(temp2);
task t(temp3);

t.pelindrom(t1);
t.pelindrom(t2);
return 0;
}