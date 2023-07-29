#include<iostream>
using namespace std;

class task
{
private:
int a[5][5];
int n;
public:

task(int index,int t[5][5])
{
n=index;
for(int i=0;i<5;i++)
{
    for(int j=0;j<5;j++)
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
for(int i=0;i<5;i++)
{
    for(int j=0;j<5;j++)
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
    // int temp=0;
    for(int j=0;j<n;j++)
    {
        if(i==j && a[i][j]==0){return false;}
        else if((i+1)==j && a[i+1][j]==0){return false;}
        else if(i==(j+1) && a[i][j+1]==0){return false;}

    }
    
        for(int k=0;k<i-1;k++)
        {
            if(a[i][k]!=0){return false;}
        }
            for(int l=i+2;l<n;l++)
            {
                if(a[i][l]!=0){return false;}
            }
}
return true;
}


int main()
{
int temp[5][5]={1,2,0,0,0,3,1,2,0,0,0,3,1,2,0,0,0,3,1,2,0,0,0,3,1};
task t(5,temp);
t.display();

if(t.Symmetric_matrix())
{
    cout<<"Matrices is Symmetric Matrices....!"<<endl;
}
else{cout<<"Not a Symmetric Matrices....!"<<endl;}


return 0;
}