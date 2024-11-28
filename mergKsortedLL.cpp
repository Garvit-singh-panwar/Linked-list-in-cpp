// you are given an array of k linked-list least , each linked list is sorted in ascending order.
// merge all the linked list into one sorted linked list and return it  

#include<iostream>
#include<vector>
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

} ;



class linkedlist 
{

public:
node* head;

linkedlist()
{
    head = NULL;
}

void insertion(int val)
{
    if(head == NULL)
    {
        head = new node(val);
        return ;
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

    while(temp != NULL)
    {
            cout << "[ "<< temp->data << " | " << temp->next << " ] " << " - > " ;
        temp = temp->next;
    }
    cout << " null " << endl;
}

};



node* merge_two_LL(node* &f,node* &s)
{
    node* Dummy_head = new node(-1);

    node* p = f;
    node* q = s;
    node* r = Dummy_head;

    while(p != NULL && q != NULL)
    {
        if(p->data < q->data)
        {
            r->next = p;
            r = r->next;
            p = p->next;

        }
        else
        {
            r->next = q;
            q = q->next;
            r = r->next;
        }

    }

    while(q != NULL )
    {
        r->next = q;
        r = r->next;
        q = q->next;
    }
    while(p != NULL)
    {
        r ->next = p;
        r = r->next;
        p = p->next;
    }

    node* temp =Dummy_head;
    Dummy_head = Dummy_head->next;
    delete(temp);
    return Dummy_head;

}



node* merge_K_LL( vector <node*> &KLL , int k)
{
    //base case here if  k == 0 means we have to merge 0 node 
    //KLL.size() == 0 means there are heads of nodes present in our KLL if no head is present then what we merge
    if(k==0  && KLL.size() == 0)return NULL ;
    node* dummy_head = KLL[0];
    int j = 1;
    while( j < k  && j < KLL.size()) //this j < KLL.size is for error handling
    {
        dummy_head = merge_two_LL(dummy_head,KLL[j]);
        j++;
    }
    return dummy_head;

}


node* merge_K_LL2(vector <node*> &KLL)
{
    if(KLL.size() == 0 )//when there is no LL
    {
        return NULL;
    }

    while(KLL.size()>1)
    {
        node* mergedhead = merge_two_LL(KLL[0],KLL[1]); //here we are merging starting two LL
        KLL.push_back(mergedhead); // here we are giving the head of the merged LL and push it in our KLL vector array
        KLL.erase(KLL.begin()); //here we are deleting our 1st LL from Array
        KLL.erase(KLL.begin()); // here we are deleting the 2nd LL from array
        //we return wen there is only 1 head left in LL and we return that head
    }

    return KLL[0]; 
}

int main()
{

linkedlist f ,s,t,fr , merged;

f.insertion(1);
f.insertion(2);
f.insertion(5);
f.insertion(9);
f.display();

s.insertion(3);
s.insertion(4);
s.insertion(6);
s.insertion(7);
s.display();

t.insertion(8);
t.insertion(10);
t.insertion(15);
t.insertion(18);
t.display();

fr.insertion(11);
fr.insertion(12);
fr.insertion(13);
fr.insertion(20);
fr.display();

vector <node*> MultipleLL = {f.head,s.head,t.head,fr.head};

// Uncomment to check the function and uncomment 1 at a time 

// merged.head = merge_K_LL(MultipleLL , 3);
// merged.head = merge_K_LL2(MultipleLL);
merged.display(); 
 
    return 0;
}