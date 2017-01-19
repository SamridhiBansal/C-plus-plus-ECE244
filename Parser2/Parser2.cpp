/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Parser2.cpp
 * Author: Samridhi
 *
 * Created on October 1, 2016, 1:00 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

#define MAX_NODE_NUMBER 5000;

using namespace std;

/*
 * 
 */

void Parser();
void insertR(stringstream& lineStream);
void modifyR (stringstream& lineStream);
void printR (stringstream& lineStream);
void printNode (stringstream& lineStream);
void deleteR (stringstream& lineStream);

int main(int argc, char** argv) {

    Parser();
}

void Parser()
{
 string line, command ,nextCommand;
 string name,resistance,nodeid1, nodeid2;
 
    cout << "> ";
    getline (cin, line);
    
    while (!cin.eof())
    {
        stringstream lineStream (line);
        lineStream >> command;
        
        if(command == "insertR")
        {
            insertR(lineStream);
            command = "Nothing";   
        }
        else if (command == "modifyR")
        {
            modifyR (lineStream);
            command = "Nothing"; 
        }
         else if (command == "printR")
        {
            printR (lineStream);
            command = "Nothing";
        }
         else if (command == "printNode")
        {
            printNode (lineStream);
            command = "Nothing"; 
        }
         else if (command == "deleteR")
        {
            deleteR (lineStream);
            command = "Nothing"; 
        }
        else if (command == "quit")
        {
            break;
        }
        else if(command == "\n")
        {
            cout << "Error: invalid command" << endl;
        }
        else
        {
            cout << "Error: invalid command" << endl;
        }
        cout << "> ";
        getline(cin, line);
        lineStream >> command;
    }
}

void insertR(stringstream& lineStream)      
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
            return;
        }
        if (name == "all")
        {
            flagAll = 1;
        }

    lineStream >> resistance;
        if(lineStream.fail())
        {
         lineStream.clear();   
         lineStream >> extraRes;
            if(lineStream.fail())
                {
                if(flagAll == 1)
                {
                    cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
                    return;
                }
                 cout << "Error: Too few arguments"<<endl;
                 return;
                }
            else
            {
                cout << "Error: invalid argument"<<endl;
                return;
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
                  return;
                }
          }
            if (resistance<0)
            {
              cout << "Error: negative resistance" << endl;
              return;
            }
        }

    lineStream >> nodeID1;
        if(lineStream.fail())
        {
           lineStream.clear();
           lineStream >> extraN1;
                if (lineStream.fail())
                {
                    if(flagAll == 1)
                    {
                        cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
                        return;
                    }
                    cout << "Error: Too few arguments"<< endl;
                    lineStream.clear();
                    return;
                }    
                else
                {
                    cout << "Error: invalid argument"<<endl;
                    return;
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
                  return;
                }
          }
         if( (nodeID1 > 5000)||(nodeID1)<0 ) 
            {
                cout<< "Error: node "<<nodeID1<< " is out of permitted range 0-5000" <<endl;
                return;
            }
        }  
     
    lineStream >> nodeID2;
        if(lineStream.fail())
        {
            lineStream.clear();
            lineStream >> extraN2;
                if (lineStream.fail())
                {
                    if(flagAll == 1)
                    {
                        cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
                        return;
                    }
                    cout<< "Error: Too few arguments"<< endl;
                    lineStream.clear();
                    return;
                }
                else
                {
                    cout << "Error: invalid argument" << endl;
                    return;
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
                    if(flagAll == 1)
                    {
                        cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
                        return;
                    }
                    cout << "Error: Too many arguments" << endl;
                    return;
                }

            }
            if ((c !=' ') && (c!='\n'))
            {
                lineStream >> extraN2;
                if (!lineStream.fail())
                {
                  cout << "Error: invalid argument" << endl; 
                  lineStream.clear();
                  return;
                }
            }
            if( (nodeID2 > 5000)||(nodeID2)<0 ) 
            {
                cout<< "Error: node "<<nodeID2<< " is out of permitted range 0-5000" <<endl;
                return;
            }
        }
   
    if(flagAll == 1)
    {
      cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
      return;
    }
    if (nodeID1 == nodeID2)
    {
        cout << "Error: both terminals of resistor connect to node " << nodeID1<<endl;
        return;
    }
    
   cout << "Inserted: resistor " << name << " " <<fixed<<setprecision(2)<< resistance << " Ohms "
            << nodeID1 << " -> " << nodeID2 << endl;

}

void modifyR (stringstream& lineStream)
{
    string name,extraRes;
    double resistance;
    int flagAll = 0;
    char c;

    lineStream >> name;
        if(lineStream.fail())
        {
            cout << "Error: Too few arguments"<<endl;
            lineStream.clear();
            return;
        }
        if (name == "all")
        {
            flagAll = 1;
        }
    
    lineStream >> resistance;
        if(lineStream.fail())
        {
         lineStream.clear();   
         lineStream >> extraRes;
            if(lineStream.fail())
                {
                if(flagAll == 1)
                {
                    cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
                    return;
                }
                 cout << "Error: Too few arguments"<<endl;
                 return;
                }
            else
            {
                cout << "Error: invalid argument"<<endl;
                return;
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
                  return;
                }
          }
            if (resistance<0)
            {
              cout << "Error: negative resistance" << endl;
              return;
            }
          if( c == ' ')
            {
                lineStream >> extraRes;
                if(!lineStream.fail())
                {
                    if(flagAll == 1)
                    {
                        cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
                        return;
                    }
                    cout << "Error: Too many arguments" << endl;
                    return;
                }

            }
        }
    if(flagAll == 1)
        {
          cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
          return;
        }
    
    cout << "Modified: resistor " << name << " to " << resistance << " Ohms " <<endl;
    return;

}

void printR (stringstream& lineStream)
{
    string name;
    string extraEntry;
    char c;
    
    lineStream >> name;
        if(lineStream.fail())
        {
            cout << "Error: Too few arguments"<<endl;
            lineStream.clear();
            return;
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
                    return;
                }

            }
        }
        
    if(name == "all")
    {
        cout << "Print: all resistors"<<endl;
        return;
    }
    else
    {
        cout << "Print: resistor " << name <<endl;
        return;
    }
    return;
}

void printNode (stringstream& lineStream)
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
                return;
            }
            else
            {
                if(name == "all")
                {
                    cout << "Print: all nodes" <<endl;
                    return;
                }
                else
                {
                    cout << "Error: invalid argument"<<endl;
                    return;
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
                  return;
                }
          }
          if( c == ' ')
            {
                lineStream >> extraEntry;
                
                if((nodeID > 5000) || (nodeID < 0))
                {
                   cout<< "Error: node "<<nodeID <<" is out of permitted range 0-5000" <<endl;
                   return;

                }
                if(!lineStream.fail())
                {
                    cout << "Error: Too many arguments" << endl;
                    return;
                }

            }
        }
    if((nodeID > 5000) || (nodeID < 0))
    {
       cout<< "Error: node "<<nodeID <<" is out of permitted range 0-5000" <<endl;
       return;
    
    }
    cout<< "Print: node "<< nodeID <<endl;
    return;

}

void deleteR (stringstream& lineStream)
{
    string name;
    string extraEntry;
    char c;
    
    lineStream >> name;
        if(lineStream.fail())
        {
            cout << "Error: Too few arguments"<<endl;
            lineStream.clear();
            return;
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
                    return;
                }

            }
        }
        
    if(name == "all")
    {
        cout << "Deleted: all resistors"<<endl;
        return;
    }
    else
    {
        cout << "Deleted: resistor " << name <<endl;
        return;
    }
    return;
}