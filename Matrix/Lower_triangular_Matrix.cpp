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

bool Lower_Triangle();
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


bool task::Lower_Triangle()
{
for(int i=0;i<n;i++)
{
    for(int j=0;j<i+1;j++)
    {
        if(a[i][j]==0){return false;}
    }
    for(int k=i+1;k<n;k++)
    {
        if(a[i][k]!=0){return false;}
    }
}
return true;
}


int main()
{
int temp[3][3]={1,0,0,4,5,0,7,8,9};
task t(3,temp);
t.display();

if(t.Lower_Triangle())
{
    cout<<"Matrices is Lower Triangular Matrices....!"<<endl;
}
else{cout<<"Not a Lower Triangular Matrices....!"<<endl;}


return 0;
}