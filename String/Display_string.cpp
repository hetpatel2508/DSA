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
};

void task::display()
{
    for(int i=0;a[i] !='\0';i++)
    {
        cout<<a[i];
    }
}

int main()
{

char temp[25]="HetPatel";
task t1(temp);

t1.display();
return 0;
}