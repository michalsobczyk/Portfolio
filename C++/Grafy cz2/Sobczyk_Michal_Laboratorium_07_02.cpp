#include "classfile.h"
#include "functions.h"


int main()
{
	ifstream in;
	in.open("edges.txt");
	int maxVertex = biggestVertex (in);
	int fromVertex;
	int toVertex;
	int numberOfEdges;


    List** tab = new List* [maxVertex];

	for (int i = 0; i < maxVertex; ++i) {
		tab[i] = new List;
	}

    addTab (in, tab);

    showIncidenceList (maxVertex, tab);
    showStopnieWierzcholkow(maxVertex, tab);


	cin.ignore();
	getchar();
	return 0;
}
