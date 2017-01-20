#ifndef NODELIST_H
#define NODELIST_H
#include "Node.h"

class NodeList{

private:
    Node*head;

public:
    NodeList();
    ~NodeList();
    Node* findNode(int Node_ID);
    Node* findOrInsert(int Node_ID);
    void printNodeList();
    bool findResistorEverywhere(string name);
    void printResistor(string nameRes);
    void modifyResistor(string nameRes,double newRes);
    void deleteResistor(string nameRes);
    void deleteall();
    void setVoltageAndFlag(int NodeID,double voltage,int zero);
    void printVoltage();
    double getNodeVoltage(int nodeID);
    void solve();

};

#endif /* NODELIST_H */

