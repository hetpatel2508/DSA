#include<iostream>
using namespace std;

int add1(int num)
{
    static int x=0;
    if(num>0)
    {
        x++;
        return add1(num-1)+x;
    }
    return 0;
}

int y=0;

int add2(int num)
{
    if(num>0)
    {
        y++;
        return add2(num-1)+y;
    }
    return 0;
}



int main()
{
    cout<<"Additision= "<<add1(4)<<endl;

    cout<<"Additision= "<<add2(5)<<endl;

}