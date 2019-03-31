#include "functions.h"
#include "tree.h"

using namespace std;

int main(){
    addTree(2, 20, root);
    addTree(5, 30, root);
    addTree(7, 35, root);
    addTree(3, 12, root);
    addTree(1, 3, root);
    int maxProfit = 0, maxWeight = 0;
	ofstream out;
	out.open("out.txt");
	backtrackingBackpack(root->leftN, maxProfit, 0, 0, maxWeight, out);
	backtrackingBackpack(root->rightN, maxProfit, 0, 0, maxWeight, out);
	cout << maxProfit;
	out.close();
    return 0;
}
