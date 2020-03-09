#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h"
#include "buildTree.h"
#include "removeChildren.h"


//At every node of the tree:
//If the node is a leaf node and flag=1 use makeChildren()
//If the node is not a leaf node and all 4 children have flag=-1 use removeChildren()

void nodeCheck(Node *node, int *makeC, int *removeC)
{
    int i;
    if (node->child[0]==NULL)
    {
        if (node->flag==1)
        {
            makeChildren(node);
            *makeC=(*makeC)+4;
        }
    }
    else if (node->child[0]!=NULL && node->child[0]->flag==-1 && node->child[1]->flag==-1 && node->child[2]->flag==-1 && node->child[3]->flag==-1)
    {
            removeChildren(node);
            *removeC=(*removeC)+4;
    }
    else
        {
            for (i=0;i<4;i++)
            {
                nodeCheck(node->child[i], makeC, removeC);
            }
        }
    return;
}

void nodePrint(Node *node)
{
    int a=0, b=0,choice;
    int *makeC, *removeC;
    makeC=&a;
    removeC=&b;
    assignValue(node);
    nodeCheck(node, makeC, removeC);
    printf("Totally make %d children, totally remove %d children", *makeC,*removeC);
    return;
}

