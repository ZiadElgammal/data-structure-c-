//multiset
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    multiset<int> mset1;
    set<int>::iterator it;
    //insert 20 elements
    for (int i = 0; i < 20; i++)
        mset1.insert(rand() % 100);
    //print elements
    for (it = mset1.begin(); it != mset1.end(); ++it)
    {
        cout << '\t' << *it;
    }
    cout << endl;

     //delete 
    mset1.erase(72);//remove a specific element by value 
    it = mset1.begin() ;it ++ ;
    mset1.erase(it );// remove element by index [21]
    //print
      for (it = mset1.begin(); it != mset1.end(); ++it) 
    { 
        cout << '\t' << *it; 
    } 
    cout << endl;

     //serach
    int x = 15;
    std::cout << "searchinf for emlement "<<x << std::endl;
   it= std::find(mset1.begin(),mset1.end(),x);
   if (it != mset1.end())
	std::cout << "Element Found " << std::endl;
else
	std::cout << "Element Not Found" << std::endl;
        return 0;
  
    return 0;
}
