/* C++ program to implement basic stack operations using array
   https://www.geeksforgeeks.org/stack-data-structure-introduction-program/ */
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

class Stack
{
    //int top;

  public:
    int a[MAX]; //Maximum size of Stack
    int top;
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    bool isEmpty();
    void getTop(Stack);
    void copy(Stack);
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}
void Stack::copy(Stack stack)
{
    int copy[top];

       copy[++top] = stack.top;
       cout<<"stack copied "<< stack.pop();
    
}
void Stack::getTop(Stack stack)
{
    if (top < 0){cout<<"stack is empty";}
    cout<<"the top element in the stack is "<<stack.pop();
}

// Driver program to test above functions
int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
   // s.copy(s);
    s.getTop(s);
   // cout << s.pop() << " Popped from stack\n";
    return 0;
}