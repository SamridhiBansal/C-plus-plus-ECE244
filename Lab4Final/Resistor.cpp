#include "Resistor.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

//double resistance;
//   string name;
//   int NodeID1;
//   int NodeID2;
//   Resistor* next;


Resistor::Resistor(string name_,double resistance_,int endpoints_1,int endpoints_2){
    name = name_;
    resistance = resistance_;
    NodeID1 = endpoints_1;
    NodeID2 = endpoints_2;
    next = NULL;
}


Resistor::~Resistor(){

}
string Resistor::getName() const{
    return name;
}
double Resistor::getResistance() const{
    return resistance;
}

Resistor* Resistor::getNext() const{
    return next;
}

void Resistor::setResistance(double resistance_){
    resistance=resistance_;
}

void Resistor::setNext(Resistor* nextR){
    next=nextR;
}

void Resistor::setNodeID1(int nodeID1_){
    NodeID1=nodeID1_;
}

void Resistor::setNodeID2(int nodeID2_){
    NodeID2=nodeID2_;
}

int Resistor::getNodeID1()const{
    return NodeID1;
}

int Resistor::getNodeID2()const{
    return NodeID2;
}
int Resistor::getEndpoint1()const{
return NodeID1;

}

 int Resistor::getEndpoint2()const{
return NodeID2;

}
//void Resistor::print(){
//
//     cout.fill('_');
//     cout << setw(20) << left << name;
//     cout << setw(8) << right << resistance;
//     cout << " Ohms " << endpointNodeIDs[0] << " -> " << endpointNodeIDs[1] << "\n";
//}
