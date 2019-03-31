#ifndef TREE_H
#define TREE_H
#include <list>
#include <iostream>
#include <string>
#include <fstream>



struct BTNode {

public:
	char sign;
	double number;
	BTNode *left;
	BTNode *right;
	BTNode *next;
};

enum EXCEPTION_CODE{
	openError,
	readError,
	saveError,
	lackOfMemory
};

#endif
