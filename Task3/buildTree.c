#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h"
#include "nodeValue.h"
#include "buildTree.h"


// make a node at given location (x,y) and level

Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));
  node->flag=0;
  node->level = level;

  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i )
    node->child[i] = NULL;

  return node;
}

// split a leaf nodes into 4 children

void makeChildren( Node *parent ) {
  int i;

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}

//grow the tree for each empty node.
void growTree(Node *parent)
{
  int i;
  Node *p=parent;
  if (p->child[0]==NULL)
  {
    makeChildren(p);
  }
  else
  {
    for (i=0;i<4;i++)
    {
      growTree(p->child[i]);
    }
  }
  return;
}


void assignValue(Node *head)
{
  int i;
  Node *p=head;
  if (p->child[0]==NULL)
  {
    if (nodeValue(p, 0.0)>0.5)
    {
      p->flag=1;
    }
    else if (nodeValue(p,0.0)< (-0.5))
    {
     p->flag=-1; 
    }
    else
    {
      p->flag=0;
    }
  }
  else
  {
    for (i=0;i<4;i++)
    {
      p->flag=0;
      assignValue(p->child[i]);
    }
  }
  return;
}

