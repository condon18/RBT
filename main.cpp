#include "rbtree.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{

  RBTree theTree;
  
  theTree.RBinsert(3);
  
  theTree.RBinsert(2);
  
  theTree.RBinsert(3);
  
  theTree.RBinsert(4);
  
  theTree.RBinsert(1);
  
  theTree.RBinsert(6);

  return 0;
}
