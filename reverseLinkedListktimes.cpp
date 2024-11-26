// Givern a head of a linked list , reverse the nodes of the list k at a time , and return the modified list 

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


//  this is what i first made
// node* Reverse_KNodes(int k , node* &head)
// {

// if( head == NULL ) //&& head->next == NULL) that what i did wrong
// {
//     return head;
// }


// int i = 0;
//  node* current = head;
//  node* prev =  NULL;
// while(current && i < k )  // && current->next != NULL) thats what i did wrong
// {
    
//       node* nexthead = current->next;
//        current->next = prev;
//        prev = current;
//        current = nexthead;
//       i++;
    
    
// }
//     if(current != NULL){
//     head->next = Reverse_KNodes( k , current);
//     }
//     return prev;

// }



node* Reverse_KNodes(int k, node* &head) {
    // Base case: if the list is empty or if fewer than k nodes remain
    // means if we give k = 1 in our function so we dont have to use recursion or do any thing k == 1 handle that type of case
    // we directly return head
    if (head == NULL || k == 1)  
    {
        return head;
    }

    node* current = head;
    node* prev = NULL;
   
    int count = 0;

    // Reverse the first k nodes
    while (current != NULL && count < k) {
        node* next = current->next;  // Save the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move prev one step forward
        current = next;        // Move current one step forward
        count++;
    }

    // After reversing k nodes, head will point to the last node of the reversed group
    // Recursively call for the next set of nodes (remaining part of the list)
    if (current != NULL) {
        head->next = Reverse_KNodes(k, current);  // Link the reversed part with the rest of the list
    }

    // prev is the new head of the reversed group of k nodes
    return prev;
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
f.display();

f.head = Reverse_KNodes(2 , f.head);
f.display();





    return 0;
}