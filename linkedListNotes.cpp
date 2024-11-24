#include<iostream>
using namespace std;
// what is a linkedlist 
// linked list is a linear datastructure used to store a list of values

// difference between array and linkedlist
// array is a single contigious memory blocks 
// [][][][][][][][][][][][]
// in linked list there are multiple memory block linked with each other
// []->[]->[]->[]->[]


// challenges of arrays
// -> static sizing 
// -> contigious memory allocation 
// insertion and deletion takes more time or space O(n)
// 


// Advantages of linked list over an array
// -> dynamic size allocation [101] -- >[204] -- >[643]
                              // address of memory bolcks
// -> non-contigious memory allocation 
// -> insertion and deletion is not expensive
// []->[]->[] x []->[]                _______
//          \   /                    /       \
//            []        []->[]->[]->[]-x>[]-x>[]->[]  
//             ^         ^   ^   ^   ^    ^    ^   ^
//             |         |   |   |   |    |    |   |
//     These blocks of memory are called nodes these nodes have 2 parts
//    memory blocks ->      [Data|nextpointer] 
//  data is value that it is storing    next pointer is pointing to the next node in our linked list it holds the address of next node


// addresses on memory              100            200            400
//                               [10 | 200] - > [20 | 400] - > [30 | null]
//                                 head node                   tail node
// we put a head pointer at the starting of our linked list or at the first node of our linked list with the help of head node we can access every node
// we can not access each node directly . if we want to go to a perticular node we have to go throught each node one by one
// how can we know ending of our linked list
// when we get a node whose next pointer pointing to null we stops because it is the last node in our linked list this node is also called tail node


//  Types of linked list
// 1. Single linked list
// every node is pointing or connected to its successor or next node 
// each node does not know which node comes before them they only know about there next node
//  if we want to go back we can't 

// 2. Doubly linked list
// every node is pointing or connected to is previous & next node in our linked list
// we can also traverse back in our linked list 

// 3. circular linked list 
//  the last node will point to head node it makes a circle beacause each node is connected to each other

// a linked list takes more memory than an array because evry memoryblock of array is = size of datatype but every node in linked list contain size of datatype + the address of next node which make its size bigger

// a doubly linked list takes very large amount of memory because it cotain the size of datatype + address of previous and next node 

// Linked list is a user defined datatype which we made through class or struct(structure). 

// IMPLEMENTATION

class node
{ 
 public: 
int data;  // this data can be of any type it can be an object , string , bool , float , double , char etc
node* nextPtr;

// here we are making a constructor just for illustration
node(int x)
{
    data = x;
    nextPtr = NULL;
}

void insertAt_Head(int , node* &head);
void traversal(node* &head);
void insertAt_End(int , node* &head);
void inssertAt_indx(int ,int  , node* &head);
void update_Val_Atindx(int , int ,node* &head);
void deletionAt_Head(node* &head);
void deletionAt_End(node* &head);
void deletionAt_indx(int , node* &head);
};



// TRAVERSAL IN SINGLE LINKED LIST
//          temp
//           |
//           V
// address  100             300                     400                500
//        [data | 300] -> [data | 400]  - - - - > [data | 500 ] - - > [data | null ]  - - - - - - - -> null
//           ^             ^                        ^                   ^                                ^
//           |             |                        |                   |                                |
//          head        temp->next            temp->next->next     temp->next->next->next       temp->next->next->next->next = null

// to traverse in our linked list we have to use a temp pointer which first points to our head node
// if i want to move to next we make temp = temp next example my temp node is pointing to head node so my temp becomes head -> nextPtr which is next nnode in our linked list 
// when we have to stop 
// we have to stop our traversal when our temp->next points to null because it is our last node in our linked list
void node::traversal(node* &head)
{
    node* temp = head;
    // int i = 0;
    while(temp != NULL )
    {
        cout << "[ "<< temp->data << " | " << temp->nextPtr << " ] " << " - > " ;
        temp = temp->nextPtr;
    }
    cout << " null " << endl;
    delete(temp);
}


// INSERTION IN OUR LINKEDLIST
// ----------------------------
// ---------------------------- 


