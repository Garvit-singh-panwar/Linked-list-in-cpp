// Given the heads of two single linkedlist headA and headB , 
// return the node at which the two lists intersect. 
// if the two list have no intersection at all return null;

// LL1 = 1 -> 2 -> 3 -> 4 -> 5 ->NULL
//                      |
// LL2 = 7 -> 8 -> 9 ->--

// output : addressof(4) 

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



void insert_OtherLLNode_AtEnd(node* &another)
{

    node* temp = head;
    while(temp->next != NULL )
    {
        temp = temp->next;
    } 
    temp->next = another;

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



node* Intersection_PointOf2LL(node* &first , node* &second)
{
    
    node* f_temp = first;
    node* s_temp = second;
    node* prev = NULL;
    while(s_temp != NULL)
    { 
    while(f_temp != NULL )
    {
        if( f_temp == s_temp)
        {
            return f_temp;

        }
        f_temp = f_temp->next;
    }
        f_temp = first;
        s_temp = s_temp->next;
    }

    return NULL;
}

int main()
{
    
LinkedList f , s ;
f.insertion_E(1);
f.insertion_E(2);
f.insertion_E(3);
cout << "First LL = ";
f.display();
s.insertion_E(1);
s.insertion_E(2);
s.insertion_E(3);
s.insertion_E(4);
s.insertion_E(5);
s.display();
node* node4ofs = s.head->next->next->next;
f.insert_OtherLLNode_AtEnd(node4ofs);
cout << "after adding node of s LL our f LL become " ;
f.display();
//cout <<  "Intersection point of f and s LL is " << Intersection_PointOf2LL(f.head , s.head) << endl;



return 0;
}
