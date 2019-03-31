#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "tree.h"
#include <list>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void exceptions(EXCEPTION_CODE error);
BTNode *huffFile(ifstream &in);
void savefile(BTNode *root, ofstream &out);
BTNode *createTree(BTNode *start);
void huffman(BTNode* node, string huffmanString, ofstream &out);


#endif
