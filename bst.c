#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include "bst.h"
#include "..\adaptive queues\queue.c"

BST  bst_new(){
BST bst={NULL,0};
return bst;
}

uint32_t  bst_count(const BST  *tree){
assert(tree!=NULL);
return tree->mass;
}

//add element into tree
static  TreeNode*  _get_new_node_(int32_t ele){
TreeNode  *newnode =(TreeNode*)malloc(sizeof(TreeNode));
newnode->data=ele;
newnode->lef=NULL;
newnode->ri=NULL;

return newnode;
}


BST*  bst_add(BST *tree,int32_t  ele){
assert(tree!=NULL);
TreeNode  *current,*parent;

current=parent=tree->root;
while(current !=NULL  &&  ele!=current->data)    //uniqueness of ele is checked here
{
 parent=current;
if (ele<current->data){
    current=current->lef;
}
else if(ele>current->data){
    current=current->ri;
}
}
if(current ==NULL){
    TreeNode *newnode=_get_new_node_(ele);
    if(parent==NULL){
        tree->root=newnode;
    }
    else if(ele<parent->data){
        parent->lef=newnode;
    }else if(ele>parent->data){
    parent->ri=newnode;
    }
    ++tree->mass; //increment the count
}
return tree;
}
uint8_t   bst_lookup(const BST *tree, int32_t key){
assert(tree !=NULL);
TreeNode *current=tree->root;
while(current !=NULL && key!=current->data){
    if (key < current->data){
        current=current->lef;

    }else if (key>current->data){
            current=current->ri;

    }

}
return (current!=NULL);

}

static TreeNode*  _findMin_(TreeNode  *node){
if(node->lef==NULL){//if tree doesnt have any subtree then root itself will be the mainnode
    return node;
}
else{
    return (_findMin_(node->lef));
}
}

static TreeNode*  _delete_(BST *tree,TreeNode *node,int32_t ele){
TreeNode *temp;
if (node==NULL){
    return node;

} else if(ele  <node->data){
   node->lef=_delete_(tree,node->lef,ele);  //gives the new node which has to b updated as left child
}
else if(ele>node->data){
    node->ri=_delete_(tree,node->ri,ele);
}
else if(node->lef  && node->ri){
    temp=_findMin_(node->ri);
    node->data=temp->data;
    node->ri=_delete_(tree,node->ri,node->data);
}
else{
    temp=node;
    if(node->ri==NULL){
        node=node->lef;
    }
    else{
        node=node->ri;
    }
    free(temp);
    --tree->mass;
}
return tree;
}

BST*      bst_delete(BST *tree,int32_t ele){
assert(tree!=NULL);
tree->root=_delete_(tree,tree->root,ele);  //internally implement a static func 'delete' to which we pass tree,address of the parent and the ele which we want to delete this is a recursive function.For every recursive func the address keeps on changing

return tree;
}




static void _inorder_(TreeNode *node){
if (node){
    _inorder_(node->lef);
    printf("%d\t",node->data);
    _inorder_(node->ri);

}
}

void      bst_inorder(BST *tree){
assert(tree!=NULL);
_inorder_(tree->root);
}

static void _preorder_(TreeNode *node){
if (node){
    printf("%d\t",node->data);
    _preorder_(node->lef);
    _preorder_(node->ri);

}
}

void      bst_preorder(BST *tree){
assert(tree!=NULL);
_preorder_(tree->root);
}

static void _postorder_(TreeNode *node){
if (node){
    _postorder_(node->lef);
    _postorder_(node->ri);
    printf("%d\t",node->data);

}
}

void      bst_postorder(BST *tree){
assert(tree!=NULL);
_postorder_(tree->root);
}


void  bst_levelordertraversal(BST *tree){
assert (tree!=NULL);
Queue q1=queue_new(tree->mass);
Queue *q=&q1;
QueueResult res;
TreeNode *node=tree->root;
queue_add(q,node,&res);

while(!queue_empty(q)){
    queue_delete(q,&res);
    node=(TreeNode*)res.data;
    if(node->lef){
        queue_add(q,node->lef,&res);

    }
    if(node->ri){
        queue_add(q,node->ri,&res);
    }
    printf("%d\t",node->data);
}

}

static int32_t count_height(TreeNode *node){
if(node==NULL){
         return 0;
}
else{
   int lheight=count_height(node->lef);
   int rheight=count_height(node->ri);

    if(lheight>rheight){
        return(lheight+1);
}
   else{
        return (rheight+1);
    }

}
}

int32_t bst_height(BST *tree){
assert(tree!=NULL);
count_height(tree->root);



}

static uint8_t count_leaf(TreeNode *node){
if(node==NULL){
    return 0;
}
if(node->lef==NULL && node->ri==NULL){
    return 1;
}
return (count_leaf(node->lef)+count_leaf(node->ri));
}

uint8_t bst_terminal_node(BST *tree){
assert(tree!=NULL);
count_leaf(tree->root);

}



int32_t max(BST *tree){
  assert(tree!=NULL);
  TreeNode *node=tree->root;
  int32_t res=node->data;
  int32_t lres=max(node->lef->data);
  int32_t rres=max(node->ri->data);
  if(lres>res){
    res=lres;
  }
  if(rres>res){
    res=rres;
  }

  return res;

}


int32_t min(BST *tree){
TreeNode *node=tree->root;
while(node->lef!=NULL){
    node=node->lef;

}
return (node->data);
}


void bst_ascending(BST *tree){
assert(tree!=NULL);
_inorder_(tree->root);
}

static void _revinorder_(TreeNode *node){
if (node){
    _revinorder_(node->ri);
    printf("%d\t",node->data);
    _revinorder_(node->lef);

}
}
void bst_descending(BST *tree){
assert(tree!=NULL);
_revinorder_(tree->root);
}
