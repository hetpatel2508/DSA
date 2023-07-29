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

int temp=0;
for(int i=0;i<n;i++)
{
int x=0;
int y=0;
    for(int j=0;j<n;j++)
    {
         if(j>=i+2)
        {
            cout<<"0  ";
        }
        else if(j>=i-1 && y<3)
        {
            cout<<A[x]<<"  ";
            x++;
            y++;
        }
        else 
        {
            cout<<"0  ";
        }
    }
    temp++;
    cout<<endl;
}

}

int main()
{
int temp[12]={1,2,3,4,5,6,7,8,9,10};
task t(5,temp);
t.Upper_Triangular();
return 0;
}