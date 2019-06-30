//set
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    set<int> set1;
    set<int>::iterator it;
    //insert 20 elements
    for (int i = 0; i < 20; i++)
        set1.insert(rand() % 100);
    //print elements
    cout<<"\nset contains: ";
     for (it = set1.begin(); it != set1.end(); ++it) 
    { 
        cout << '\t' << *it; 
    } 
    cout << endl;
    //delete 
    set1.erase(72);//remove a specific element by value 
    it = set1.begin() ;it ++ ;
    set1.erase(it );// remove element by index 
    //print
    cout<<"the set contains";
      for (it = set1.begin(); it != set1.end(); ++it) 
    { 
        cout << '\t' << *it; 
    } 
    cout << endl;

    //serach
    int x = 83;
    std::cout << "searchinf for emlement: "<<x << std::endl;
   it= std::find(set1.begin(),set1.end(),x);
   if (it != set1.end())
	std::cout << "Element Found " << std::endl;
else
	std::cout << "Element Not Found" << std::endl;
        return 0;
  
    return 0;
}
