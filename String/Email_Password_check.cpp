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

bool check_email();

bool check_password();
};

void task::display()
{
    for(int i=0;a[i] !='\0';i++)
    {
        cout<<a[i];
    }
}

bool task::check_email()
{
    int len=0;
    int temp=0;
    for(int i=0;a[i]!='\0';i++)
    {
        len++;
        if((a[i]>=65&&a[i]<=90) || (a[i]>=97&&a[i]<=122) || (a[i]>=48&&a[i]<=57) || a[i]=='@' || a[i]=='.')
        {temp++;}
    }
    if(len==temp){return 1;}
    else{return 0;}
}

bool task::check_password()
{
    int alphabet=0;
    int number=0;
    int special_symbol=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if((a[i]>=65&&a[i]<=90) || (a[i]>=97&&a[i]<=122))
        {alphabet++;}
        else if((a[i]>=48&&a[i]<=57))
        {number++;}
        else if(a[i]=='@' || a[i]=='#' || a[i]=='$' || a[i]=='&' || a[i]=='_' || a[i]=='.')
        {special_symbol++;}
        else{return 0;}
    }
    if(alphabet>3 && number>2 && special_symbol>0)
    {
        return 1;
    }
}

int main()
{

char temp1[25]="Het16491234@gmail.com";
char temp2[25]="Hetp$1234";
task t1(temp1);
task t2(temp2);

if(t1.check_email())
{
    cout<<"Email is good...!"<<endl;
}
else{cout<<"Email error..."<<endl;}


if(t2.check_password())
{
    cout<<"Password is good...!"<<endl;
}
else{cout<<"Password error..."<<endl;}

}