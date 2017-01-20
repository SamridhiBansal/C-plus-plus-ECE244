#ifndef _TREENODE_H
#define _TREENODE_H

#include "DBentry.h"

class TreeNode {
private:
    DBentry* entryPtr;
    TreeNode* left;
    TreeNode* right;
    int probeNode;

public:
    
    TreeNode(DBentry* _entryPtr);// A useful constructor
    ~TreeNode();// the destructor
    void setLeft(TreeNode* newLeft);// sets the left child of the TreeNode.
    void setRight(TreeNode* newRight);// sets the right child of the TreeNode
    TreeNode* getLeft() const;// gets the left child of the TreeNode.
    TreeNode* getRight() const;// gets the right child of the TreeNode
    DBentry* getEntry() const; // returns a pointer to the DBentry the TreeNode contains. 
    
    //Helper Functions:
//    void insert(int v);
//    void print_inorder();
//    int minimum();
//    bool valueExists(int v);
//    void del(int v, TreeNode *& pp);
//    TreeNode* find(TreeNode* r,int v);
    
    void insert(DBentry* v);
    void print_inorder();
    bool DBexists(DBentry* v);
    void del(string v,TreeNode*& pp);
    TreeNode* find(TreeNode*r,string v);
    TreeNode* findProbe(TreeNode*r,string v, int probe);
    DBentry* maximum();
    int getProbe()const;
};

#endif 

