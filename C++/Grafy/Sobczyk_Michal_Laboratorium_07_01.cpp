#include "functions.h"

int main()
{
    int edgeNumber;
    ifstream in;
    in.open ("edges.txt");
    in >> edgeNumber;
    int maxVertex = biggestVertex(in);
    int **tab = createMatrix (edgeNumber, maxVertex);
    zeroMatrix(tab, edgeNumber, maxVertex);
    createIncidenceMatrix(tab, in);
    showMatrix(tab, edgeNumber, maxVertex);
    zeroMatrix(tab, edgeNumber, maxVertex);
    createNeighbourMatrix(tab, in);
    showMatrix(tab, maxVertex, maxVertex);
    cout << "2 czesc zadania" << endl << endl << endl;
    in.seekg(0);
    vector <int> vect;
    vector<vector <int>> vectN (maxVertex);
    createIncidenceVector(vect, in);
    showIncidenceVector(vect, edgeNumber, maxVertex);
    createNeighbourVector(vectN, in);
    cout << endl;
    cout << endl;
    showNeighbourVector(vectN, maxVertex);
    in.close();
    return 0;
}
