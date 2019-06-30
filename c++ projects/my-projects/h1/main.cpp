#include <iostream>

using namespace std;


//declaring linkedlists elements
struct node
{
    int data;
    node *next;
};


//declaring linkedlist class
class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    //adding new node to the list and checking
    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    //displaying the list elements
    void display()
    {
        node *tmp;
        tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
     struct node *searchNode(int n )
    {
      node *temp = head;
      int num= 0;
      while (temp->next != NULL)
       {
         if(temp->data==n)
           return temp;
           num++;
         temp = temp ->next;
       }cout << "No Node " << n << " in list.\n";
    }
    void DeleteNode(){
    }
};


//Main function
int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
   // a.display();
    a.add_node(5);
    a.display();
     a.searchNode(11);
    return 0;
}
