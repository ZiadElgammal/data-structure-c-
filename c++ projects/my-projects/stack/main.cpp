#include <iostream>
#include <cstdlib>


class Node
{
public:
    Node* next;
    int data;
};

using namespace std;

class Stack
{
public:
    int length;
    Node* head;

    Stack();
    ~Stack();
    void add(int data);
    void print();
    void pop();
};

Stack::Stack(){
    this->length = 0;
    this->head = NULL;
}

Stack::~Stack(){
    std::cout << "LIST DELETED";
}

//add element for stack [push element]
void Stack::add(int data){
    Node* node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
}

void Stack::print(){
    Node* head = this->head;
    int i = 1;
    while(head){
        std::cout << i << ": " << head->data << std::endl;
        head = head->next;
        i++;
    }
}

void Stack::pop()  //to remove the top element
{
  Node *temp = new Node();  
 temp = head;
 head = head->next;
}

int main(int argc, char const *argv[])
{
    Stack* s = new Stack();
    // for (int i = 0; i < 100; ++i)
    // {
    //     list->add(rand() % 100);
    // }
    s->add(1);
    s->add(2);
    s->add(3);
    s->add(4);
    s->add(5);
    s->print();
    s->pop(); 
    std::cout << "List Length: " << s->length << std::endl;
   // delete list;
      s->print();
    return 0;
}
