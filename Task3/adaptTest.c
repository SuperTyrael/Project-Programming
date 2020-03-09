#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "buildTree.h"
#include "removeChildren.h"
#include "treeStructure.h"

void adapt(Node *head)
{
    Node *p=head;
    int i;
    for (i=0;i<4;i++)
    {
        if (p->child[i]!=NULL)
        {
            while (p->child[0]==NULL)
            {
                
            }
        }
        
    }
}