//priorty queue
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
void printPriorityQueue(priority_queue<int> q)
{
    //printing content of queue
    std::cout << "queue contains:";
    while (!q.empty())
    {
        cout << " " << q.top();
        q.pop();
    }
}

int main()
{
    std::priority_queue<int> q;
    for (int i = 0; i < 20; i++)
        q.push(rand() % 100); //push 20 random integers
    printPriorityQueue(q);    // functionto avoid deleting the original queue

    //SEARCH
    int x = 93;
    while (!q.empty())
    {
        if (q.top() == x)
        {
            std::cout << "\nelement found";
            break;
        }
        q.pop();
        if (q.empty() == true)
            std::cout << "\nelement not found";
    }

    return 0;
}
