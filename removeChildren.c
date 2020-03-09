#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h"

void removeChildren(Node *parent)
{
    int i;
    if (parent->child[0]!=NULL)
    {
        return;
    } 
    else
    {
        for (i=0;i<4;i++)
        {
            free(parent->child[i]);
            parent->child[i]=NULL;
        }
    }
}
