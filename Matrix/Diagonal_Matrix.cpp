#include<iostream>
using namespace std;

class task
{
private:
int a[3][3];

public:

task(int t[3][3])
{

for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        a[i][j]=t[i][j];
    }
}

}

void display();

bool diagonal();
};


void task::display()
{
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        cout<<a[i][j]<<"  ";
    }
    cout<<endl;
}
}


bool task::diagonal()
{
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        if(i==j && a[i][j]==0){return false; break;}
        else if(i!=j && a[i][j]!=0){return false; break;}
    }
}
return true;
}


int main()
{
int temp[3][3]={1,0,0,0,5,0,0,0,9};
task t(temp);
t.display();

if(t.diagonal())
{
    cout<<"Matrices is Diagonal Matrices....!"<<endl;
}
else{cout<<"Not a Diagonal Matrices....!"<<endl;}


return 0;
}