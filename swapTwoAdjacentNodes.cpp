// Given a LinkedList 
// swap every teo adjacent nodes and return its head.
// you may not modify the value in the list's nodes.
// only nodes themselves may be changed

#include<iostream>
using namespace std;

class node
{

public:
int data;
node* next;

node(int val)
{
    data =val;
    next = NULL;
}

};

class LL
{

public:
node* head;
LL()
{
    head = NULL;

}

void insertion(int val)
{
    if(head == NULL)
    {
        head = new node(val);
        return ;

    }

    node* temp = head;
    while(temp->next)
    {
        temp =temp->next;
    }
    temp->next = new node(val);


}



void display()
{
    node* temp = head;

    while (temp)
    {
        cout << temp->data << " -> ";
        temp= temp ->next;
    }
    cout << "NULL  " << endl;


}

};


node* swap2AdjacentNOdes(node* head)
{

    if(head == NULL)
    {
        return head;
    }

    node* prev = NULL;
    node* curr = head;
    for(int i = 0 ; i < 2 && curr ; i++)
    {
        node* nexthead = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nexthead;

    }
    if(curr)
    {
        head->next = swap2AdjacentNOdes(curr);
    }
  
    return prev;

}

node* swap2AdjacentNOdes2(node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    // recursive case
    node* secondNode = head->next;
    head->next = swap2AdjacentNOdes2(secondNode->next);
    secondNode->next = head ; // reversing the link between first and second
    return secondNode;

}

int main()
{

    LL f,s;
    f.insertion(1);
    f.insertion(2);
    f.insertion(3);
    f.insertion(4);
    f.insertion(5);
    f.insertion(6);
    f.display();
    // s.head = swap2AdjacentNOdes(f.head);
    s.head = swap2AdjacentNOdes2(f.head);
    s.display();




    return 0;
}
