#include<iostream>
using namespace std;

class task
{
private:
int n;
int *A=new int[24];

public:

task(int index,int t[25])
{
n=index;
for(int i=0;i<25;i++)
{
    A[i]=t[i];
}
}

bool Upper_Triangular();
};



bool task::Upper_Triangular()
{
int x=0;   
for(int i=0;i<n;i++)
{
    for(int k=0;k<i;k++)
    {
        cout<<"0  ";
    }
    for(int j=i;j<n;j++)
    {
        cout<<A[x]<<"  ";
        x++;
    }
    cout<<endl;
}
}

int main()
{
int temp[12]={1,2,3,4,5,6,7,8,9,10};
task t(4,temp);
t.Upper_Triangular();
return 0;
}