// INSERTION IN THE HEAD OF LINKED LIST
// adding a node in the start
//      newnode
//       |                          oldnode
//       V
//      [ ]               [ ] - > [ ] - > [ ] -> [ ] -> NULL
//                         ^
//       |                 |
//      newnode->next =  head
//       ^                 |
//       |                 |
//     head = newnode      |
//     head -> next --------
//   now our new node is the head node
//  thats how we add a node in the starting of our linked list
void node :: insertAt_Head(int val , node* &head)
{
    node* new_node = new node(val) ;
    new_node->nextPtr = head;
    head = new_node;
    // timecomplexity O(1)
}



// INSERTION IN THE END OF OUR LINKED LIST
// adding a node in the end
// 
//  temp                             ------------------------ 
//   |      Old_node                 |                        |
//   V                               V                        |
//  [ ] - > [ ] - > [ ] - > [ ] -x> Null                     [ ]----   (new_node->next = null)
//   ^       ^       ^       ^                                ^      
//   |       |  - >  |  - >  |                                |  
//  head    temp    temp  temp->nextptr = null (stops)      new_node   
//   |                                                        |
// temp = temp->nextPtr;     (temp->nextptr =  new_node)-------
// 
//  
void node::insertAt_End(int val , node* &head)
{
    node* temp = head;
    node* new_node = new node(val);
    while(temp->nextPtr != NULL)
    {
        // if(temp->nextPtr == NULL)break;
        temp = temp->nextPtr;
    }
    temp->nextPtr = new_node;
    // already null because of constructor
    // new_node->nextPtr = NULL ;
    // delete(temp);

        // timecomplexity O(n)
}


//  INSERT NODE AT AN ARBITARYT POSITION
//  adding a node to a arbitary position
                
//                            
//   p = head   q = p->next 
// 
//      p          q        p           q  (stop)
//      | \        |  \  /  |        _/ |
//      |  \       |   \/   |      _/   |
//      |   \      |   /\   |    _/     |
//      V    \     V  /  \  V   /       V
//            \      /    \    /
//indx  0      \  1 /      \2 /         3         4
//     [ ]  - >  [ ]  - >  [ ]  --X--> [ ]  - >  [ ] - > null               
//      ^         ^       / ^  newindx  4  \      5
//      |         |      /  |               \      
//    head        p     /   q                \   
//                     /                      \
//                    /                        \
//                   /            3             \
//                  /------------[ ]-------------\
//                 /           new_node           \
//                /            new_node->nextptr = q;
//                p->nextptr = new_node


void node::inssertAt_indx(int val , int indx , node* &head)
{
    if(indx == 0)
    {
        insertAt_Head(val , head);
        return;
    }
    node* p = head;
    node* q = head->nextPtr;
    node* new_node = new node(val);
    int i = 1;
    
    while(i < indx && q != NULL )
    {
        p = p->nextPtr;
        q = q->nextPtr;
        i++;
    }


    new_node->nextPtr = q;
    p->nextPtr = new_node;
    // timecomplexity O(n)
}

// UPDATING VALUE AT THE INDX
// ---------------------------
// ---------------------------


// pointer   temp    temp ( temp = givenIndx) (stop) 
//             |  ->  | ->   | 
//             V      V      V
// indx        0      1      2      3
//            [ ] -> [ ] -> [ ] -> [ ] -> null
//             ^             ^
//             |             |
//            head       temp->val = givenvalue
// 
// 

void node::update_Val_Atindx(int val,int indx , node* &head)
{
    node* temp = head;
    int i = 0;
    while(i < indx && temp != NULL)
    {
        temp = temp->nextPtr;
        i++;
    } 
    if(temp == NULL)
    {
        cerr << "Wrong Indx " << endl;
        return;
    }
    temp->data = val;
    // timecomplexity O(n)

}



// DELETEION IN OUR LINKEDLIST
// ------------------------------------------
// ------------------------------------------




// DELETION AT THE HEAD OF OUR LINKED LIST
//  delete a node at the start
//      head
//       |     (head = head->next;)
//       V         V
//      [ ] -x- > [  ] -- > [  ] - - >null
//       ^          ^
//       |          |
//      temp       head 
//  delete(temp);

void node::deletionAt_Head(node* &head)
{
    node* temp = head; // node to be ldeleted
    head = head->nextPtr;
    delete(temp);
    // timecomplexity O(1)
}



