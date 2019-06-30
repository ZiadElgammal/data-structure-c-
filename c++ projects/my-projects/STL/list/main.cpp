//list
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    std::list<int> l1;
    for (int i = 0; i < 20; i++)
        l1.push_back(rand() % 100);
    std::cout << "l1 contains:"; //return elements using iterator
    for (auto i = l1.begin(); i != l1.end(); ++i)
        std::cout << *i << " ";

    //remove elements at index 3
    list<int>::iterator it = l1.begin();
    advance(it, 3);
    it = l1.erase(it);
    //print elements again
    std::cout << "\nl1 contains:";
    for (auto i = l1.begin(); i != l1.end(); ++i)
        std::cout << *i << " ";

    // sort list
    l1.sort();
    //std::stable_sort(l1.begin(),l1.end());
    cout << "\n sorted l1:";
    for (auto i = l1.begin(); i != l1.end(); ++i)
        std::cout << *i << " ";
    cout << "\n";

    // search for an element that exists
  it = std::find(l1.begin(),l1.end(),92);
 int index = std::distance(l1.begin(), it);
if (it != l1.end())
	std::cout << "Element Found at index "<< index << std::endl;
else
	std::cout << "Element Not Found" << std::endl;

    //search for an element that doesn't exists 
 it = std::find(l1.begin(),l1.end(),2000);
if (it != l1.end())
	std::cout << "Element Found at index"<<index << std::endl;
else
	std::cout << "Element Not Found" << std::endl;


    return 0;
}
