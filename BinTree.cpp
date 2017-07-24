#include "BinTree.h"
#include <stdio.h>

BinTree::BinTree(){
	root = NULL;
}

BinTree::~BinTree(){
	delete [] root;
}

//true val exists
//false otherwise
bool
BinTree::insert(int val){
	BTNode * parent = NULL;
	//node where to insert
	BTNode * n = root;

	while(n != NULL){
		parent = n;

		if(n->value == val){
			return true;	//found the value
		} else if (n->value > val){
			n = n->left; // val is in left sort tree
		} else { 	//n->value < val
			n = n->right; 
		}
	}
	//val is not in the tree
	//parent should point to the node to insert
	//except if the tree is empty
	//if the tree is empty, parent is null

	//create new node
	n = new BTNode();
	n->value = val;
	n->right = NULL;
	n->left = NULL;

	if(parent == NULL){
		//tree is empty
		root = n;
	} else {
		//tree is not empty
		//parent point to the parent of node to insert
		//in left or right
		if(parent->value > val){
			//insert left
			parent->left = n;
		} else {
			//insert right
			parent->right = n;
		}
	}
	return false;
}

void
BinTree::inOrderPrint(BTNode * node){
	//print values of the tree rooted by "node"
	//using inorder traversal
	if(node ==NULL)
		return;
	inOrderPrint(node->left);
	printf("%d ", node->value);
	inOrderPrint(node->right);
} //To print the whole tree, call inOrderPrint(root)

BTNode *
BinTree::getRoot(){
	return this->root;
}

int main(int argc, char ** argv){
	BinTree * bt = new BinTree();

	bt->insert(6);
	bt->insert(12);
	bt->insert(3);
	bt->insert(32);
	bt->insert(88);
	bt->insert(2);

	BTNode * root = bt->getRoot();
	printf("Binary Tree...\n");
	bt->inOrderPrint(root);
	printf("\n");
}
