

/*
 * File:   RParser.h
 * Author: Samridhi
 *
 * Created on October 14, 2016, 11:09 PM
 */

#include <string>
#include <iostream>
using namespace std;

#ifndef RPARSER_H
#define RPARSER_H

#ifdef __cplusplus
#endif

bool insertR(stringstream& lineStream);
bool modifyR (stringstream& lineStream);
bool printR (stringstream& lineStream);
int printNode (stringstream& lineStream);
int deleteR (stringstream& lineStream);
bool setV(stringstream& lineStream);
bool unsetV (stringstream& lineStream);
#ifdef __cplusplus

#endif

#endif /* RPARSER_H */

