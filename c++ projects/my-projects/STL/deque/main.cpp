//deque
#include <iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main()
{
    std::deque<int> q1; // declearedeque q1
    for (int i = 0; i < 20; i++)
        q1.push_back(rand() % 100); //push 20 random integers from the end 
    std::cout << "q1 contains:";    //return elements using iterator
    for (auto i = q1.begin(); i != q1.end(); ++i)
        std::cout << *i << " ";

        //remove elements at index 3   
    q1.erase(q1.begin() + 3); 

 //return all elements with iterator
 std::cout << "\nq1 contains:";  
    for (auto i = q1.begin(); i != q1.end(); ++i)
        std::cout << *i << " ";

        // sort deque
std::stable_sort(q1.begin(),q1.end()); cout<<"\n sorted v1:";
for (auto i = q1.begin(); i != q1.end(); ++i)
        std::cout << *i << " ";
        cout<<"\n";

        // search for an element that exists
 std::deque<int>::iterator it = std::find(q1.begin(),q1.end(),92);
 int index = std::distance(q1.begin(), it);
if (it != q1.end())
	std::cout << "Element Found at index "<< index << std::endl;
else
	std::cout << "Element Not Found" << std::endl;

//search for an element that doesn't exists 
 it = std::find(q1.begin(),q1.end(),2000);
if (it != q1.end())
	std::cout << "Element Found at index"<<index << std::endl;
else
	std::cout << "Element Not Found" << std::endl;
    return 0;
}
