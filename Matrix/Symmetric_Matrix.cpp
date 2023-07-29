#include<iostream>
using namespace std;

class task
{
private:
int a[3][3];
int n;
public:

task(int index,int t[3][3])
{
n=index;
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        a[i][j]=t[i][j];
    }
}

}

void display();

bool Symmetric_matrix();
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


bool task::Symmetric_matrix()
{
for(int i=0;i<n;i++)
{
    for(int j=i;j<n;j++)
    {
        if(a[i][j]!=a[j][i]){return false;}
    }
}
return true;
}


int main()
{
int temp[3][3]={1,1,1,1,2,2,1,2,3};
task t(3,temp);
t.display();

if(t.Symmetric_matrix())
{
    cout<<"Matrices is Symmetric Matrices....!"<<endl;
}
else{cout<<"Not a Symmetric Matrices....!"<<endl;}


return 0;
}