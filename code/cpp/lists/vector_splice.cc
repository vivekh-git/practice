#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

using namespace std;



int main()
{
   std::list<int> v;
   for (int i=0; i<10; ++i) v.push_back(i); // 1 2 3 4 5
   std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ",")); 
   std::cout << "\n";

   list<int>::iterator it = std::next(v.begin(), 1); // O(N)
   list<int>::iterator rb = std::next(it);
   list<int>::iterator re = v.end();   
   cout << "it:" << *it << ", v is list, rb: "<<*rb<< ", re: "<<*re<<endl;
   //v.splice(it, v, rb, re); // O(1)
   v.splice(std::next(v.begin(),5), v, std::next(v.begin(),6), v.end()); // O(1)

   std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ","));
   std::cout << "\n";   
}
