// Find middle element of a given LL in one traversal

#include<iostream>
using namespace std;

class node 
{
    public:
    int data;
    node* next ;

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
    node* End;
    LL()
    {
        head = NULL;
        End = NULL;
    }


    void insertionAt_End(int val)
    {

        if(head == NULL) 
        {
            head = new node(val);
            End = head;
            return;
        }
        End->next = new node(val);
        End = End->next;
        //here time complexity of insertion in end is O(1);

    }

    void insertionAt_head(int val)
    {
        if(head == NULL)
        {
            head = new node(val);
            End = head;
            return;
        }
        node* newnode = new node(val);
        newnode ->next = head;
        head = newnode;
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


node* Find_MiddleEle(node* head)
{
    int p = 0;
    int q = 0;
    node* temp = head;
    node* middle = head;
    while( temp != NULL)
    {
        temp = temp->next;
        p++;
        while(q != p/2)
        {
            middle = middle->next;
            q++;
        }
        
    }

    return middle;
}



int main()
{

    LL f;
    f.insertionAt_End(1);
    f.insertionAt_End(2);
    f.insertionAt_End(3);
    f.insertionAt_End(4);
    f.insertionAt_End(5);
    f.insertionAt_End(6);
    f.insertionAt_End(7);
    f.display();
    cout << "middle ele is  " << Find_MiddleEle(f.head)->data;







    return 0;
}