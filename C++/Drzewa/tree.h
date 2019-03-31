#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <vector>
#include <fstream>

struct BTNode {
  BTNode *leftN;
  BTNode *rightN;
  BTNode *parentN;
  int valueN;
  int weightN;
  int treeLevelN;
};

struct wezel *root;

#endif // TREE_H
