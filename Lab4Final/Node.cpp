#include "Node.h"
#include "Resistor.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;


Node::Node(int Node_ID){

    NodeID = Node_ID;
    next = NULL;
    voltage = 0;
    flagSet = false;
   // cout << "Creating node:" << NodeID <<endl;
}

Node::~Node(){

   // cout << "Deleteing Node:" << NodeID <<endl;
}

int Node::getID()const{
   return NodeID;
}

void Node::setID(int Node_ID){
    NodeID = Node_ID;
}

Node* Node::getNext() const{
    return next;
}

void Node::setNext(Node* nextN){
    next = nextN;
}

double Node::getVoltage() const{
    return voltage;
}

bool Node::getFlagSet() const{
    return flagSet;
}

void Node::setFlagSet(bool flagSetter){
    flagSet = flagSetter;
}

void Node::setVoltage(double voltageN){
    voltage = voltageN;
}

void Node::addResistor(string name,double resistance,int nodeID1,int nodeID2){
    resistor_list.insertResistor(name,resistance,nodeID1,nodeID2);
}

void Node::printResistorList(){
    cout << "Connections at node " <<NodeID<<": "<< resistor_list.numberOfResistors() <<" resistor(s)"<<endl;
    resistor_list.printList();
}

bool Node::findResistor(string name){
    return resistor_list.findResistor(name);
}

void Node::printResistor(string nameRes){

        resistor_list.printResistor(nameRes);
}

void Node::modifyResistor(string nameRes, double newRes, int doneonce){
    resistor_list.modifyResistor(nameRes,newRes,doneonce);
}

bool Node::deleteResistor(string name, int delete_count){
    return resistor_list.deleteResistor(name, delete_count);

}

void Node::delete_all_resistors(){
    resistor_list.delete_all_R();
}
int Node::num_Resistors()
{
    return resistor_list.num_Resistors();
}
double Node::Calculate_A()
{
    return resistor_list.Calculate_A();
}
double * Node:: node_resistor_array()
{
    return resistor_list.node_resistor_array();
}
int* Node::node_array(int nodeid)
{
    return resistor_list.node_array(nodeid);
}
void Node::setSolveVoltage(double volt)
{
    voltage=volt;
}
void Node::clearVoltage()
{
    voltage=0;

}
