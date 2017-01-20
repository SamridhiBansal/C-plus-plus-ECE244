#include "TreeNode.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

//TreeNode(DBentry* _entryPtr);// A useful constructor
//    ~TreeNode();// the destructor
//    void setLeft(TreeNode* newLeft);// sets the left child of the TreeNode.
//    void setRight(TreeNode* newRight);// sets the right child of the TreeNode
//    TreeNode* getLeft() const;// gets the left child of the TreeNode.
//    TreeNode* getRight() const;// gets the right child of the TreeNode
//    DBentry* getEntry() const; // returns a pointer to the DBentry the TreeNode contains. 

TreeNode::TreeNode(DBentry* _entryPtr){
    entryPtr = _entryPtr;
    left = NULL;
    right = NULL;
    probeNode = 1;
}

TreeNode::~TreeNode(){
    delete entryPtr;
    entryPtr = NULL;
    left = NULL;
    right = NULL;
    
}

void TreeNode::setLeft(TreeNode* newLeft){
    left = newLeft;
}

void TreeNode::setRight(TreeNode* newRight){
    right = newRight;
}

TreeNode* TreeNode::getLeft() const{
    return left;
}

TreeNode* TreeNode::getRight() const{
    return right;
}

DBentry* TreeNode::getEntry() const{
    return entryPtr;
}

int TreeNode::getProbe() const{
    return probeNode;
}
//    void insert(DBentry* v);
//    void print_inorder();
//    bool DBexists(DBentry* v);
//    void del(DBentry* v,TreeNode*& pp);
//    TreeNode* find(DBentry*v,TreeNode*r );

void TreeNode::insert(DBentry* v){
    if(entryPtr->getName() == v->getName())
        return;
    if(v->getName()<entryPtr->getName()){
        if(left == NULL){
            left = new TreeNode(v);
        }
        else
            left->insert(v);
    }
    else{
         if(right == NULL){
            right = new TreeNode(v);
        }
        else
            right->insert(v);
    }
    return;
}

void TreeNode::print_inorder(){
     if(left != NULL)
        left->print_inorder();
    cout<< *entryPtr;
    if(right != NULL)
        right->print_inorder();
}

TreeNode* TreeNode::find(TreeNode* r, string v){
    if(r == NULL)
		return NULL;
	if(r->entryPtr->getName() == v){
            return r;   
        }
		
	if(v< r->entryPtr->getName())
		return find(r->left,v);
	else
		return find(r->right,v);
}

TreeNode* TreeNode::findProbe(TreeNode* r, string v,int probe){
    if(r == NULL)
		return NULL;
	if(r->entryPtr->getName() == v){
            probeNode = probe;
            cout << probeNode<<endl;
            return r;
        }
		
	if(v< r->entryPtr->getName())
		return findProbe(r->left,v,probe+1);
	else
		return findProbe(r->right,v,probe+1);
}


void TreeNode::del(string v, TreeNode*& pp){
    if(v<entryPtr->getName()){
        if(left != NULL){
            left->del(v,left);
        }
        return;
    }
    if(v>entryPtr->getName()){
        if(right!=NULL)
            right->del(v,right);
        return;
    }
    if((left == NULL)&&(right == NULL)){
        pp = NULL;
        delete this;
    }
    else if((left == NULL)&&(right != NULL)){
        pp = right;
        right = NULL;
        delete this;
    }
   else if((left != NULL)&&(right == NULL)){
        pp = left;
        left = NULL;
        delete this;
    }
   else{
       DBentry* m = left->maximum();
       entryPtr->setName(m->getName());
       entryPtr->setIPaddress(m->getIPaddress());
       entryPtr->setActive(m->getActive());
       left->del(m->getName(),left);
   }
    return;
}

DBentry* TreeNode::maximum(){
    if(right == NULL){
        return entryPtr;
    }
    return right->maximum();
}