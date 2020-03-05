
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"
#include "destroyTree.h"
#include "removeChildren.h"

// Task2 testing 1

int main( int argc, char **argv ) {

  Node *head;
  int i,choice;
  printf("plz input the test number");
  scanf("%d", choice);

  // make the head node
  head = makeNode( 0.0,0.0, 0 );
  if (choice==1)
  {
    // make a tree
    makeChildren( head );
    growTree(head);

    //delete child node
    for (i=0;i<4;i++)
    {
        removeChildren(head->child[i]);
    }
  }
  else if (choice==2)
  {
    // make a tree
    growTree(head);
    makeChildren(head->child[0]);
    makeChildren(head->child[2]);

    //remove one node in level 1
    removeChildren(head->child[0]);
  }
  // print the tree for Gnuplot
  writeTree( head );

  //free the memory
  destroyTree(head);
  return 0;
}

