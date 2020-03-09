#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h"
#include "buildTree.h"
#include "removeChildren.h"
#include "nodeCheck.h"
#define maxLevel 6


void nodeCheckExtend(Node *node, int *makeC, int *removeC)
{
    int i;
    if (node->child[0]==NULL)
    {
        {
            if (node->flag==1 && node->level<maxLevel)
            {
                makeChildren(node);
                *makeC=(*makeC)+4;
            }
        }
    }
    else if (node->child[0]!=NULL)
    {
        if (node->child[0]->flag==-1 && node->child[1]->flag==-1 && node->child[2]->flag==-1 && node->child[3]->flag==-1)
        {
            removeChildren(node);
            *removeC=(*removeC)+4;
        }
        else
        {
            for (i=0;i<4;i++)
            {
                nodeCheckExtend(node->child[i], makeC, removeC);
            }
        }
    }
    return;
}

void adapt(Node *head)
{
    int a,b;
    int *makeC,*removeC;
    do
    {
        a=b=0;
        makeC=&a;
        removeC=&b;
        assignValue(head);
        nodeCheckExtend(head, makeC, removeC);
    }while (*makeC!=0 || *removeC!=0);
    printf("make %d remove %d\n", *makeC, *removeC);
}

