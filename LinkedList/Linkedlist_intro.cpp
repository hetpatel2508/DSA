#include <iostream>
#include <math.h>
using namespace std;

struct linkedlist
{
int data;
struct linkedlist *next_node;
};

void display(struct linkedlist *head)
{
    
    while(head!=0)
    {
        cout<<head->data<<"  ";
        head=head->next_node;
    }
}

int main()
{
    struct linkedlist *head=new linkedlist;
    struct linkedlist *second=new linkedlist;
    struct linkedlist *third=new linkedlist;

    head->data=1;
    head->next_node=second;

    second->data=2;
    second->next_node=third;

    third->data=3;
    third->next_node=NULL;

    display(head);
}