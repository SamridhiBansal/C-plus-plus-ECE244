
/* 
 * File:   Main.cpp
 * Author: Samridhi
 *
 * Created on November 15, 2016, 3:06 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

#include "DBentry.h"
#include "TreeDB.h"
#include "TreeNode.h"

using namespace std;

//Ostream Declarations:
ostream& operator<< (ostream& out, const DBentry& rhs){
  out << rhs.name << " : "<<rhs.IPaddress <<" : ";
    if(rhs.active == true)
        out<< "active"<<endl;
    else
        out << "inactive"<<endl;  
    return out;
}

int main() {
    
        cout.setf (ios::fixed); //make sure everything prints as decimals and not scientific notation    
        TreeDB *bigT = new TreeDB();
    
        string line,command;
        cout << "> ";
        getline (cin, line);

       while (!cin.eof() )
        {
        stringstream lineStream (line);
        lineStream >> command; 
        
        if(command == "insert"){
            string name, status;
            int IPaddress;
            bool active;
            
            lineStream>>name>>IPaddress>>status;
            
            if(status == "active"){
                active = true;
            }
            else{
                active = false; 
            }
            
            TreeNode* find = bigT->find(name);
                if(find != NULL){
                    cout << "Error: entry already exists”"<<endl;
                }
                else
                {
                    DBentry *newEntry = new DBentry(name,IPaddress,active);
                    bigT->insert(newEntry);
                    cout <<"Success"<<endl;
                }    
        }
        else if(command == "find"){
            
            string name;
            lineStream>>name;
            
            TreeNode* find = bigT->find(name);
                if(find == NULL){
                    cout << "Error: entry does not exist"<<endl;
                }
                else
                {
                    DBentry* found = find->getEntry();
                    cout << *found;
                }
        }
        else if(command == "remove"){
            
            string name;
            lineStream>>name;
            TreeNode* find = bigT->find(name);
                if(find == NULL){
                    cout << "Error: entry does not exist"<<endl;
                }
                else
                {
                   bigT ->del(name); 
                   cout<<"Success"<<endl;
                }
   
        }
        else if(command == "printall"){
            bigT->print_inorder();  
        }
        else if(command == "printprobes"){
            string name;
            lineStream>>name;   
            
            TreeNode* find = bigT->find(name);
                if(find == NULL){
                    cout << "Error: entry does not exist"<<endl;
                }
                else
                {
                   TreeNode* findProbe = bigT->findProbe(name); 
                }
            
        }
        else if(command == "removeall"){
            bigT->clear();
            cout<<"Success"<<endl;
        }
        
        else if(command == "countactive"){
            bigT->countActive();
        }
        else if(command == "updatestatus"){
            string name,status;
            lineStream>>name>>status;
            bool active;

            TreeNode* find = bigT->find(name);
                if(find == NULL){
                    cout << "Error: entry does not exist"<<endl;
                }
                else
                {
                    if(status == "active"){
                            active = true;
                        }
                        else{
                            active = false; 
                        }
                    find->getEntry()->setActive(active);
                    cout<<"Success"<<endl;
                }
        }
        else if (command == "quit"){
            break;
        }
        else{
            cout<<"Invalid command"<<endl;
        }
        
        cout << "> ";
        getline(cin, line);
        lineStream >> command;
        
       }
//     TreeDB *bigT = new TreeDB();
//     DBentry *hello = new DBentry("name34",1300000,true);
//     bigT->insert(new DBentry("name",1000000,true));
//     bigT->insert(new DBentry("name2",1040000,true));
//     bigT->insert(new DBentry("1name",102000,true));
//    bigT->insert(hello);
//     bigT->print_inorder();
//    
//     TreeNode* find = bigT->find("name34");
//    if(find == NULL){
//        cout << "Not Found!"<<endl;
//    }
//    else
//    {
//        cout<<"Found!" <<endl;
//        cout << find->getProbe()<<endl;
//    }
//  
//    bigT->del("1name");
//     bigT->print_inorder();
//    bigT ->del("name2");
//     bigT->print_inorder();
//   
//    TreeNode* find2 = bigT->find("name2");
//    if(find2 == NULL){
//        cout << "Not Found!"<<endl;
//    }
//    else
//     cout<<"Found!" <<endl;
//     bigT->print_inorder();
    
    return 0;
}

