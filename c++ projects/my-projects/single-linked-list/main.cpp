
#include <iostream>
#include <cstdlib>

class Node
{
  public:
    Node *next;
    int data;
};

using namespace std;

class LinkedList
{
  public:
    int length;
    Node *head;
    Node *tail;

    LinkedList();                         //constructor
    ~LinkedList();                        //destructor
    void add(int data);                   // to inserst a new node at the end of the linked list
    void insertNode(int index, int data); //add a node at a specific index and shifts the all following nodes
    void print();                         // to display linked list elements
    void deleteList();                    //to delete the whole linked list
    void deleteNode(int index);           // to delete a specific node of the linked list using its index
    int searchNode(int data);            //seach and return node index
    void reverseList();                   // to reverse the elements of the linked list
    void swap(int index1, int index2);    //to swap 2 nodes in the list by swaaping their data
    void findMax();                       //find maxmium value in the list
    void findMin();                       // find minimum value in the list
    void sort();                          //sort list elements assending
    void compareLists();                  //compare 2 linked listes
    void insertZero(int num, int index);  //insert zeros elments at certain indexand shift others
   int findOccurrences(int k); //search and count how many times a specific element appeared in the list
};

//constructor
LinkedList::LinkedList()
{
    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
}

//destructor
LinkedList::~LinkedList()
{
    std::cout << "LIST DELETED";
}

void LinkedList::add(int data)
{
    Node *node = new Node();
    node->data = data;
    if (length == 0)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        this->tail = node;
    }
    this->length++;
}
void LinkedList::insertNode(int index, int data)
{
    Node *current = head;
    Node *temp = new Node();
    temp->data = data;
    // cout << endl
    //    << temp->data << endl;
    //if the node inserted is the head
    if (index == 0)
    {
        temp->next = current;
        head = temp;
        exit;
    }
    // Find previous node(current) of the node to be inserted (temp)
    else if (index >= 1)
    {
        for (int i = 0; current != NULL && i < index - 1; i++)
        {
            current = current->next;
        }

        if (current->next == NULL) //if we need to add tail node
        {
            // cout << current->data << endl;
            tail->next = temp;
            //cout << temp->data << endl;
            temp->next = NULL;
            tail = temp;
            // cout << tail->data << endl;
            exit;
        }
        //if the node is in the middle
        if (index > 0 && index < length)
        {
            temp->next = current->next;
            current->next = temp;
            exit;
        }
    }
}

void LinkedList::insertZero(int num, int index)
{
    Node *current = head;
    Node *temp = new Node();
    temp->data = 0;
    if (index == 0) //if we add zeros at the head index
    {
        int i = 0;
        for (int i = 0; i < num; i++)
        {
            this->insertNode(0, 0);
            this->length++;
            // temp->next = current;
            // head = temp;
            exit;
        }
        exit;
    }
    else if (index == this->length - 1) //if we need to add tail node

    {
        for (int i = 0; i < num; i++)
        {
            this->insertNode(this->length, 0);
            this->length++;
        }
    }
    else if (0<index<this->length -1)
    {
        for (int i = 0; i < num; i++)
        {
            this->insertNode(index, 0);
            this->length++;
        }
    }
    
}
//print elements  [like a s]
void LinkedList::print()
{
    Node *head = this->head;
    int i = 1;
    while (head)
    {
        std::cout << i << ": " << head->data << std::endl;
        head = head->next;
        i++;
    }
}

void LinkedList::deleteList()
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current->next;
        //free(current);
        delete current;
        current = temp;
    }
}

