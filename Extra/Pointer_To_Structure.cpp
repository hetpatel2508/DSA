#include<iostream>
using namespace std;

struct ract
{
    int len;
    int bre;
};


int main()
{
struct ract r={2,3};
struct ract *ptr=&r;
cout<<ptr->len<<endl;
cout<<ptr->bre<<endl;
}