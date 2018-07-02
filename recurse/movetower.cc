#include <iostream>

using namespace std;

// pseudo code
// 3 towers - A, B, C  - char - src = A, dest = B
void MoveTower(int n, char src, char dst, char tmp) {
  // go till last disk
  if ( n > 0 ) {
    MoveTower(n-1, src, tmp, dst);
    MoveSingleDisk(src, dst);
    MoveTower(n-1, tmp, dst, src); 
  }
  return;
}
