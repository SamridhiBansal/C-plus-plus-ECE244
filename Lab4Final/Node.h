#ifndef NODE_H
#define NODE_H


/*
 * File:   Node.h
 * Author: JC and VB
 * Author: TSA
 *
 * Updated on August 24, 2016, 01:40 PM
 * Created on October 6, 2013, 12:58 PM
 */

#include"Resistor.h"
#include "ResistorList.h"

class Node
{
private:
    int NodeID;
    Node *next;
    double voltage;
    bool flagSet;
    ResistorList resistor_list;

public:
   Node(int Node_ID);
   ~Node();
   int getID()const;
   void setID(int Node_ID);
   Node* getNext()const;
   double getVoltage()const;
   bool getFlagSet()const;
   void setNext(Node* nextN);
   void setVoltage(double voltage);
   void setFlagSet(bool flagSetter);
   void addResistor(string name,double resistance,int nodeID1,int nodeID2);
   void printResistorList();
   bool findResistor(string name);
   void printResistor(string nameRes);
   void modifyResistor(string nameRes,double newRes,int doneonce);
   bool deleteResistor(string nameRes,int delete_count);
   void delete_all_resistors();
   int num_Resistors();
    double Calculate_A();
    double * node_resistor_array();
   int *node_array(int nodeid);
   void clearVoltage();
   void setSolveVoltage(double volt);

};

#endif	/* NODE_H */


