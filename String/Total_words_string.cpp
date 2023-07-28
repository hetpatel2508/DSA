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
int word_string();
};

void task::display()
{
    for(int i=0;a[i] !='\0';i++)
    {
        cout<<a[i];
    }
}

int task::word_string()
{
    int temp=1;
    for(int i=0;a[i] !='\0';i++)
    {
        if(a[i]==' ')
        {
            temp++;
        }
    }
    return temp++;
}


int main()
{

char temp[25]="Het Patel R";
task t1(temp);
int word=t1.word_string();
cout<<"Total Words= "<<word;
return 0;
}