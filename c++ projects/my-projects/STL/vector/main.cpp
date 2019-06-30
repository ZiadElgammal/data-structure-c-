//vector
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
int main()
{
    std::vector<int> v1; // decleare vector v1:
    for (int i = 0; i < 20; i++)
        v1.push_back(rand() % 100); //push 20 random integers
    std::cout << "v1 contains:";    //return e/*8lements using iterator
    for (auto i = v1.begin(); i != v1.end(); ++i)
        std::cout << *i << " ";
  
    //remove elements at index 3   
    v1.erase(v1.begin() + 3); 

    //return all elements with iterator
 std::cout << "\nv1 contains:";  
    for (auto i = v1.begin(); i != v1.end(); ++i)
        std::cout << *i << " ";

// sort vector 
std::stable_sort(v1.begin(),v1.end()); cout<<"\n sorted v1:";
for (auto i = v1.begin(); i != v1.end(); ++i)
        std::cout << *i << " ";
        cout<<"\n";
 // search for an element that exists
 std::vector<int>::iterator it = std::find(v1.begin(),v1.end(),92);
 int index = std::distance(v1.begin(), it);
if (it != v1.end())
	std::cout << "Element Found at index "<< index << std::endl;
else
	std::cout << "Element Not Found" << std::endl;


//search for an element that doesn't exists 
 it = std::find(v1.begin(),v1.end(),2000);
if (it != v1.end())
	std::cout << "Element Found at index"<<index << std::endl;
else
	std::cout << "Element Not Found" << std::endl;
        return 0;
}
