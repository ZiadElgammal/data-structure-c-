//queue
#include <iostream>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;

void printQueue(queue<int> q)
{
    //printing content of queue
    std::cout << "queue contains:";
    while (!q.empty())
    {
        cout << " " << q.front();
        q.pop();
    }
}

int main()
{
    std::queue<int> q; // declearedeque q1
    for (int i = 0; i < 20; i++)
        q.push(rand() % 100); //push 20 random integers 
    printQueue(q);            // functionto avoid deleting the original queue
    
    //sort
    std::list<int> l; //use a list to copy queue in it and sort it 
    while (!q.empty())
    {

        for (int i = 0; i < 20; i++)
        {
            l.push_back(q.front());
            q.pop();
        }
        cout << "\nsorted queue: ";
        l.sort();
        for (auto i = l.begin(); i != l.end(); ++i)
            std::cout
                << *i << " ";
        cout << "\n";
    }
    for (auto i = l.begin(); i != l.end(); ++i)//copying sorted elements from list 
        q.push(*i);
    printQueue(q);

//search
int x=93;//125
 list<int>::iterator it = l.begin();
it = std::find(l.begin(),l.end(),x);
if (it != l.end())
	std::cout << "\nElement Found  " << std::endl;
else
	std::cout << "\nElement Not Found" << std::endl;

    return 0;
}
