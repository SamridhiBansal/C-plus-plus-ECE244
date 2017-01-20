/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "RParser.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

bool unsetV (stringstream& lineStream)
{
    string name;
    string extraEntry;
    char c;

    lineStream >> name;
        if(lineStream.fail())
        {
            cout << "Error: Too few arguments"<<endl;
            lineStream.clear();
            return false;
        }
        else
        {
            c = lineStream.peek();
            if( c == ' ')
            {
                lineStream >> extraEntry;
                if(!lineStream.fail())
                {
                    cout << "Error: Too many arguments" << endl;
                    return false;
                }

            }
        }


    return true;
}

bool setV(stringstream& lineStream)
{
    string extraNodeid,extraVoltage;
    int nodeID;
    double voltage;
    char c;

    lineStream >> nodeID;
        if(lineStream.fail())
        {
         lineStream.clear();
         lineStream >> extraNodeid;
            if(lineStream.fail())
                {
                 cout << "Error: Too few arguments"<<endl;
                 return false;
                }
            else
            {
                cout << "Error: invalid argument"<<endl;
                return false;
            }
        }
        else
        {
          c = lineStream.peek();
          if((c != ' ') && (c != '\n'))
          {
              lineStream >> extraNodeid;
              if (!lineStream.fail())
                {
                  cout << "Error: invalid argument" << endl;
                  lineStream.clear();
                  return false;
                }
          }
        }

     lineStream >> voltage;
        if(lineStream.fail())
        {
         lineStream.clear();
         lineStream >> extraVoltage;
            if(lineStream.fail())
                {
                 cout << "Error: Too few arguments"<<endl;
                 return false;
                }
            else
            {
                cout << "Error: invalid argument"<<endl;
                return false;
            }
        }
        else
        {
          c = lineStream.peek();
          if((c != ' ') && (c != '\n'))
          {
              lineStream >> extraVoltage;
              if (!lineStream.fail())
                {
                  cout << "Error: invalid argument" << endl;
                  lineStream.clear();
                  return false;
                }
          }
          if( c == ' ')
            {
                lineStream >> extraVoltage;
                if(!lineStream.fail())
                {
                    cout << "Error: Too many arguments" << endl;
                    return false;
                }

            }
        }


    return true;


}
bool insertR(stringstream& lineStream)
{
    string name,extraRes,extraN1,extraN2;
    double resistance;
    int nodeID1, nodeID2;
    int flagAll = 0;
    char c;

    lineStream >> name;
        if(lineStream.fail())
        {
           cout << "Error: Too few arguments"<<endl;
            lineStream.clear();
            return false;
        }
        if (name == "all")
        {
            cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
            return false;
        }

    lineStream >> resistance;
        if(lineStream.fail())
        {
         lineStream.clear();
         lineStream >> extraRes;
            if(lineStream.fail())
                {
                 cout << "Error: Too few arguments"<<endl;
                 return false;
                }
            else
            {
                cout << "Error: invalid argument"<<endl;
                return false;
            }
        }
        else
        {
          c = lineStream.peek();
          if((c != ' ') && (c != '\n'))
          {
              lineStream >> extraRes;
              if (!lineStream.fail())
                {
                  cout << "Error: invalid argument" << endl;
                  lineStream.clear();
                  return false;
                }
          }
            if (resistance<0)
            {
              cout << "Error: negative resistance" << endl;
              return false;
            }
        }

    lineStream >> nodeID1;
        if(lineStream.fail())
        {
           lineStream.clear();
           lineStream >> extraN1;
                if (lineStream.fail())
                {
                    cout << "Error: Too few arguments"<< endl;
                    lineStream.clear();
                    return false;
                }
                else
                {
                    cout << "Error: invalid argument"<<endl;
                    return false;
                }
        }
        else
        {
          c = lineStream.peek();
          if((c != ' ') && (c != '\n'))
          {
              lineStream >> extraN1;
              if (!lineStream.fail())
                {
                  cout << "Error: invalid argument" << endl;
                  lineStream.clear();
                  return false;
                }
          }
       /*  if( (nodeID1)<0 )
            {
                cout<< "Error: node "<<nodeID1<< " is negative" <<endl;
                return false;
            }*/
        }

    lineStream >> nodeID2;
        if(lineStream.fail())
        {
            lineStream.clear();
            lineStream >> extraN2;
                if (lineStream.fail())
                {
                    cout<< "Error: Too few arguments"<< endl;
                    lineStream.clear();
                    return false;
                }
                else
                {
                    cout << "Error: invalid argument" << endl;
                    return false;
                }

        }
        else
        {
            c = lineStream.peek();
            if( c == ' ')
            {
                lineStream >> extraN2;
                if(!lineStream.fail())
                {
                    cout << "Error: Too many arguments" << endl;
                    return false;
                }

            }
            if ((c !=' ') && (c!='\n'))
            {
                lineStream >> extraN2;
                if (!lineStream.fail())
                {
                  cout << "Error: invalid argument" << endl;
                  lineStream.clear();
                  return false;
                }
            }
         /*  if( nodeID1<0 )
            {
                cout<< "Error: node "<<nodeID1<< " is negative" << endl;
                return false;
            }*/
        }

    if (nodeID1 == nodeID2)
    {
        cout << "Error: both terminals of resistor connect to node " << nodeID1<<endl;
        return false;
    }


    return true;

}

