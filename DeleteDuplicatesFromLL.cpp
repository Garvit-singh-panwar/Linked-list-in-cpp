// Given the head of a sorted linked list ,
//  delete all duplicates such that each element appers only once .
//  return the linked list sorted as well 

// this is sorted linked list
// linked list = 1 - 1 - 2 - 2 - 3 - 3 - 4 - null ;
// resultant list = 1 - 2 - 3 - 4 - null





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
    node *head;

    LinkedList()
    {
        head = NULL;
    }


    void insertAt_head(int val)
    {
        if(head == NULL)
        {
            head = new node(val);
            return ;
        }
        node* new_node = new node(val);
        new_node->next = head;
        head = new_node;

    }

    void insertAt_Tail(int val)
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
        node* newnode = new node(val);
        temp->next = newnode;
    }


    void Display()
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


void delete_Duplicates_From_LL(node* &head)
{

    node* temp = head;
    while(temp!= NULL && temp->next != NULL)
    {
        if(temp->data == temp->next->data)
        {
            node* duplicate = temp->next;
            temp->next = duplicate->next;
            delete(duplicate);
        }
        else
        {

            // if temp -> data != Temp->next->data then we make temp = temp->next
            // because if temp->data == temp->next->next->data then we cannot delete all dulplactes
            temp = temp->next;
        }
    }


}



void delete_Duplicates_From_LL2(node* &head)
{
    node*temp = head;
    while(temp)
    {
        while(temp->next != NULL && temp->data == temp->next->data)
        {
            node* duplicate = temp->next;
            temp->next = duplicate->next;
            delete(duplicate);
        }
        temp = temp->next;
    }

}


int main()
{

LinkedList F;
F.insertAt_Tail(1);
F.insertAt_Tail(1);
F.insertAt_Tail(2);
F.insertAt_Tail(3);
F.insertAt_Tail(3);
F.insertAt_Tail(3);
F.Display();
// delete_Duplicates_From_LL(F.head);
delete_Duplicates_From_LL2(F.head);
F.Display();







    return 0;
}