// Given head of a linked list , determine if a given list has a cycle in it 

#include<iostream>
using namespace std;
class node{
public:
int data;
node* next;

node(int val)
{
    data = val;
    next = NULL;
}


};



class LL
{
    public:
    node* head;
    node* end;

    LL()
    {
        head = NULL;
        end = NULL;

    }

    void insertion_H(int val)
    {
        if(head == NULL)
        {
            head = new node(val);
            end = head;
            return ;
        }

        node* newnode = new node(val);
        newnode->next = head;
        head = newnode;


    }

    void display()
{
    node* temp = head;

    while(temp != NULL)
    {
            cout << "[ "<< temp->data << " | " << temp->next << " ] " << " - > " ;
        temp = temp->next;
    }
    cout << " null " << endl;
}




};



bool checkCycle(node* head)
{
    int p = 0;
    int q = 0;
    node* temp = head;
    node* checker = head;
    while(temp != NULL)
    {   
        while(q != p/2)
        {   
            if(checker == temp ) return true;
            checker = checker->next;
            q++;
        }
        p++;
        temp = temp->next;

    }
    return false;
}

int main()
{

LL f;
f.insertion_H(1);
f.insertion_H(2);
f.insertion_H(3);
f.insertion_H(4);
f.insertion_H(5);
// f.end->next = f.head->next->next;
cout <<checkCycle(f.head);

return 0;
}