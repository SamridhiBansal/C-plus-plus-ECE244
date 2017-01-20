#include "Node.h"
#include "Resistor.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

ResistorList::ResistorList()
{
    head = NULL;
    //cout << "Creating New ResistorList" <<endl;
}
ResistorList::~ResistorList()
{

     Resistor *p;
     while (head != NULL) {
       p = head;
       head = p->getNext();
       delete p;
  }
    // cout << "Deleting ResistorList" <<endl;
}





Resistor* ResistorList::insertResistor(string name, double resistance, int N1,int N2){

    Resistor* r = new Resistor(name,resistance,N1,N2);

    Resistor* p = head;
    Resistor* prev = NULL;

   while (p != NULL) {
        prev = p;
        p = p->getNext();
    }
    r->setNext(p);
    if (prev == NULL) // head of the list!
      head = r;
    else
      prev->setNext(r);

   return r;

}
void ResistorList::printList(){

    Resistor *p = head;
    while(p!= NULL){

     cout.fill(' ');
     cout << setw(20) << left << p->getName();
     cout << setw(8) << right << p->getResistance();
     cout << " Ohms " << p->getNodeID1() << " -> " << p->getNodeID2() << endl;

        p = p->getNext();
    }
}

bool ResistorList::findResistor(string name){

    for (Resistor *cur = head; cur != NULL; cur = cur->getNext()){
    if (cur->getName() == name){
      return true;
    }
  }
  return false;
}

int ResistorList::numberOfResistors(){
    int counter = 0;
    Resistor *p = head;
    while(p!= NULL){
        counter++;
        p = p->getNext();
    }
    return counter;
}

void ResistorList::printResistor(string nameRes){

    for (Resistor *cur = head; cur != NULL; cur = cur->getNext()){
    if (cur->getName() == nameRes){
     cout.fill(' ');
     cout << setw(20) << left << cur->getName();
     cout << setw(8) << right << cur->getResistance();
     cout << " Ohms " << cur->getNodeID1() << " -> " << cur->getNodeID2() << endl;
    }
  }
}

void ResistorList::modifyResistor(string nameRes,double newRes,int doneonce){

    double oldVal = 0;
    for (Resistor *cur = head; cur != NULL; cur = cur->getNext()){
    if (cur->getName() == nameRes){
        oldVal = cur->getResistance();
        cur->setResistance(newRes);
    }
  }
    if(doneonce == 0){
        cout << "Modified: resistor "<<nameRes<< " from resistance " <<oldVal <<" Ohms" <<" to "<< newRes<<" Ohms "<<endl;
    }

}

bool ResistorList::deleteResistor(string name, int delete_count)
{
    Resistor * previous = NULL, *r_delete = NULL;

    if (head->getName() == name) {

        r_delete = head;
        head=head->getNext();

        delete r_delete;
        return true;
    }

    previous = head;
    r_delete = head->getNext();


    while (r_delete != NULL)
    {
        if (r_delete->getName() == name)
        {
            previous->setNext(r_delete->getNext());

            delete r_delete;
            return true;
        }
        previous = r_delete;
        r_delete = r_delete->getNext();
    }

    return false;
}

void ResistorList::delete_all_R()
{
  Resistor *p;
  while (head != NULL) {
    p = head;
    head = p->getNext();
    delete p;
  }
}
int ResistorList::num_Resistors()
{
    int number=0;
    for (Resistor *cur = head; cur != NULL; cur = cur->getNext())
    {
        number++;
    }
    return number;
}
double ResistorList::Calculate_A()
{
    Resistor*temp=head;
    double sum=0;
    double A;
    while (temp!=NULL){
        sum= sum+ 1/temp->getResistance();
        temp=temp->getNext();
    }
    A=1/sum;
    return A;
}
double* ResistorList::node_resistor_array()
{
    int numResistor;
    numResistor = num_Resistors();
    double * rarray = new double[numResistor];
    int i=0;
    Resistor*temp =head;
     while (temp!=NULL)
    {
        rarray[i]=temp->getResistance();

        i++;
        temp=temp->getNext();
    }

    return rarray;
}
int* ResistorList::node_array(int nodeid)
{
    int numResistor;
    numResistor = num_Resistors();
    int * narray = new int[numResistor];
    int i=0;
    Resistor*temp =head;
     while (temp!=NULL)
    {
        if (temp->getEndpoint1() == nodeid) narray[i]= temp->getEndpoint2();
        else narray[i]= temp->getEndpoint1();

        i++;
        temp=temp->getNext();
    }
    return narray;
}

