
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"
#include "destroyTree.h"
#include "nodeCheck.h"
#include "removeChildren.h"

// main

int main( int argc, char **argv ) {

    Node *head;

  // make the head node
    head = makeNode( 0.0,0.0, 0 );

  // make a tree
    makeChildren( head );
    growTree(head);
    growTree(head);

    //node value detect
    adapt(head);

  // print the tree for Gnuplot
	  writeTree( head );
    destroyTree(head);
    return 0;
}
