#include<iostream>
using namespace std;

class sparse_matrix
{
private:
int row;
int colum;
int *A=new int[60];
int t=1;

public:
    
int i[25];
int j[25];
int x[25];

sparse_matrix()
{
    row=0;
    colum=0;
    A=0;
}

sparse_matrix(int r,int c,int x[50])
{
    row=r;
    colum=c;
    for(int f=0;f<(row*colum);f++)
    {
        A[f]=x[f];
    }
}
void display()
{
    int temp=0;
    for(int o=0;o<row;o++)
    {
        for(int p=0;p<colum;p++)
        {
            cout<<A[temp]<<"  ";
            temp++;
        }
    cout<<endl;
    }
}


void sparse_matrix_Adjustment()
{
            i[0]=row;
            j[0]=colum;
int temp=0;
    for(int a=0;a<row;a++)
    {
        for(int b=0;b<colum;b++)
        {
            if(A[temp]!=0)
            {
                i[t]=a+1;
                j[t]=b+1;
                x[t]=A[temp];
                t++;
            }
            temp++;
        }
    }
            x[0]=t-1;
}
void sparse_display()
{
    for(int a=0;a<t;a++)
    {
        cout<<i[a]<<"  ";
    }
    cout<<endl;
    for(int b=0;b<t;b++)
    {
        cout<<j[b]<<"  ";
    }
    cout<<endl;
    for(int c=0;c<t;c++)
    {
        cout<<x[c]<<"  ";
    }
    cout<<endl;
}

void sparse_to_normal()
{
    int temp=1;
    for(int a=0;a<row;a++)
    {
        for(int b=0;b<colum;b++)
        {
            if(a==(i[temp]-1) && b==(j[temp]-1))
            {
                cout<<x[temp]<<"  ";
                temp++;
            }
            else 
            {
                cout<<"0  ";
            }
        }
        cout<<endl;
    }
}

};


int main()
{
    int temp1[35]={0,0,0,6,0,0,0,7,0,0,0,0,0,2,0,5,0,0,0,0,0,0,0,0,4,0,0,0,0,0};
    sparse_matrix s1(5,6,temp1);
    
    s1.display();
    s1.sparse_matrix_Adjustment();
    cout<<endl;
    s1.sparse_display();
}