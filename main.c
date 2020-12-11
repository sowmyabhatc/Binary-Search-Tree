#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

void test_new(){
BST tree1=bst_new();
BST *tree= &tree1;
assert(bst_count(tree)==0);
tree=bst_add(tree,10);
tree=bst_add(tree,50);
tree=bst_add(tree,20);
tree=bst_add(tree,90);
assert(bst_count(tree)==4);

}

void test_inorder(){
BST tree1=bst_new();
BST *tree=&tree1;
tree=bst_add(tree,50);
tree=bst_add(tree,20);
tree=bst_add(tree,90);
tree=bst_add(tree,25);
tree=bst_add(tree,70);
tree=bst_add(tree,60);
tree=bst_add(tree,85);
tree=bst_add(tree,35);
tree=bst_add(tree,10);

bst_inorder(tree);


}

void test_preorder(){
BST tree1=bst_new();
BST *tree=&tree1;
tree=bst_add(tree,50);
tree=bst_add(tree,20);
tree=bst_add(tree,90);
tree=bst_add(tree,25);
tree=bst_add(tree,70);
tree=bst_add(tree,60);
tree=bst_add(tree,85);
tree=bst_add(tree,35);
tree=bst_add(tree,10);

 bst_preorder(tree);


}




void test_postorder(){
BST tree1=bst_new();
BST *tree=&tree1;
tree=bst_add(tree,50);
tree=bst_add(tree,20);
tree=bst_add(tree,90);
tree=bst_add(tree,25);
tree=bst_add(tree,70);
tree=bst_add(tree,60);
tree=bst_add(tree,85);
tree=bst_add(tree,35);
tree=bst_add(tree,10);


bst_postorder(tree);

}

void test_levelordertraversal(){
BST tree1=bst_new();
BST *tree=&tree1;
tree=bst_add(tree,50);
tree=bst_add(tree,20);
tree=bst_add(tree,90);
tree=bst_add(tree,25);
tree=bst_add(tree,70);
tree=bst_add(tree,60);
tree=bst_add(tree,85);
tree=bst_add(tree,35);
tree=bst_add(tree,10);


bst_levelordertraversal(tree);
}

void test_height(){
BST tree1=bst_new();
BST *tree=&tree1;
tree=bst_add(tree,50);
tree=bst_add(tree,20);
tree=bst_add(tree,90);
tree=bst_add(tree,25);
tree=bst_add(tree,70);
tree=bst_add(tree,60);
tree=bst_add(tree,85);
tree=bst_add(tree,35);
tree=bst_add(tree,10);


assert(bst_height(tree)==4);

}



void test_terminal(){
BST tree1=bst_new();
BST *tree=&tree1;
tree=bst_add(tree,50);
tree=bst_add(tree,20);
tree=bst_add(tree,90);
tree=bst_add(tree,25);
tree=bst_add(tree,70);
tree=bst_add(tree,60);
tree=bst_add(tree,85);
tree=bst_add(tree,35);
tree=bst_add(tree,10);

assert(bst_terminal_node(tree)==3);
}

void test_max(){
BST tree1=bst_new();
BST *tree=&tree1;
tree=bst_add(tree,50);
tree=bst_add(tree,20);
tree=bst_add(tree,90);
tree=bst_add(tree,25);
tree=bst_add(tree,70);
tree=bst_add(tree,60);
tree=bst_add(tree,85);
tree=bst_add(tree,35);
tree=bst_add(tree,10);

assert(max(tree)==90);

}

void test_min(){
BST tree1=bst_new();
BST *tree=&tree1;
tree=bst_add(tree,50);
tree=bst_add(tree,20);
tree=bst_add(tree,90);
tree=bst_add(tree,25);
tree=bst_add(tree,70);
tree=bst_add(tree,60);
tree=bst_add(tree,85);
tree=bst_add(tree,35);
tree=bst_add(tree,10);

assert(min(tree)==10);

}

void test_ascending(){
BST tree1=bst_new();
BST *tree=&tree1;
tree=bst_add(tree,50);
tree=bst_add(tree,20);
tree=bst_add(tree,90);
tree=bst_add(tree,25);
tree=bst_add(tree,70);
tree=bst_add(tree,60);
tree=bst_add(tree,85);
tree=bst_add(tree,35);
tree=bst_add(tree,10);

bst_ascending(tree);


}

void test_descending(){
BST tree1=bst_new();
BST *tree=&tree1;
tree=bst_add(tree,50);
tree=bst_add(tree,20);
tree=bst_add(tree,90);
tree=bst_add(tree,25);
tree=bst_add(tree,70);
tree=bst_add(tree,60);
tree=bst_add(tree,85);
tree=bst_add(tree,35);
tree=bst_add(tree,10);

bst_descending(tree);


}
int main()
{
    test_new();
    test_inorder();
    test_postorder();
    test_levelordertraversal();
    test_height();
    test_terminal();
    test_max();
    test_min();
    test_ascending();
    test_descending();
    return 0;

}
