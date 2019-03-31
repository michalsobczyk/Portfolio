#include "functions.h"

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

int **createMatrix (int n, int m){
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int [m];
    return matrix;
}

void createIncidenceMatrix(int** &matrix, ifstream &vertex){
    int edgeNumber, maxVertex;
    int fromVertex, toVertex;
    maxVertex = biggestVertex (vertex);
    vertex >> edgeNumber;
    for (int i = 0; i < edgeNumber; i++){
        vertex >> fromVertex;
        vertex >> toVertex;
        matrix[i][fromVertex - 1] = -1;
        matrix[i][toVertex - 1] = 1;
    }
}

void showMatrix (int** &matrix, int n, int m){
    cout << "    ";
    for (int j = 0; j < m; j++) cout << j + 1 << "   ";
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << i + 1 << " | ";
        for (int j = 0; j < m; j++){
            if (matrix[i][j] == -1) cout << matrix[i][j] << "  ";
            else cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

void zeroMatrix (int ** &matrix, int n, int m){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = 0;
}

void createNeighbourMatrix(int ** &matrix, ifstream &vertex){
    int fromVertex, toVertex;
    int edgeNumber;
    int maxVertex = biggestVertex(vertex);
    vertex >> edgeNumber;
    for (int i = 0; i < edgeNumber; i++){
        vertex >> fromVertex;
        vertex >> toVertex;
        matrix[fromVertex - 1][toVertex - 1] = -1;
        matrix[toVertex - 1][fromVertex - 1] = 1;
    }
}





void createIncidenceVector(vector <int> &tab, ifstream &vertex) {
    int edgeNumber, maxVertex;
    int fromNumber, toNumber;
    maxVertex = biggestVertex (vertex);
    vertex >> edgeNumber;
    for (int i = 0; i < edgeNumber; i++){
        vertex >> fromNumber;
        vertex >> toNumber;
        for (int j = 0; j < maxVertex; j++){
            if (fromNumber - 1 == j) tab.push_back(-1);
            else if (toNumber - 1 == j) tab.push_back(1);
            else tab.push_back(0);
        }
    }
}

void showIncidenceVector (vector <int> &tab, int edgeNumber, int maxVertex){
    cout << "    ";
    for (int j = 0; j < maxVertex; j++) cout << j + 1 << "   ";
    cout << endl;
    int counter = 0, lines = 1;
    cout << lines << " | ";
    for (int i = 0; i < edgeNumber*maxVertex; i++){
        counter++;
        if (tab[i] == -1) cout << tab[i] << "  ";
        else cout << tab[i] << "   ";
        if (counter == 5 && i != edgeNumber*maxVertex - 1) {
            counter = 0;
            cout << endl;
            cout << ++lines << " | ";
        }
    }
}

void createNeighbourVector(vector<vector <int>> &tab, ifstream &vertex) {
    int fromNumber, toNumber;
    int edgeNumber;
    int maxVertex = biggestVertex(vertex);
    vertex >> edgeNumber;
    while (!vertex.eof()){
        vertex >> fromNumber;
        vertex >> toNumber;
        tab[fromNumber - 1].push_back(toNumber);
    }
}

void showNeighbourVector (vector<vector <int>> &tab, int maxVertex){
    for (int i = 0; i < maxVertex; i++){
        cout << i + 1 << " | ";
        for(int j = 0; j < tab[i].size(); j++){
            cout << tab[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
