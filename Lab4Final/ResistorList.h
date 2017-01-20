
#ifndef RESISTORLIST_H
#define RESISTORLIST_H
#include "Resistor.h"



class ResistorList{
private:
    Resistor *head;
public:
    ResistorList();
    ~ResistorList();
    Resistor* insertResistor(string name, double resistance, int N1,int N2);
    void printList();
    int numberOfResistors();
    bool findResistor(string name);
    void printResistor(string nameRes);
    void modifyResistor(string nameRes,double newRes,int doneonce);
    bool deleteResistor(string nameRes,int delete_count);
    void delete_all_R();
    int num_Resistors();
    double Calculate_A();
    double* node_resistor_array();
    int* node_array(int nodeid);
};


#endif /* RESISTORLIST_H */

