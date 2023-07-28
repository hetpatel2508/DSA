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
    for(int i=0;i<len/2;i++)
    {
        int j=len-i-1;
        int temp=0;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}



int main()
{

char temp[25]="Hetp$123";
task t(temp);
t.reverse(t.length());

t.display();
}