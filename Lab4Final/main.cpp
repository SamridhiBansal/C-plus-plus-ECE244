/*
 * File:   Main.cpp
 * Author: Samridhi
 *
 * Created on October 14, 2016, 11:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "RParser.h"
#include "Node.h"
#include "Resistor.h"
#include "ResistorList.h"
#include "NodeList.h"
#define MIN_ITERATION_CHANGE 0.0001

using namespace std;

int main(int argc, char** argv) {

   NodeList* node_list = new NodeList();
   cout<< fixed <<setprecision(2);
    int nodeid;
    int i;
    double rvalue;


    string line, command ,nextCommand;
    string name,resistance;
    int nodeid1, nodeid2,nodeID;
    double voltage;



    cout << "> ";
    getline (cin, line);

   while (!cin.eof() )
    {
        stringstream lineStream (line);
        lineStream >> command;

       if(command == "setV")
        {
            if( setV(lineStream))
            {
                stringstream lineStream (line);
                lineStream >> command >> nodeID >> voltage;
                Node* n = node_list->findNode(nodeID);

                if(n == NULL){
                    cout<< "Error: node "<<nodeID<<" not found"<<endl;
                }
                if(n!=NULL){
                    node_list->setVoltageAndFlag(nodeID,voltage,1);
                    cout << "Set: node "<< nodeID << " to " << voltage << " Volts\n";
                }

                // node_list->printVoltage();
                command = "Nothing";
            }
        }

        else if(command == "insertR" )
        {
            if (insertR(lineStream)){

                stringstream lineStream (line);
                lineStream >> command >> name >> rvalue >> nodeid1 >> nodeid2;

                if(node_list->findResistorEverywhere(name)){
                    cout<<"Error: resistor "<< name <<" already exists"<<endl;
                }

                else{

                Node *Node1 = node_list->findOrInsert(nodeid1);
                Node *Node2 = node_list ->findOrInsert(nodeid2);

                Node1->addResistor(name,rvalue,nodeid1,nodeid2);
                Node2->addResistor(name,rvalue,nodeid1,nodeid2);

                cout<<"Inserted: "<< name <<" "<<rvalue<<" Ohms "<<nodeid1<<" -> "<<nodeid2<<endl;
            }

            }
            command = "Nothing";

        }
        else if (command == "modifyR" )
        {
            if(modifyR (lineStream))
            {
                stringstream lineStream (line);
                lineStream >> command >> name >> rvalue;
                if(!node_list->findResistorEverywhere(name)){
                        cout << "Error: resistor "<<name<<" not found"<<endl;
                    }
                 else{
                        node_list->modifyResistor(name,rvalue);
                    }
            }

            command = "Nothing";
        }

         else if (command == "printNode")
        {
            int flag;
            flag = printNode (lineStream);

            int NodeID;
            string allCommand;


            if(flag ==1)//Flag for node value
            {
               stringstream lineStream (line);
               lineStream >> command >> NodeID;
               Node* n = node_list->findNode(NodeID);
               if (n != NULL){
                n->printResistorList();
               }
               else {
                   cout << "Error: node "<<NodeID<<" not found"<<endl;
               }
            }
            if(flag==2)//Flag for all
            {
                stringstream lineStream (line);
                lineStream >> command >> allCommand;
                node_list->printNodeList();

            }

            command = "Nothing";

        }
         else if (command == "deleteR")
        {
            int flag2;
            flag2 = deleteR (lineStream);
            if(flag2 ==1)//Typed not all
            {
               string nameRes;
               stringstream lineStream (line);
               lineStream >> command >> nameRes;
                if(!node_list->findResistorEverywhere(nameRes)){
                        cout << "Error: resistor "<<nameRes<<" not found"<<endl;
                    }
                 else{
                        node_list->deleteResistor(nameRes);
                    }

            }
            if(flag2==2) //Typed all
            {
                string allCommand;
                stringstream lineStream (line);
               lineStream >> command >> allCommand;
               node_list->deleteall();


            }

            command = "Nothing";

        }
         else if(command == "printR"){

          if (printR (lineStream))
            {
                stringstream lineStream (line);
                lineStream >> command >> name;
                    if(!node_list->findResistorEverywhere(name)){
                        cout << "Error: resistor "<<name<<" not found"<<endl;
                    }
                    else{
                        node_list->printResistor(name);
                    }
                command = "Nothing";
            }
         }

         else if (command == "unsetV")
        {
             if( unsetV(lineStream))
            {
                stringstream lineStream (line);
                lineStream >> command >> nodeID;
                Node* n = node_list->findNode(nodeID);

                if(n == NULL){
                    cout<< "Error: node "<<nodeID<<" not found"<<endl;
                }
                if(n!=NULL){
                    node_list->setVoltageAndFlag(nodeID,0.0,0);
                    cout << "Unset: the solver will determine the voltage of node "<< nodeID <<"\n";
                }
                //node_list->printVoltage();

                command = "Nothing";
            }
        }
         else if (command == "solve")
        {
             node_list->solve();
            command = "Nothing";
        }
        else if (command == "quit")
        {
            break;
        }
        else
        {
            cout << "Error: invalid command" << endl;
        }
        cout << "> ";
        getline(cin, line);
        lineStream >> command;
    }
     node_list->deleteall();
     delete node_list;
    return 0;
}
