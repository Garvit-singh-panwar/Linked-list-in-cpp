// Given the head of a single linked list 
//  group all the node with odd indices together followed by the nodes with even indices 
//  and return the reordered list

#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

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

    void insertion(int val)
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

        while(temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

};


node* rearrangeList_oldIndices_FollowEven(node* &head)
{

if(head == NULL) return NULL;

node* oddhead =head;
node* evenhead = head->next;
node* odd = oddhead;
node* even = evenhead;

while(odd->next && even->next)
{
    odd->next = odd->next->next;
    odd = odd->next;
    even->next = even->next->next;
    even = even->next;
}
odd->next = evenhead;
return oddhead;

}

int main()
{

LinkedList l , m;

l.insertion(1);
l.insertion(2);
l.insertion(3);
l.insertion(4);
l.insertion(5);
l.insertion(6);
l.display();

m.head =rearrangeList_oldIndices_FollowEven(l.head);

m.display();




    return 0;
}