#include<iostream>
using namespace std;

class task
{
private:
int n;
int *A=new int[n];

public:

task(int index,int t[12])
{
n=index;
for(int i=0;i<n;i++)
{
    A[i]=t[i];
}
}

bool diagonal();

};


bool task::diagonal()
{
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        if(i==j){cout<<A[i]<<"  ";}
        else{cout<<"0  ";}
    }
    cout<<endl;
}
}

int main()
{
int temp[12]={1,2,4,5};
task t(3,temp);
t.diagonal();

return 0;
}