//map
#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    map<int, int> m1;
    map<int, int>::iterator it;
    //insert 20 elements
    for (int i = 0; i < 20; i++)
        m1.insert(pair<int, int>(i, rand() % 100));
    // print
    cout << "\nThe map m1 is : \n";
    cout << "\tx \ty \n";
    for (it = m1.begin(); it != m1.end(); ++it)
    {
        //cout << '\t' << it;
        cout << '\t' << it->first
             << '\t' << it->second << '\n';
    }
    cout << endl;

    //delete
    cout << "deleting element with key 18";
    m1.erase(m1.find(18)); //remove a specific key value

    // print
    cout << "\nThe map m1 is : \n";
    cout << "\tx \ty \n";
    for (it = m1.begin(); it != m1.end(); ++it)
    {
        //cout << '\t' << it;
        cout << '\t' << it->first
             << '\t' << it->second << '\n';
    }
  //  search by key
  int x = 19;
    it = m1.find(x);
    if (it != m1.end())
        std::cout << "Element Found " << std::endl;
    else
        std::cout << "Element Not Found" << std::endl;

    return 0;
}
