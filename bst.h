#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <stdint.h>

typedef struct _tree_node_  TreeNode;
struct _tree_node_ {
int32_t  data;
TreeNode   *lef;
TreeNode  *ri;
};

typedef  struct  _bst_  BST;
struct  _bst_{
//we need to store the root address of the BST
TreeNode  *root;
uint32_t   mass; //size
};

BST       bst_new();
uint32_t  bst_count(const BST  *tree);
uint8_t   bst_lookup(const BST *tree, int32_t key);
BST*      bst_add(BST* tree,int32_t ele);
BST*      bst_delete(BST *tree,int32_t ele);
void      bst_inorder(BST *tree);//lpr
void      bst_preorder(BST *tree);//plr
void      bst_postorder(BST *tree);//lrp
void      bst_levelordertraversal(BST *tree);//lr

int32_t   bst_height(BST *tree);
uint8_t   bst_terminal_node(BST *tree);
int32_t   max(BST *tree);
int32_t   min(BST *tree);
void      bst_ascending(BST *tree);
void      bst_descending(BST *tree);

#endif // BST_H_INCLUDED
