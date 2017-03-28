// rbtree.cpp implementation file for Red-Black Tree class

#include "rbtree.h"
#include <iostream>
#include <iomanip>


using namespace std;

// Constructor
RBTree::RBTree()
{
    root = NULL;
}


// Destructor
RBTree::~RBTree()
{
    del(root);
}

void RBTree::del(NodePtr current)
{
    if ( current != NULL )
    {
        del( current->left );
        del( current->right );
        delete current;
    }
}

// Other RBTree mutators - not directly used here
void RBTree :: leftRotate( NodePtr x )
{
   NodePtr y = x->right ;
// You write the rest of this
}

void RBTree :: rightRotate( NodePtr x )
{
   NodePtr y = x->left ;
// You write the rest of this
}

void RBTree :: insertFixup( NodePtr z )
{
  NodePtr y ;
  while (z->p->color == 'R' ) {
    if ( z->p == z->p->p->left ) {
       // You fill this in
    } else {
       // You fill this in - with left and right interchanged
    }
  }
  root->color = 'B' ;
}

void RBTree :: deleteFixup( NodePtr x )
{
  NodePtr w ; // w is x's sibling
  while ( ( x != root ) && ( x->color == 'B' ) ) {
     if ( x == x->p->left ) {  // x is a left child
        // You fill this in
     } else {  // x is a right child
        // You fill this in - with left and right interchanged
     }
  }
  x->color = 'B' ;
}


// Other RBTree accessors - not directly used here - used in RBdelete
NodePtr RBTree :: Tree_minimum( NodePtr x )
{
   while ( x->left != NULL )
      x = x->left ;
   return x ;
}

// This is not used.
NodePtr RBTree :: Tree_successor( NodePtr x )
{
   if ( x->right != NULL ) return Tree_minimum( x->right ) ;
   
   NodePtr y = x->p ;
   while ( ( y != NULL ) && ( x == y->right ) ) {
      x = y ;
      y = y->p ;
   }
   return y ; 
}


// RBTree mutators
void RBTree :: RBinsert( KeyType k )
{
    NodePtr z = new Node(k);
    z->color = 'B';

   // You supply the rest of the code

   insertFixup( z ) ;
}

void RBTree :: RBdelete( NodePtr z )
{
   NodePtr x ;
   NodePtr y = z ;
   char y_original_color = y->color ;

   // You supply the rest of the code

   if ( y_original_color == 'B' )
       deleteFixup( x ) ;
}

// RBTree accessor
NodePtr RBTree :: RBsearch( NodePtr x, KeyType k )
{
   while ( ( x != NULL ) && ( k != x->key ) )
      if ( k < x->key ) x = x->left ;
      else              x = x-> right ;
   return x ;
}

// RBTree "print" utility routines
void RBTree :: inorderTreeWalk( NodePtr x )
{
   if ( x != NULL ) {
      inorderTreeWalk( x->left ) ;
      cout << x->key << " " ;
      inorderTreeWalk( x->right ) ;
   }
}

/* Just prints tree in order as a horizontal list; may be used for debugging */
void RBTree :: PrintTree()
{
   cout << "Tree elements in order:\n" ;
   inorderTreeWalk( root ) ;
   cout << "\n\n" ;
}

/* Shows the structure of the binary search tree */
void RBTree :: ShowTree( NodePtr x, int depth )
{
   if ( x != NULL ) {
      ShowTree( x->right, depth+1 ) ;
      cout << setw( depth*7 +4 ) << x->key << x->color << endl ;
      ShowTree( x->left, depth+1 ) ;
   }
}

