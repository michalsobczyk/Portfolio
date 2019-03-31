#include "functions.h"
#include "classfile.h"

int biggestVertex (ifstream &vertex){
    vertex.seekg(1);
    int maxVertex, tempVertex;
    vertex >> maxVertex;
    while (!vertex.eof()){
        vertex >> tempVertex;
        if (tempVertex > maxVertex) maxVertex = tempVertex;
    }
    vertex.seekg(0);
    return maxVertex;
}

void addTab (ifstream &vertex, List** &tab){
    int vertexNumber;
    int fromVertex, toVertex;
    vertex >> vertexNumber;
    for(int i = 0; i < vertexNumber; i++){
        vertex >> fromVertex;
        vertex >> toVertex;
		tab[fromVertex - 1]->addwart(toVertex);
		tab[toVertex - 1]->addwart(fromVertex);
    }
}

void showIncidenceList(int maxVertex, List** &tab){
	for (int i = 0; i < maxVertex; ++i) {
		cout << i + 1 << " | ";
		for (int j = ((tab[i])->sizeList()) - 1; j >= 0; --j) {
			cout << (tab[i])->getList(j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void showStopnieWierzcholkow (int maxVertex, List** &tab){
	for (int i = 0; i < maxVertex; ++i)
		cout << i + 1 << " | " << (tab[i])->sizeList() << endl;
}
