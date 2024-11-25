// Given the head of a linked list , delete every alternate element from the List starting from the second element

// linked list = [1]->[2]->[3]->[4]->[5]->null
// resultant linked list = [1]->[3]->[5]->null


#include<iostream>
using namespace std;


class node
{
    public:
    int data;

    node* next_ptr;
    node(int val)
    {
        data = val;
        next_ptr = NULL;
    }

};

// making a class linked list for abstraction
// we don't have to pass head pointer to every function 
// It makes our work easy

class LinkedList
{

public:
node* head;

LinkedList()
{
    head = NULL;
}

void insertAt_Tail(int val)
{
    if(head == NULL)
    {
       head = new node(val);
       return ;
    }
    node* temp = head;
    node* new_node = new node(val);
    while(temp->next_ptr != NULL)
    {
        temp = temp->next_ptr;
    }
    temp->next_ptr = new_node;
}

void display()
{
    node* temp = head;
    // int i = 0;
    while(temp != NULL )
    {
        cout << "[ "<< temp->data << " | " << temp->next_ptr << " ] " << " - > " ;
        temp = temp->next_ptr;
    }
    cout << " null " << endl;

}




};


// using this function we are deleting alternate elements from our linked list
void delete_Alternate_Nodes(node* &head)
{
    node* current = head;
    while(current !=NULL && current->next_ptr != NULL)
    {
        node* temp = current->next_ptr;

        // current->next = current->next->next
        current->next_ptr = temp->next_ptr;

        delete(temp);

        // current = current->next->next
        current = current->next_ptr;

    }
}


int main ()
{

LinkedList first;
first.insertAt_Tail(1);
first.insertAt_Tail(2);
first.insertAt_Tail(3);
first.insertAt_Tail(4);
first.insertAt_Tail(5);
first.insertAt_Tail(6);
first.display();
delete_Alternate_Nodes(first.head);
first.display();




    return 0;
}