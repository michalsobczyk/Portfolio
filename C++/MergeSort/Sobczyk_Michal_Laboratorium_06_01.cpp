#include "functions.h"


using namespace std;

void openfile(string tekst);

int main()
{
	openfile("in.txt");

    return 0;
}


void openfile(string tekst) {

    ifstream in;
	in.open(tekst, std::ios::in);
	if (!in.good())
		exit(0);

    ofstream out;
	out.open("out.txt");

    int inversions;
	int cyfra, zestawy, iloscDanych;
	in >> zestawy;
	for (int i = 0; i < zestawy; i++){
        inversions = 0;
		in >> iloscDanych;
		int *T = new int[iloscDanych];
		for (int j = 0; j < iloscDanych; j++) {
			in >> cyfra;
			T[j] = cyfra;
        }
        inversions = sortScal(T, 0, iloscDanych - 1);
        out << inversions << endl;
    }
	in.close();
	out.close();
}
