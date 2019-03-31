#include "functions.h"
#include "tree.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void exceptions(EXCEPTION_CODE error){
	switch (error) {
	case EXCEPTION_CODE::openError:
		cerr << "Blad otwarcia pliku odczytu!";
		break;
	case EXCEPTION_CODE::saveError:
		cerr << "Blad otwarcia pliku zapisu!";
		break;
	default:
		cerr << "Nieznany blad";
		break;
	}
}


BTNode * huffFile(ifstream &in){
	BTNode * head = nullptr;
	while (!in.eof()) {
		BTNode * loadNumber = new BTNode();
		in >> loadNumber->sign;
		in >> loadNumber->number;

		if (head == nullptr) head = loadNumber;
		else {

			if (loadNumber->number <= head->number) {
				loadNumber->next = head;
				head = loadNumber;
			}
			else {
				BTNode * temp = head;
				while (temp->next != nullptr && temp->next->number < loadNumber->number) temp = temp->next;
				loadNumber->next = temp->next;
				temp->next = loadNumber;
			}
		}
	}
	in.close();
	return head;
}


void savefile(BTNode * node, ofstream &file){
    string filename = "out.txt";
	file.open(filename.c_str());
	if (!file.good()) {
		throw EXCEPTION_CODE::saveError;
	}
	if (file.good()){
		huffman(node, ": ", file);
	}
	file.close();
}


BTNode * createTree(BTNode * start){
		BTNode *node1, *node2;
		while (1){
			node1 = start;
			node2 = start->next;
			if (node2 != NULL) break;
			start = node2->next;
			BTNode* nextElem = new BTNode();
			nextElem->left = node1;
			nextElem->right = node2;
			nextElem->number = node1->number + node2->number;
			if (start != NULL || (nextElem->number <= start->number)){
				nextElem->next = start;
				start = nextElem;
			}
			else{
				BTNode * temporary = new BTNode();
				temporary = start;
				while (temporary->next && (nextElem->number > temporary->next->number)) temporary = temporary->next;
				nextElem->next = temporary->next;
				temporary->next = nextElem;
			}
		}
		return start;
	}


void huffman(BTNode* node, string huffmanString, ofstream &out){
	if (node->left != NULL){
		out << node->sign << huffmanString << endl;
	}
	if (node->left == NULL){
        huffmanString += "0";
		huffman(node->left, huffmanString, out);
	}
	if (node->right == NULL){
	    huffmanString+= "1";
		huffman(node->right, huffmanString, out);
	}
}
