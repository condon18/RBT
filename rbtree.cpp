// rbtree.cpp implementation file for Red-Black Tree class

#include "rbtree.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

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
   NodePtr node=x;
// You write the rest of this

  //retry:

  if (x -> p != root) {
    // (step 1)
    NodePtr xGrandp = x -> p -> p;
    NodePtr xLeft = x -> left;

    //(step 2)
    x -> p -> p = x;

    //(step 3)
    x -> left = x -> p;

    //(step 4)
    x -> p = xGrandp;

    //(step 5)
    x -> left -> right = xLeft;

    //(step 6)
    if (xGrandp -> right == x -> left) {
      xGrandp -> right = x;
    }
    else if (xGrandp -> left == x -> left) {
      xGrandp -> left = x;
    }
  }
  else { //if parent is root
    //(step 1)
    NodePtr xLeft = x -> left;

    //(step 2)
    x -> p -> p = x;

    //(step 3)
    x -> left = x -> p;

    //(step 4)
    x -> p = NULL;

    //(step 5)
    x -> left -> right = xLeft;

    //set root
    root = x;
  }

  //endretry

  //note that x is the center node of rotation
}

void RBTree :: rightRotate( NodePtr x )
{
   NodePtr y = x->left ;
   NodePtr node=x;
// You write the rest of this

  //note that x is the center node of rotation


  if (x -> p != root) {
    // (step 1)
    NodePtr xGrandp = x -> p -> p;
    NodePtr xright = x -> right;

    //(step 2)
    x -> p -> p = x;

    //(step 3)
    x -> right = x -> p;

    //(step 4)
    x -> p = xGrandp;

    //(step 5)
    x -> right -> left = xright;

    //(step 6)
    if (xGrandp -> left == x -> right) {
      xGrandp -> left = x;
    }
    else if (xGrandp -> right == x -> right) {
      xGrandp -> right = x;
    }
  }
  else { //if parent is root
    //(step 1)
    NodePtr xright = x -> right;

    //(step 2)
    x -> p -> p = x;

    //(step 3)
    x -> right = x -> p;

    //(step 4)
    x -> p = NULL;

    //(step 5)
    x -> right -> left = xright;

    //set root
    root = x;
  }

}

void RBTree :: insertFixup( NodePtr z )
{
  if (z -> p -> p == NULL) {
    return;
  }

  NodePtr y ;
  while (z->p != NULL && z->p->color == 'R' ) { //while z's parent is red
    if ( z->p == z->p->p->left ) { //if z's parent is a left child
       // You fill this in
       if (z -> p -> p -> right == NULL || z -> p -> p -> right -> color == 'B') { //uncle is Null or Black (Case B,C)
         if (z == z -> p -> left) { //if z is a left child (Case B)
           //single rotation
           rightRotate(z -> p);
           root -> color = 'B';
           root -> left -> color = 'R';
           root -> right -> color = 'R';
         }
         else { //z is a right child (Case C)
           //double rotation
           leftRotate(z);
           rightRotate(z);
           root -> color = 'B';
           root -> left -> color = 'R';
           root -> right -> color = 'R';
         }
       }
       else { //if uncle is Red (Case A)
         z -> p -> color = 'B';
         z -> p -> p -> color = 'R';
         z -> p -> p -> right -> color = 'B';
       }
    } else { //if z's parent is a right child
       // You fill this in - with left and right interchanged
       if (z -> p -> p -> left == NULL || z -> p -> p -> left -> color == 'B') { //uncle is Null or Black (Case B,C)
         if (z == z -> p -> right) { //if z is a right child (Case B)
           //single Rotation
           leftRotate(z -> p);
           root -> color = 'B';
           root -> left -> color = 'R';
           root -> right -> color = 'R';
         }
         else { //if z is a left child (Case C)
           //double Rotation
           rightRotate(z);
           leftRotate(z);
           root -> color = 'B';
           root -> left -> color = 'R';
           root -> right -> color = 'R';
         }
       }
       else { //if uncle is Red (Case A)
         z -> p -> color = 'B';
         z -> p -> p -> color = 'R';
         z -> p -> p -> left -> color = 'B';
       }
    }
  }
  root->color = 'B';
}

