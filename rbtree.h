#ifndef RBTREE_H
#define RBTREE_H

#include <stddef.h>

typedef int KeyType;

typedef class Node * NodePtr;
// Note: One could replace all "NodePtr"s below with "Node *"


class Node {
public:
   KeyType key;
   char color;
   NodePtr p;
   NodePtr left;
   NodePtr right;

   // Constructor
   Node( KeyType k = 0 ) : key(k), p(NULL), left(NULL), right(NULL) {}
};


class RBTree {
    
public:
    
    RBTree();
    ~RBTree();
    
    // RBTree "dictionary" functions
    void RBinsert( KeyType z );     // Inserts a new node with value k
    void RBdelete( NodePtr z );     // Deletes a node that should have been found with RBSearch
    NodePtr RBsearch( NodePtr x, KeyType key );
    NodePtr RBsearch( KeyType k ) { return RBsearch(root, k); }
    
    // RBTree display options
    void ShowTree( NodePtr x, int depth );
    void ShowTree( int depth ) { ShowTree(root, depth); }
    void PrintTree();
    
private:
    
   // Utility for PrintTree(); could be made public if needed externally
   void inorderTreeWalk( NodePtr x ) ; 

   NodePtr root ;
    
   // Other RBTree accessors - not directly used here
   NodePtr Tree_minimum( NodePtr x ) ;
   NodePtr Tree_successor( NodePtr x ) ;

   // Other RBTree mutators - not directly used here
   void leftRotate( NodePtr x ) ;
   void rightRotate( NodePtr x ) ;
   void insertFixup( NodePtr z ) ;
   void deleteFixup( NodePtr x ) ;
   //void RBTransplant( NodePtr u, NodePtr v ) ;

    void del(NodePtr current);
} ;

#endif
