#include "TreeDB.h"
#include "TreeNode.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

TreeDB::TreeDB(){
    root = NULL;
    probesCount = 0;
}

TreeDB::~TreeDB(){
    clear();
   
}
void TreeDB::insert(DBentry* v){
     if(root == NULL)
        root = new TreeNode(v);
    else
        root->insert(v);
    return; 
}

void TreeDB::print_inorder(){
    if(root != NULL){
        root ->print_inorder();    
    }  
}

TreeNode* TreeDB::find(string v){
     if(root == NULL){
        return NULL;
    }
    return root->find(root,v);
}

TreeNode* TreeDB::findProbe(string v){
     if(root == NULL){
        return NULL;
    }
    return root->findProbe(root,v,1);
}

void TreeDB::del(string val){
    if (root == NULL){
        return;
    }
    root->del(val,root);
    return;
}

void TreeDB::countActive(){
    activeCount = 0;
    if (root != NULL){ //makes sure tree is not empty
        activeHelper(root);
    }
    cout << activeCount << endl;
}

void TreeDB::activeHelper(TreeNode* cur){
    if (cur == NULL)
        return;

    if (cur->getEntry()->getActive() == true){
        activeCount += 1; //checks if active
    }
        activeHelper(cur->getLeft()); //goes down both subtrees
        activeHelper(cur->getRight());
}

void TreeDB::clear(){
    if (root != NULL)
        clearHelper(root);
        root = NULL; //set root to NULL for safety
}

void TreeDB::clearHelper(TreeNode* cur){
    if ((cur->getLeft() == NULL) && (cur->getRight() == NULL)){ //at node with no children
        delete cur;
        return;
    }
    else if ((cur->getLeft() == NULL) && (cur->getRight() != NULL)){ //if node only has children on right
        clearHelper(cur->getRight()); //go down right subtree
        delete cur;
        return;
    }
    else if ((cur->getLeft() != NULL) && (cur->getRight() == NULL)){ //if node only has children on left
        clearHelper(cur->getLeft()); //go down left subtree
        delete cur;
        return;
    }
    else{ //if node has 2 children
        clearHelper(cur->getLeft()); //go down both subtrees
        clearHelper(cur->getRight());
        delete cur;
        return;
    }
}