void LinkedList::deleteNode(int num)
{
    Node *temp;
    Node *current = head;
    //if head needs to be removed
    if (num == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    // Find previous node(current) of the node to be deleted (temp)
    else if (num >= 1)
    {
        for (int i = 0; current != NULL && i < num - 1; i++)
        {
            current = current->next;
        }

        if (current->next->next == NULL) //if we need to remove tail node
        {
            temp = current->next;
            //cout<< temp->data <<endl;
            delete temp;
            temp->next = NULL;
            tail = current;
            //cout << tail->data <<endl;
            exit;
        }
        //if the node is in the middle
        temp = current->next; //temp = node that we need to remove
        current->next = current->next->next;
        delete temp;
    }
}

void LinkedList::reverseList()
{
    Node *current = head;
    Node *next = NULL;
    Node *previous = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

int LinkedList::searchNode(int data)
{
    Node *current = head;
    Node *temp = NULL;
    int index;
    for (index = 0; current != NULL; index++)
    {
        if (current->data == data)
        {
            temp = current;
            cout << "data found at index = " << index<<"\n";
            return 1;
            exit;
        }

        current = current->next;
    }
    if (temp == NULL)
    {
        cout << "data not found \n";
        return -1;
    }

    // while(current != NULL)
    // {
    //  if (current->data == data) {
    //      cout<< "data found at index = "<<index;
    //      exit ;
    //  }
    //     current = current->next;
    //     index++;
    // }
}

int LinkedList::findOccurrences(int k)
 {//Node *current = head;
// int num =0;
//     if (head ==NULL)
//     {
//         return -1;
//     }
//     else{
//        searchNode(k);
//        return int i;
        
//     }
    Node *current = head;
    Node *temp = NULL;
    int index;
    for (index = 0; current != NULL; index++)
    {
        if (current->data == k)
        {
            temp = current;
            return 1;

            }

        current = current->next;
    }
    if (temp == NULL)
    {
        
        return -1;
    }
            
    
}

void LinkedList::swap(int index1, int index2)
{

    Node *temp1 = head;
    Node *temp2 = tail;
    Node *current = head;
    //swap head with tail
    if (index1 == 0 || index1 == length - 1) // if index 1 is head or tail
    {
        if (index2 == length - 1 || index2 == 0)              //if index 2 is head or tail
        {                                                     //to swap head with tail
            for (int i = 0; current->next->next != NULL; i++) // to stop at the node previous to tail
            {
                current = current->next;
            }
            temp2->next = temp1->next;
            current->next = temp1;
            temp1->next = NULL;
            head = temp2;
            tail = temp1;
            exit;
        }
    }
    else if (length > index1 > 0 && length > index2 > 0) //if index1 or 2 is between head and tail
    {
        for (int i = 0; i < index1; i++)
        {
            current = current->next;
        }
        cout << "index1(current) =" << current->data;
        for (int j = 0; j < index2; j++)
        {
            temp1 = temp1->next;
        }
        cout << "\n swapping :" << temp1->data << "\n";
        int a = current->data;
        cout << "\n a=  " << a;
        current->data = temp1->data;
        cout << "\n with : " << temp1->data << "\n \n";
        temp1->data = a;
        // if (current->next ==NULL){ tail = current; }
        // else if (temp1->next ==NULL){tail = temp1;}
        
        exit;
    }
    //if we want to swap head or tail with any middle node
    
}

void LinkedList::findMax()
{
    Node *current = head;
    int max = head->data;
    for (int i = 0; i < length; i++)
    {
        if (current->data >= max)
        {
            max = current->data;
        }
        current = current->next;
    }
    cout << "\n the maxmium value in the list is: " << max << "\n\n";
}

void LinkedList::findMin()
{
    Node *current = head;
    int min = head->data;
    for (int i = 0; i < length; i++)
    {
        if (current->data <= min)
        {
            min = current->data;
        }
        current = current->next;
    }
    cout << "\n the minimum value in the list is: " << min;
}

void LinkedList::sort()
{
    Node *current = head;
    for (int i = 0; i <= length - 1; i++)
    {
        if (current->data >= current->next->data)
        {
            // cout<<"i index ="<<i<<"and i++ = " <<i+1;
            swap(i + 1, i);
            cout << "\n i= " << i;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char const *argv[])
{
    LinkedList *list = new LinkedList();
    LinkedList *list2 = new LinkedList();
    //  for (int i = 0; i < 100; ++i){list->add(rand(int(10)) % 100);}
    list->add(00);
    list->add(10);
    list->add(20);
    list->add(30);
    list->add(40);
    list->add(50);
       list->add(60);
           list->add(50);


    cout << endl;
    list->print();
    std::cout << "List Length: " << list->length << std::endl;
    //delete list;
    cout << endl;
     //list->deleteList();
    // list->insertNode(7, 17);
    //list->print();
    //list->reverseList();
    // list->deleteNode(1);
    // list->swap(3,6);
    //list->insertZero(3, 3);
        std::cout << "List Length: " << list->length << std::endl;
    //     list->insertNode(2,0);
   //  list->findMin();
  //  list->findMax();
    // list->sort();
   // list->print();
    //list->searchNode(2555);
   // cout<<list->findOccurrences(50);
    cout <<list->findOccurrences(50);

    return 0;
}
