#include <iostream>
#include <fstream>
#include "tree.h"
#include "functions.h"

using namespace std;

int main()
{
	int returnCode = 0;
	ifstream in;
	ofstream out;
	string filename = "in.txt";

	try {
        BTNode * huffman = nullptr;
        huffman = new BTNode ();
        in.open(filename.c_str());
        if (!in.good())
            throw EXCEPTION_CODE::openError;
        while (!in.eof()) huffman = huffFile(in);
            BTNode *start = createTree(huffman);
            savefile(start, out);
            out.close();
	}
	catch (EXCEPTION_CODE error) {
		exceptions(error);
		returnCode = 1;
	}

	getchar();
	cin.ignore();

	return returnCode;
}
