// Given the head of a single Linked list revrse the list and return the reversed list 

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



// This is a recursive function of reversing a linked list 

node* Reverse_A_LinkedList(node* &head , node* temp = NULL)
{

if(head == NULL)
{
    
    return temp;
}

node* nextHead = head->next;
head->next = temp;
return Reverse_A_LinkedList(nextHead , head);

}


node* reverse_A_LinkedList(node* &head)
{
    node* prevNode =NULL;
    node* currentNode = head;
    while( currentNode != NULL)
    {
        node* nexthead = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nexthead; 
    }

    return prevNode;

}

node* reverseLLRecursion(node* head)
{

    if(head == NULL || head ->next == NULL)return head;
    // recursive case
    node* newhead = reverseLLRecursion(head->next);
    head->next->next = head;
    head->next = NULL; // head is now pointing to last node in reversed ll    
    return newhead;

}

//                                          ^
//                                          |
// these process repeats multiple times in this function at the end we return newhead 
// 
//                                 next----------------------|
//                                  |                        |
//                                  |   ----|                |
//                                  |   |   |                |
//                                  |   |  next--------------|
//                                  |   |   |    --next      |
//                                  |   |   |    |   |       V
// 0     [ ]      [ ]      [ ]     [ ]---   [ ]---  [ ]     NULL
//                                                   ^
// 1                                ^       ^      head (return)
//                                  |       |       ^
// 2                                |      head   newhead
//                                  |             head->next->next = head; (new node->next = head)
//                                  |      head->next = NULL
//                                  |      return newhead
//                                  |                |
//                                  |       |        |
// 3                               head     |     newhead
//                                        head->next->next = head
//                                head->next = NULL;
// 
// 
// 



int main()
{

LinkedList f;
f.insertAt_Tail(1);
f.insertAt_Tail(2);
f.insertAt_Tail(3);
f.insertAt_Tail(4);
f.insertAt_Tail(5);
f.insertAt_Tail(6);
f.insertAt_Tail(7);
f.Display();
// this is a recursive function
// f.head = Reverse_A_LinkedList(f.head);
// f.Display();
// it is not a recursive function
// f.head = reverse_A_LinkedList(f.head);
// f.Display();
f.head = reverseLLRecursion(f.head);
f.Display();
    return 0;
}