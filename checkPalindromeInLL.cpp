// given head , the head of a linked list determine if the LL is a palindrome or not 

//  1 -> 2 -> 3 -> 3 -> 2 -> 1 ->NULL 
// if the data LL from head to middile or from end to middle looks same then the LL is palandrom 

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

class ll
{
public:
node* head;

ll()
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
        temp= temp->next;

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

bool Is_Palindrome(node* head)
{

    node* slow = head;
    node* fast = head;

    // here slow comes in the middle
    while(fast->next!= NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //  we are reversing the  list from middle to end
    node* curr = slow->next;
    node* prev = slow;
    slow->next = NULL;

    while(curr!=NULL)
    {
        node*nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;

    }

// we are making 2 heads one start from first and second starts from end
    node* head1 = head;
    node* head2 = prev;

// we are checking that the list is palindrome or not
    while(head2)
    {
        if(head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
}
int main()
{

ll f;
f.insertion(1);
f.insertion(2);
f.insertion(3);
f.insertion(4);
f.insertion(1);
f.display();
cout << Is_Palindrome(f.head);



}
