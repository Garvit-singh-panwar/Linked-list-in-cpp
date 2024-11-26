// Given 2 LinkedList , tell if they are equal or not . 
// Two LinkedList are equal if they have the same data and the arrangement of data is also same  

// LL1 = 1 -> 2 -> 3 -> 4 -> NULL
// LL2 = 1 -> 2 -> 3 -> 4 -> NULL

// OUTPUT : TRUE

// LL1 = 1 -> 2 -> 3 -> 4 -> NULL;
// LL2 = 1 -> 2 -> 3 -> NULL

// OUTPUT : FALSE 


// LL1 = 1 -> 3 -> 2 -> 4 -> NULL
// LL2 = 1 -> 2 -> 3 -> 4 -> NULL

// OUTPUT : FALSE

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



bool Compare_Two_LL_SameOrNot(node* &first , node* &second)
{

node* F_temp = first;
node* S_temp = second;

while(F_temp != NULL && S_temp != NULL)
{
    if(F_temp->data != S_temp->data)
    {
        return false;
    }
    F_temp = F_temp->next;
    S_temp = S_temp->next;
}

if(F_temp != S_temp)
{
    return false;
}

return true;
}

int main()
{

LinkedList f,s;
f.insertion_E(1);
f.insertion_E(2);
f.insertion_E(3);
f.insertion_E(4);
f.insertion_E(5);
f.insertion_E(6);
cout << "First LinkedList = " ;
f.display();
s.insertion_E(1);
s.insertion_E(2);
s.insertion_E(3);
s.insertion_E(4);
s.insertion_E(5);
cout << "second LinkedList = " ;
s.display();
cout << "comparing both are same or not : 1 for same and 0 for notsame " << endl;
cout << Compare_Two_LL_SameOrNot(f.head , s.head) << endl;


    return 0;
}