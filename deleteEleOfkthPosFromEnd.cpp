// Given the head of the linked list remove the kth element from the end of the linked list and return the head


#include<iostream>
using namespace std;

class node{

public:
int data;
node *next;

node(int val)
{
    data = val;
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

void insertionAt_End(int val)
{
    if(head==NULL)
    {
        head = new node(val);
        return ;
    }
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    node* newnode = new node(val);
    temp->next = newnode;

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

void deleteNOde_atKthPos_fromEnd(int k ,node* &head)
{
    int i =0;
    node* p = head;
    node* q = head->next;
    while(i < k)
    {
        q = q->next;
        i++;
    }

    if(q == NULL)
    {
        node* temp = head;
        head = head->next;
        delete(temp);
        return;
    }

    while(q != NULL)
    {
        p = p->next;
        q = q->next;
    }
    node* temp = p->next;
    p->next = temp->next;
    delete(temp);

}



int main()
{
LinkedList f;
f.insertionAt_End(1);
f.insertionAt_End(2);
f.insertionAt_End(3);
f.insertionAt_End(4);
f.insertionAt_End(5);
f.insertionAt_End(6);
f.insertionAt_End(7);
f.insertionAt_End(8);
f.insertionAt_End(9);

f.display();
deleteNOde_atKthPos_fromEnd(4,f.head);
cout << "after deleting 4th node from end "<< endl;
f.display();

    return 0;
}