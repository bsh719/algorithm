#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int i, int j) {
	int n1, n2;
	if (X[i] >= 0 && Y[i] >= 0) n1 = 1;
	else if (X[i] <= 0 && Y[i] >= 0) n1 = 4;
	else if (X[i] <= 0 && Y[i] <= 0) n1 = 3;
	else n1 = 2;

	if (X[j] >= 0 && Y[j] >= 0) n2 = 1;
	else if (X[j] <= 0 && Y[j] >= 0) n2 = 4;
	else if (X[j] <= 0 && Y[j] <= 0) n2 = 3;
	else n2 = 2;

	if (n1 != n2) return n1 < n2;

	return Y[i] * X[j] > Y[j] * X[i];
}
