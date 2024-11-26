// Given the head of the single Linked list print the reversed list?

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

class LinkedList
{

public: 
node* head;

LinkedList()
{
    head = NULL;                                     
}

void Insertion_End(int val)
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
    node* newNode = new node(val);
    temp->next = newNode ;

}


void display()
{
    node* temp = head;
    while(temp)
    {
        cout << temp->data << " - > ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

};

void printInReverse(node* &head)
{
    
    if(head == NULL)
    {
        cout<< "NULL ";
        return;

    }
    printInReverse(head->next);
    cout<< " - >  " << head->data ;
    return;

}



int main()
{

LinkedList F;
F.Insertion_End(1);
F.Insertion_End(2);
F.Insertion_End(3);
F.Insertion_End(4);
F.display();
printInReverse(F.head);






    return 0;
}