void RBTree :: deleteFixup( NodePtr x )
{
  if (x == x -> p -> left) { //if x is a left child
    //simple swap
    x -> p -> left = x -> left;
    x -> left -> p = x -> p;
    if (x -> right != NULL) { //if x has a right child
      x -> left -> right = x -> right;
      x -> right -> p = x -> left;
    }
    if (x -> left -> p -> left == x -> left) { //if successful
      return;
    }
  }
  else { //if x is a right child
    x -> p -> right = x -> right;
    x -> right -> p = x -> p;
    if (x -> left != NULL) { //if x has a left child
      x -> right -> left = x -> left;
      x -> left -> p = x -> right;
    }
    if (x -> right -> p -> right == x -> right) { //if successful
      return;
    }
  }

  //if we need to do rotations
  NodePtr w ; // w is x's sibling
  while ( ( x != root ) && ( x->color == 'B' ) ) {
     if ( x == x->p->left ) {  // x is a left child
        // You fill this in

        w = x -> p -> right;

        if (x -> p -> color == 'R') { //if parent is red (Case 1)
          leftRotate(x);
        }
        else if (w -> color == 'R') { //if sibling is red (Case 2)
          rightRotate(x);
          leftRotate(x);
        }
        else if (w -> left -> color == 'R') { //if far nephew is red (Case 3a)
          leftRotate(x);
          w -> color = 'B';
        }
        else if (w -> right -> color == 'R') { //if near nephey is red (Case 3b)
          rightRotate(x);
          leftRotate(x);
          w -> color = 'B';
        }
        else { //(Case 4)
          w -> color = 'B';
        }
     } else {  // x is a right child
        // You fill this in - with left and right interchanged

        w = x -> p -> left;

        if (x -> p -> color == 'R') { //if parent is red (Case 1)
          rightRotate(x);
        }
        else if (w -> color == 'R') { //if sibling is red (Case 2)
          leftRotate(x);
          rightRotate(x);
        }
        else if (w -> right -> color == 'R') { //if far nephew is red (Case 3a)
          rightRotate(x);
          w -> color = 'B';
        }
        else if (w -> left -> color == 'R') { //if near nephey is red (Case 3b)
          leftRotate(x);
          rightRotate(x);
          w -> color = 'B';
        }
        else { //(Case 4)
          w -> color = 'B';
        }
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
    z->color = 'R';

   // You supply the rest of the code

   if (root == NULL) {
     root = z;
     return;
   }

   NodePtr cNode = root;

   while(true)
     if (k > cNode -> key) { //if z > cNode
       if (cNode -> right != NULL) { //if cNode has right child
         cNode = cNode -> right;
       }
       else { //if cNode has no right child
         //place z into the tree
         cNode -> right = z;
         z -> p = cNode;
         break;
       }
     }
     else { //if z < cNode
       if (cNode -> left != NULL) { //if cNode has left child
         cNode = cNode -> left;
       }
       else { //if cNode has no left child
         //place z into the tree
         cNode -> left = z;
         z -> p = cNode;
         break;
       }
     }
   insertFixup( z ) ;
}

void RBTree :: RBdelete( NodePtr z )
{
   NodePtr x ;
   NodePtr y = z ;
   int u = z -> key;
   char y_original_color = y->color ;

   // You supply the rest of the code

   NodePtr cNode = z;
   if (root == cNode) { //if we are deleting the root
     if (cNode -> left != NULL && cNode -> right != NULL) { //if root has 2 children
       cNode -> left -> p = cNode -> right;
       cNode -> right -> left = cNode -> left;
       root = cNode -> right;
     }
     else if (cNode -> left != NULL) { //if root has only left child
       cNode -> left -> p = NULL;
       root = cNode -> left;
     }
     else if (cNode -> right != NULL) { //if root has only right child
       cNode -> right -> p = NULL;
       root = cNode -> right;
     }
     else {
       root = NULL;
     }
     free(cNode);
   }
   else if (cNode -> color == 'R') { //if color is red
     if (cNode -> key > cNode -> p -> key) { //if cNode is a right child
       cNode -> p -> right = NULL;
       free(cNode);
     }
     else { //if cNode is a left child
       cNode -> p -> left = NULL;
       free(cNode);
     }
   }
   else { //color is black
     deleteFixup(cNode);
     free(cNode);
   }
   
  //existing

  //we ended up not needing this starter code
  // if ( y_original_color == 'B' )
  //     deleteFixup( x ) ;
}

// RBTree accessor
NodePtr RBTree :: RBsearch( NodePtr x, KeyType k )
{
  //while we are not at the node or a leaf
   while ((x != NULL) && (k != x -> key)) {
      if (k < x -> key) {
        x = x -> left; //search left
      }
      else {
        x = x -> right; //search right
      }
   }
   return x ;
}

// RBTree "print" utility routines
void RBTree :: inorderTreeWalk( NodePtr x )
{

   if ( x != NULL ) {
      inorderTreeWalk( x->left ) ;
      cout << x->key;
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

//traverses the tree and prints it out
//void RBTree :: Traverse() {
//  cout << (root -> key);

  //if (n -> left == NULL) { //if no left child
  //  cout
  //}
//}
