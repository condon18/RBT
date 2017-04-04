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
    cout << "if root != node\n";
    if (root != node) {
      cout << "if root->left ==node\n";
        if (root->left ==node) { //'b
            node->p = node->left;
        }
        else if (root->left != NULL) { //if grandchildren exist
          if (root->left->left == node || root->left->right == node) { //C
            node->p = node->left;
          }
        }
    } else {//A
      root = y;
      y -> right = x;
    }
    
    /*cout << "y->left\n";
    node->right = y->left;
    cout << "node->left =node\n";
    node->left =node ;*/
}

void RBTree :: rightRotate( NodePtr x )
{
   NodePtr y = x->left ;
   NodePtr node=x;
// You write the rest of this
    /*if (root != node) {
        if (root->right ==node) //'b
            node->p = node->right;
        else if (root->right->right == node || root->right->left == node) { //C
          node->p = node->right;
        }
    } else //A
      node->p->left = node->left;


    node->left = y->right;
    node->right =node ;*/
}

void RBTree :: insertFixup( NodePtr z )
{
  if (z -> p -> p == NULL) {
    return;
  }

  NodePtr y ;
  cout << "while:\n";
  while (z->p->color == 'R' ) { //while z's parent is red
    cout << "if parent is left child\n";
    if ( z->p == z->p->p->left ) { //if z's parent is a left child
       // You fill this in
       if (z -> p -> p -> right == NULL || z -> p -> p -> right -> color == 'B') { //uncle is Null or Black (Case B,C)
         if (z == z -> p -> left) { //if z is a left child (Case B)
           //single rotation
           rightRotate(root);
           root -> color = 'B';
           root -> left -> color = 'R';
           root -> right -> color = 'R';
         }
         else { //z is a right child (Case C)
           //double rotation
           rightRotate(root);
           rightRotate(root);
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
       cout << "if uncle is Null or black:\n";
       if (z -> p -> p -> left == NULL || z -> p -> p -> left -> color == 'B') { //uncle is Null or Black (Case B,C)
         cout << "if z is a right child:\n";
         if (z == z -> p -> right) { //if z is a right child (Case B)
           //single Rotation
           cout << "left single rotate:\n";
           leftRotate(root);
           root -> color = 'B';
           root -> left -> color = 'R';
           root -> right -> color = 'R';
         }
         else { //if z is a left child (Case C)
           //double Rotation
           leftRotate(root);
           leftRotate(root);
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
  root->color = 'B' ;
}

void RBTree :: deleteFixup( NodePtr x )
{
  NodePtr w ; // w is x's sibling
  while ( ( x != root ) && ( x->color == 'B' ) ) {
     if ( x == x->p->left ) {  // x is a left child
        // You fill this in
        
        w = x -> p -> right;
        
        if (x -> p -> color == 'R') { //if parent is red (Case 1)
          leftRotate(root);
        }
        else if (w -> color == 'R') { //if sibling is red (Case 2)
          leftRotate(root);
          leftRotate(root);
        }
        else if (w -> left -> color == 'R') { //if far nephew is red (Case 3a)
          leftRotate(root);
          w -> color = 'B';
        }
        else if (w -> right -> color == 'R') { //if near nephey is red (Case 3b)
          leftRotate(root);
          leftRotate(root);
          w -> color = 'B';
        }
        else { //(Case 4)
          w -> color = 'B';
        }
     } else {  // x is a right child
        // You fill this in - with left and right interchanged
        
        w = x -> p -> left;
        
        if (x -> p -> color == 'R') { //if parent is red (Case 1)
          rightRotate(root);
        }
        else if (w -> color == 'R') { //if sibling is red (Case 2)
          rightRotate(root);
          rightRotate(root);
        }
        else if (w -> right -> color == 'R') { //if far nephew is red (Case 3a)
          rightRotate(root);
          w -> color = 'B';
        }
        else if (w -> left -> color == 'R') { //if near nephey is red (Case 3b)
          rightRotate(root);
          rightRotate(root);
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
   cout << "fixup:\n";
   insertFixup( z ) ;
}

void RBTree :: RBdelete( NodePtr z )
{
   NodePtr x ;
   NodePtr y = z ;
   char y_original_color = y->color ;

   // You supply the rest of the code
   
   NodePtr cNode = z;
   
   if (cNode -> color == 'R') { //if color is red
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

   if ( y_original_color == 'B' )
       deleteFixup( x ) ;
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
      cout << "/" << x->key << " \\" ;
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