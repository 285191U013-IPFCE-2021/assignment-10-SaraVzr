#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

int min_right (struct tree_node *t){
  struct tree_node *temp = t;
  while(t->left != NULL){
   temp = t->left;
  }
  return (temp->item);
}

struct tree_node * Insert (int x, struct tree_node *t)
{
  // Insert item x into the tree t
 if (t==NULL){
  t = Initialize (t);
  t->item = x;
  }
   else if(x <= t->item)
   return Insert (x, t->left);
 
     else if (x > t->item)
     return Insert (x, t->right);
}

struct tree_node * Remove (int x, struct tree_node *t)
{
 // Remove one item from the tree t
 if (t!=NULL)
 {
  if(x > t->item){
    t->right = Remove(x, t->right);
   } 
     else if(x < t->item){
     t->left = Remove (x, t->left);
     }
       else if (x == t->item){
  
       if ( t->left == NULL && t->right ==NULL) {
       free (t);
       return NULL;
       }
       }
         else if (t->left == NULL || t->right == NULL){
         struct tree_node *p = NULL;
         if (t->right == NULL){
          p = t->left;
         }
         else { 
         p = t->right;
         }
         free(t);
         return p; 
         }

           else {
           int min_largest = min_right (t->right);
           t->item = min_largest;
           t->right = Remove(t->item, t->right);
           }
 }
  return (t);
}



int Contains (int x, struct tree_node *t)
{
  // Return true if the tree t contains item x. Return false otherwise.
  if (t->item == x)
  return 1;
     else if (x < t->item)
     Contains(x, t->left);
       else if (x > t->item)
       Contains (x,t->right);
         else 
         return 0;
}


struct tree_node * Initialize (struct tree_node *t)
{
  // Create an empty tree
  assert (t==NULL);
  struct tree_node *binarytree= (struct tree_node*)malloc(sizeof(struct tree_node));  
  binarytree->left = NULL;
  binarytree->right = NULL;
  return binarytree;
}


int Empty (struct tree_node *t)
{
  // Test if empty
  if (t == NULL)
    return 1;

  return 0;
}

int Full (struct tree_node *t)
{
    // Test if full
    return false;
}