bool modifyR (stringstream& lineStream)
{
    string name,extraRes;
    double resistance;
    char c;

    lineStream >> name;
        if(lineStream.fail())
        {
            cout << "Error: Too few arguments"<<endl;
            lineStream.clear();
            return false;
        }
        if (name == "all")
        {

            cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
            return false;
        }

    lineStream >> resistance;
        if(lineStream.fail())
        {
         lineStream.clear();
         lineStream >> extraRes;
            if(lineStream.fail())
                {
                cout << "Error: Too few arguments"<<endl;
                 return false;
                }
            else
            {
                cout << "Error: invalid argument"<<endl;
                return false;
            }
        }
        else
        {
          c = lineStream.peek();
          if((c != ' ') && (c != '\n'))
          {
              lineStream >> extraRes;
              if (!lineStream.fail())
                {
                  cout << "Error: invalid argument" << endl;
                  lineStream.clear();
                  return false;
                }
          }
            if (resistance<0)
            {
              cout << "Error: negative resistance" << endl;
              return false;
            }
          if( c == ' ')
            {
                lineStream >> extraRes;
                if(!lineStream.fail())
                {
                    cout << "Error: Too many arguments" << endl;
                    return false;
                }

            }
        }
    //cout << "Modified: resistor " << name << " to " << resistance << " Ohms " <<endl;
    return true;

}

bool printR (stringstream& lineStream)
{
    string name;
    string extraEntry;
    char c;

    lineStream >> name;
        if(lineStream.fail())
        {
           cout << "Error: Too few arguments"<<endl;
            lineStream.clear();
            return false;
        }
        else
        {
            c = lineStream.peek();
            if( c == ' ')
            {
                lineStream >> extraEntry;
                if(!lineStream.fail())
                {
                    cout << "Error: Too many arguments" << endl;
                    return false;
                }

            }
        }


    return true;
}

int printNode (stringstream& lineStream)
{
    int nodeID;
    string name;
    char c;
    string extraEntry;

    lineStream >> nodeID;
    if(lineStream.fail())
    {
        lineStream.clear();
        lineStream >> name;
            if(lineStream.fail())
            {
               cout << "Error: too few arguments" << endl;
                return 0;
            }
            else
            {
                if(name == "all")
                {

                    return 2;
                }
                else
                {
                    cout << "Error: invalid argument"<<endl;
                    return 0;
                }

            }
    }
    else
    {
        c = lineStream.peek();
          if((c != ' ') && (c != '\n'))
          {
              lineStream >> extraEntry;
              if (!lineStream.fail())
                {
                  cout << "Error: invalid argument" << endl;
                  lineStream.clear();
                  return 0;
                }
          }
          if( c == ' ')
            {
                lineStream >> extraEntry;

                if(nodeID < 0)
                {
                    cout<< "Error: node "<<nodeID<< " is neagtive" << endl;
                   return 0;

                }
                if(!lineStream.fail())
                {
                    cout << "Error: Too many arguments" << endl;
                    return 0;
                }

            }
        }
   /* if( nodeID < 0)
    {
       cout<< "Error: node "<<nodeID<< " is negative" <<endl;
       return 0;

    }*/

    return 1;

}

int deleteR (stringstream& lineStream)
{
    string name;
    string extraEntry;
    char c;

    lineStream >> name;
        if(lineStream.fail())
        {
            cout << "Error: Too few arguments"<<endl;
            lineStream.clear();
            return 0;
        }
        else
        {
            c = lineStream.peek();
            if( c == ' ')
            {
                lineStream >> extraEntry;
                if(!lineStream.fail())
                {
                    cout << "Error: Too many arguments" << endl;
                    return 0;
                }

            }
        }

    if(name == "all")
    {
        cout << "Deleted: all resistors"<<endl;
        return 2;
    }
    else
    {
        cout << "Deleted: resistor " << name <<endl;
        return 1;
    }
    return 1;
}