// DELETION AT THE END OF OUR LINKED LIST
//   delete a node from the end
//      head       q         q
//       |         |         |       (q = p->next) (stop when q->next=null)
//       V         V         V
//      [ ] -x- > [  ] -- > [ ]->null
//       ^          ^ \         /
//       |          |  \       /
//       p          p   \     /
//  p->next = null;      \   /
//  delete(q);          p->next;


void node::deletionAt_End(node* &head)
{
    node* p =head;
    node* q = p->nextPtr;
    while(q->nextPtr != NULL)
    {
        p = p->nextPtr;
        q = q->nextPtr;
    }
    p->nextPtr = NULL;
    delete(q);
    // timecomplexity O(n)
}


// DELETION AT AN ARBITARY POSITION
//  delete a node at an arbitary position
//             head       q         q                                       i=2
//              |         |         |                  (q = p->next) (stop when i = indx-1)
//              V         V         V                     
//  indx        0         1         2        3
//             [ ] -x- > [  ] -x-> [ ] -x-> [  ] - > NULL
//  newindx     0          1        X        2  
//              ^          ^ \             / 
//              |          |  \           /
//              p          p   \         /
//         p->next = q->next    \       /
//         delete(q);            p->next = q->next;

void node::deletionAt_indx(int indx , node* &head)
{
    if(indx == 0)
    {
        head->deletionAt_Head(head);
        return;
    }
    node* p = head;
    node* q = p->nextPtr;
    int i = 0;
    while( i < indx-1 && q != NULL)
    {
        p = p->nextPtr;
        q = q->nextPtr;
        i++;
    }
    if(q == NULL)
    {
        cerr << "wrong indx" << endl;
        return;

    }
    p->nextPtr = q->nextPtr;
    delete(q);
}



int main()
{




// this show data and nextpointer
// Uncomment and check;
//          |
//          V

// node *head = new node(3);
// cout << " data in head pointer or head node " << head->data << endl <<" address of head pointer or head node " << head->nextPtr  <<  endl;

//    ^
//    |
// comment back

// cout << endl ;

// this show traversal and insertion in the head
// Uncomment and check
//      |
//      V 

// node *head = new node(3);
// head->traversal(head);
// head->insertAt_Head(2,head);
// head->traversal(head);
// head->insertAt_Head(1,head);
// head->traversal(head);

//       ^    
//       |   
//     coment back  


// this will show traversal and insertion at end
//  uncomment and check 
//       |
//       V

//  node *head = new node(1);
//  head->traversal(head);
//  head->insertAt_End(2, head);
//  head->traversal(head);
//  head->insertAt_End(3,head);
//  head->traversal(head);


//         ^
//         |
//      comment back


//  This will show traversal and insertion at an arbitary position 
// uncomment and check

//  node *head = new node(1);
//  head->traversal(head);
//  head->insertAt_End(2, head);
//  head->traversal(head);
//  head->insertAt_End(3,head);
//  head->traversal(head);
//  head->inssertAt_indx(4,2,head);
//  cout << "here we are using insertion at indx function " << endl;
//  head->traversal(head);

//  comment back


// This will show traversal insertion and updation of value 
// uncomment and check

//  node *head = new node(1);
//  head->traversal(head);
//  head->insertAt_End(2, head);
//  head->traversal(head);
//  head->insertAt_End(3,head);
//  head->traversal(head);
//  head->inssertAt_indx(4,2,head);
//  cout << "here we are using insertion at indx function " << endl;
//  head->traversal(head);
//  head->update_Val_Atindx(3,2,head);
//  cout << "here we are updating the value at perticular indx " << endl;
//  head->traversal(head);
//  head->update_Val_Atindx(4,3,head);
//  head->traversal(head);

// This will show traversal Insertion and deletion
// uncomment and check

// node *head = new node(2);
// cout << "Here we start inserting the elements by various insertion functions " << endl;
// head->traversal(head);
// head->insertAt_Head(1,head);
// head->traversal(head);
// head->insertAt_End(4,head);
// head->traversal(head);
// head->inssertAt_indx(3,2,head);
// head->traversal(head);
// cout << "here we start deleting the elements using various deletion functions " << endl;
// head->deletionAt_indx(2,head);
// head->traversal(head);
// head->deletionAt_Head(head);
// head->traversal(head);
// head->deletionAt_End(head);
// head->traversal(head);

// comment back
    return 0;
}