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

bool Symmetric_Matrix();
};



bool task::Symmetric_Matrix()
{

for(int i=0;i<n;i++)
{
int temp=0;
    for(int j=0;j<n;j++)
    {
        if(temp<i)
        {
            cout<<A[temp]<<"  ";
            temp++;
        }
        else
        {
            cout<<A[temp]<<"  ";
        }
    }
    cout<<endl;
}

}

int main()
{
int temp[12]={1,2,3,4,5,6,7,8,9,10};
task t(5,temp);
t.Symmetric_Matrix();
return 0;
}