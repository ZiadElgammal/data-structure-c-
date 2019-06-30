//stack
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;
void printstack(stack<int> s)
{
    //printing content of stack
    while (!s.empty())
    {
        cout << " " << s.top();
        s.pop();
    }
}
int main()
{
    std::stack<int> s1;
    for (int i = 0; i < 20; i++)
        s1.push(rand() % 100);
    std::cout << "stack s1 contains:";
    //print elements
  printstack(s1);//function to avoid deleting elements 

    //search for 21 &20
    int x = 613; //21
    std::cout << "\nsearching for " << x << "\n";
    while (!s1.empty())
    //for (int i = 0; i < 20; i++)
    {
        if (s1.top() == x)
        {
            std::cout << "\nElement Found \n " << std::endl;
            break;
        }
        s1.pop();
      if (s1.empty() == true)
                std::cout
            << "\nelement not found\n"; 
    }
}
