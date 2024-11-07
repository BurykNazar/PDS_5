#include<iostream>
#include<Windows.h>
#include<vector>
#include<string>

using namespace std;

vector<string> getCartProd(const string set1[], size_t size1,
	const string set2[], size_t size2,
	const string set3[], size_t size3) {
	vector<string> rowsVector;

	for (size_t i = 0; i < size1; i++) {
		for (size_t j = 0; j < size2; j++) {
			for (size_t k = 0; k < size3; k++) {
				rowsVector.push_back(set1[i] + set2[j] + set3[k]);
			}
		}
	}
	return rowsVector;
}


void printProd(vector<string> cartesian) {
	for (size_t i = 0; i < cartesian.size(); i++) {
		cout << "Комбінація номер " << (i + 1) << ": {";
		for (size_t j = 0; j < cartesian[i].size(); j++) {
			cout << cartesian[i][j];
			if (j < 2)
				cout << ", ";
		}
		cout << "}" << endl;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string setA[]{ "a","b","c"};
	string setB[]{ "x","y","z" };
	string setC[]{ "0","1" };
	
	cout << "Множина A складається з елементів [";
	for (size_t i = 0; i < size(setA); i++) {
		cout << setA[i];
		if (i < size(setA) - 1) 
			cout << ", ";
	}
	cout << "]" << endl;
	cout << "Множина B складається з елементів [";
	for (size_t i = 0; i < size(setB); i++) {
		cout << setB[i];
		if (i < size(setB) - 1)
			cout << ", ";
	}
	cout << "]" << endl;
	cout << "Множина C складається з елементів [";
	for (size_t i = 0; i < size(setC); i++) {
		cout << setC[i];
		if (i < size(setC) - 1)
			cout << ", ";
	}
	cout << "]" << endl;
	vector<string> cartesian = getCartProd(setA, size(setA),
		setB, size(setB), setC, size(setC));
	cout << "Декартовий добуток AxBxC містить " << cartesian.size()
		<< " елементів." << endl;
	
	printProd(cartesian);
	return 0;
}