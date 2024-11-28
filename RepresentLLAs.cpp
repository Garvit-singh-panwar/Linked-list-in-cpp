// you are given the head of a single LL , the list can be represented as 
// L0 -> L1 -> ------ -> Ln-1 -> Ln ->NULL

// Reorder the list to be on the following form:
// L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ..... -> NULL


#include<iostream>
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
            return;
        }
        node* temp = head;

        while(temp ->next != NULL)
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


node* rearrange_Like_pattern(node* head)
{

node* slow = head;
node* fast = head;

while(fast && fast->next)
{
    slow = slow->next;
    fast = fast->next->next;
}

node* curr = slow -> next;
node* prev = slow;
slow->next = NULL;
while(curr)
{
    node* nexthead = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nexthead;
}

node* head1 = head;
node *head2 = prev;

 while(head1 != head2)
 {  node*temp = head1->next;
    head1->next = head2;
    head1 = head1->next;
    head2 = temp;
 }

 return head;

}



int main()
{
LL f,S;


f.insertion(1);
f.insertion(2);
f.insertion(3);
f.insertion(4);
f.insertion(5);
f.insertion(6);
f.display();

S.head =rearrange_Like_pattern(f.head);
S.display();





    return 0;
}