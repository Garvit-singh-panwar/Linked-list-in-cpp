// Given the head of a linked list , rotate the list to the right by k places  

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

class LinkedList
{

public:
node* head;

LinkedList()
{
    head = NULL;
}


void insertion(int val)
{

if( head == NULL)
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
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

}

};


node* rotateList_toRight_byK_Nodes(int k , node* head)
{

node* p = head;
node* q = head;

for(int i = 0 ; i < k ; i++)
{
    q = q->next; 
}
while(q->next)
{
    q = q->next;
    p = p->next;
}
node* newhead = p->next;
p->next = NULL;
q->next = head;

return newhead;

}


node* rotateList_toRight_byK_Nodes2(int k , node* head)
{

int n;
node* tail = head;

while(tail->next)
{
    tail = tail->next;
    n++;
}
n++;

k = k%n;
cout << k  << endl;
if(k == 0)
{
    return head;
}

tail->next = head;
node* temp = head;

for(int i = 1 ; i < n-k ; i++ )
{
    temp = temp->next;
}
node* newhead = temp->next;
temp->next = NULL;

return newhead;


}

int main()
 {

LinkedList f , n;
f.insertion(1);
f.insertion(2);
f.insertion(3);
f.insertion(4);
f.insertion(5);
f.insertion(6);
f.insertion(7);
f.display();


// n.head = rotateList_toRight_byK_Nodes( 2 , f.head);
n.head = rotateList_toRight_byK_Nodes2( 2 , f.head);
n.display();




    return 0;

 }






