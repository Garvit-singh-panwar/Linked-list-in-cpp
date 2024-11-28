// Given head of a linked list 
// determine if the LL has a cycle and remove the cycle from it 





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
node* head ;
node* end;
LL()
{
    head = NULL;
    end = NULL;
}


void insertion(int val)
{
    if(head == NULL)
    {
        head = new node(val);
        end = head;
        return;
    }

    end->next = new node(val);
    end = end->next;

}


void display()
{

node* temp = head;

while(temp != NULL)
{
    cout <<  temp-> data <<" -> ";
    temp = temp->next;

}
cout << "NULL" << endl;

}


};


// here is the procedure hoe this function works 
// here no are the iterations men on which iteration where our pointer points

// 
//                          |  cycle |  second meet
//                          |starting| / Firstmeet
//                                    /  /
//             f      4f      5s,f---|  |      4s
//                                     3f -| here first they both meet |  and then both pointer takes single steps the second time 
//                             2s      3s -| then we make fast = head  |  when they both meet is the point where our cycle starts
//            0s,f     1s      1f              2f
//            [ ] - > [ ] - > [ ] - > [ ] - > [ ] ->| 
//                             |                    |
//                             |<------------<-------
// 

void removeCycle(node* head)
{

node* slow = head;
node* fast = head;

do
{
 slow = slow->next;
 fast = fast->next->next;

}while(slow != fast);

fast = head;

while(slow->next != fast->next)
{
    slow = slow->next;
    fast = fast->next;
}

slow->next = NULL;

}




int main()
{

LL f;
f.insertion(1);
f.insertion(2);
f.insertion(3);
f.insertion(4);
f.insertion(5);
f.end->next = f.head->next->next;
removeCycle(f.head);
f.display();





    return 0;
}