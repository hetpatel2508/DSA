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

bool Upper_Triangle();
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


bool task::Upper_Triangle()
{
for(int i=0;i<n;i++)
{
    for(int j=i;j<n;j++)
    {
        if(a[i][j]==0){return false;}
    }
    for(int k=0;k<i;k++)
    {
        if(a[i][k]!=0){return false;}
    }
}
return true;
}


int main()
{
int temp[3][3]={1,2,3,0,4,5,0,0,6};
task t(3,temp);
t.display();

if(t.Upper_Triangle())
{
    cout<<"Matrices is Upper Triangular Matrices....!"<<endl;
}
else{cout<<"Not a Upper Triangular Matrices....!"<<endl;}


return 0;
}