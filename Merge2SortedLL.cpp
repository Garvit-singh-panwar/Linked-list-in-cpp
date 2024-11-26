// Given 2 sorted LinkedList , merge them into 1 single linked list such that the resulting list is also sorted 

#include<iostream>
using namespace std;

class node
{
public:

int data ;
node* next;

node(int val)
{
    data =val;
    next = NULL;
}

};


class LinkedList
{
public:
node* head;

LinkedList()
{
    head = NULL;
}

void insertion_H(int val)
{
    if(head == NULL)
    {
        head = new node(val);
        return ;
    }

    node* newnode = new node(val);
    newnode->next = head;
    head = newnode;
}


void insertion_E(int val)
{
    if(head == NULL)
    {
        head = new node(val);
        return;
    }

    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new node(val);

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




node* merge_two_LL(node* &f,node* &s)
{
    node* Dummy_head = new node(-1);

    node* p = f;
    node* q = s;
    node* r = Dummy_head;

    while(p && q)
    {
        if(p->data < q->data)
        {
            r->next = p;
            r = r->next;
            p = p->next;

        }
        else
        {
            r->next = q;
            q = q->next;
            r = r->next;
        }

    }

    while(q)
    {
        r->next = q;
        q = q->next;
    }
    while(p)
    {
        r = p->next;
        p = p->next;
    }

    node* temp =Dummy_head;
    Dummy_head = Dummy_head->next;
    delete(temp);
    return Dummy_head;

}

int main()
{

LinkedList f,s,t;
f.insertion_E(1);
f.insertion_E(3);
f.insertion_E(5);
f.insertion_E(7);
s.insertion_E(2);
s.insertion_E(4);
s.insertion_E(6);
t.head = merge_two_LL(f.head,s.head);
t.display();




    return 0;
}