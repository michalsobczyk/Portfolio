#include "functions.h"

int main() {

	int **A = nullptr;
	int n, m, z = 0;
	cin >> z;
	if (z < 0)
		cout << "!negative number" << endl;
	else
		for (z; z > 0; z--) {
			cin >> n >> m;
			A = f_createtable(n, m);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					cin >> A[i][j];
			}
			int wynik = sum_table2(A, n, m);
			cout << wynik << endl;
		}
	system("PAUSE");
	return 0;
}
