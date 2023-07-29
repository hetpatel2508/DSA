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
int len_of_arr=(((n*n)+n)/2);

for(int i=0;i<len_of_arr;i++)
{
    A[i]=t[i];
}
}

bool Lower_Triangular();
};



bool task::Lower_Triangular()
{
int x=0;   
for(int i=0;i<n;i++)
{
    for(int j=0;j<i+1;j++)
    {
        cout<<A[x]<<"  ";
        x++;
    }
    for(int k=i+1;k<n;k++)
    {
        cout<<"0  ";
    }
    cout<<endl;
}
}

int main()
{
int temp[12]={1,2,3,4,5,6,7,8,9,10};
task t(4,temp);
t.Lower_Triangular();
return 0;
}