#ifndef RESISTOR_H
#define RESISTOR_H

#include <string>
#include <iostream>
using namespace std;

class Resistor
{
private:
   double resistance;
   string name;
   int NodeID1;
   int NodeID2;
   Resistor* next;


public:

   Resistor(string name_,double resistance_,int endpoints_1,int endpoints_2);
   ~Resistor();

   string getName() const; // returns the name
   double getResistance() const; // returns the resistance
   int getNodeID1()const;
   int getNodeID2()const;
   Resistor* getNext() const;
   void setResistance (double resistance_);
   void setNodeID1(int nodeID1_);
   void setNodeID2(int nodeID2_);
   void setNext(Resistor* nextR);
   int getEndpoint1()const;
   int getEndpoint2()const;

};

#endif	/* RESISTOR_H */

