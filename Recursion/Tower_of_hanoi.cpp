#include <iostream>
using namespace std;

void tower_of_hanoi(int num,char A,char B,char C)
{
    static int step=1;
    if(num>0)
    {
        tower_of_hanoi(num-1,A,C,B);
        cout<<"Step: "<<step++<<"  Move Disk: "<<num<<" "<<A<<" to "<<C<<endl;
        tower_of_hanoi(num-1,B,A,C);
    }
}

int main()
{

    tower_of_hanoi(3,'A','B','C');
}