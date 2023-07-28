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

void check(int  *vovel=0,int *consonant=0);
};

void task::display()
{
    for(int i=0;a[i] !='\0';i++)
    {
        cout<<a[i];
    }
}

void task::check(int  *vovel,int *consonant)
{
    for(int i=0;a[i] !='\0';i++)
    {
        if(a[i]=='a' || a[i]=='e' ||a[i]=='i' ||a[i]=='o' ||a[i]=='u' ||a[i]=='A' ||a[i]=='E' ||a[i]=='I' ||a[i]=='O' || a[i]=='U')
        {(*vovel)++;}
        else if((a[i]>=65 && a[i]<=90) || (a[i]>=97 && a[i]<=122))
        {(*consonant)++;}
    }
}

int main()
{

char temp[25]="HetPatel";
task t1(temp);

int vov=0,con=0;

t1.check(&vov,&con);

cout<<"Vovels= "<<vov<<endl;
cout<<"consonant= "<<con<<endl;

return 0;
}