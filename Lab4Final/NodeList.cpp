#include "Node.h"
#include "Resistor.h"
#include "NodeList.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

NodeList::NodeList(){
    head = NULL;
}

NodeList::~NodeList(){
  Node *p;
  while (head != NULL) {
    p = head;
    head = p->getNext();
    delete p;
  }
   // cout << "Deleting NodeList";
}

Node* NodeList::findNode(int Node_ID){
    for(Node* curr = head; curr!=NULL; curr = curr->getNext()){

        if(curr->getID() == Node_ID){

            //cout << "Node: " << Node_ID <<"Found";
            return curr;
        }
    }

    return NULL;
}

Node* NodeList::findOrInsert(int Node_ID){


   //Finding Function:
    for(Node* curr = head; curr!=NULL; curr = curr->getNext()){

        if(curr->getID() == Node_ID){

            //cout << "Node: " << Node_ID <<"Found"<<endl;
            return curr;
        }
    }
    //Node not found so we need to create a new node;
    Node* n = new Node(Node_ID);

    //Inserting Function:

    Node *p = head;
    Node *prev = NULL;

    while (p != NULL &&  p->getID()< Node_ID) {
        prev = p;
        p = p->getNext();
    }
    n->setNext(p);
    if (prev == NULL) // head of the list!
      head = n;
    else
      prev->setNext(n);

   return n;

}

void NodeList::printNodeList(){

    cout << "Print:\n";
    Node *p = head;
    while(p!= NULL){
        p->printResistorList();
        p = p->getNext();
    }
}

bool NodeList::findResistorEverywhere(string name){

    for (Node *cur = head; cur != NULL; cur = cur->getNext()){
    if (cur->findResistor(name) == true ){
      return true;
    }
  }
  return false;

}
void NodeList::printResistor(string nameRes){
    int count = 0;
  for (Node *cur = head; cur != NULL; cur = cur->getNext()){
    if (cur->findResistor(nameRes) == true && count == 0){
        cur->printResistor(nameRes);
        count++;
    }
  }
}

void NodeList::modifyResistor(string nameRes,double newRes){
  int count = 0;
  for (Node *cur = head; cur != NULL; cur = cur->getNext()){
    if (cur->findResistor(nameRes) == true ){
        cur->modifyResistor(nameRes,newRes,count);
        count++;
    }
  }
}

void NodeList::deleteResistor(string nameRes)
{
    int delete_count=0;
     for (Node *cur = head; cur != NULL; cur = cur->getNext())
    {
            if (cur->deleteResistor(nameRes, delete_count) == true )delete_count++;
            if (delete_count==2)return;
    }
  return;
}

void NodeList::deleteall()
{
  Node *p;
  while (head != NULL) {
    p = head;
    head = p->getNext();
    p->delete_all_resistors();
    delete p;
  }
}

void NodeList::setVoltageAndFlag(int NodeID,double voltage,int zero){


    for (Node *cur = head; cur != NULL; cur = cur->getNext()){
    if ( cur->getID()== NodeID ){
      cur->setVoltage(voltage);
      if(zero == 0)
        cur->setFlagSet(false);
      else
          cur->setFlagSet(true);
    }
    }
}

void NodeList::printVoltage(){

    int flag=0;
    for (Node *cur = head; cur != NULL; cur = cur->getNext()){
        if( cur->getFlagSet()){
            flag = 1;
        }
        else
            flag = 0;
        cout <<"Node: "<<cur->getID()<<" has "<<cur->getVoltage()<<" and flag is "<<flag<<endl;
    }

}
double NodeList::getNodeVoltage(int nodeID)
{
   Node *p = head;
    while(p!= NULL){
       if(p->getID() == nodeID){

            return p->getVoltage();
       }

        p = p->getNext();
    }

}
void NodeList::solve(){

   double A, B=0;
   double prev_volt, new_volt; // To compare the old and new node voltage and find error
   double error=1;
   double *r_array; // This array collect all resistance valves connected to the node
    int *n_array;  //This array collect all other nodes connected to the node
    int i;
    bool flag=false;
   Node*temp=head;


   while (temp!=NULL){
        if (temp->getFlagSet() == true) flag=true;
        temp=temp->getNext();
    }

    if (flag==false){
        cout<< "Error: no nodes have their voltage set\n";
        return;
    }
    while (error > 0.0001){
        error=0;
        temp =head;


   while (temp!=NULL)
    {
        if(temp->getFlagSet()==false)
        {
            B=0;
            prev_volt=temp->getVoltage();

            A=temp->Calculate_A();
            r_array = temp->node_resistor_array();
            n_array = temp->node_array(temp->getID());

            for ( i=0; i < temp->num_Resistors(); i++){
                B = B+ getNodeVoltage(*(n_array+i))/(*(r_array+i));
            }
            delete[] r_array; // free the memory
            delete[] n_array;// free the memory
            new_volt = A*B;
            if ((abs(new_volt - prev_volt) > 0.0001)||(error > 0.0001)) error = (abs(new_volt - prev_volt));

            temp->setSolveVoltage(new_volt);
        }
        temp=temp->getNext();
   }

}
    cout << "Solve:" << endl;

    Node *p = head;
    while(p!= NULL){
        cout <<  "Node " << p->getID() << ": " <<  p->getVoltage() <<  " V " << endl;
        p = p->getNext();
    }
    p=head;
    while(p!= NULL){
        if (p->getFlagSet() == false) p->clearVoltage();
        p = p->getNext();
    }


}


