#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<Windows.h>

using namespace std;

const size_t N = 8;
const string setUni[]{ "1", "2", "3", "4", "5", "6", "7", "8" };

vector<string> getComplement(const string set1[]) {
	vector<string> complement;
	for (size_t i = 0; i < N; i++)
		if (set1[i] != setUni[i])
			complement.push_back(setUni[i]);
	return complement;
}

vector<string> getIntersection(const string set1[],
	const string set2[]) {
	vector<string> intersection;
	for (size_t i = 0; i < N; i++) {
		if (set1[i] != "-" && set2[i] != "-" && set1[i] == set2[i])
			intersection.push_back(set1[i]);
	}
	return intersection;
}

vector<string> getUnion(const string set1[],
	const string set2[]) {
	set<string> setsUnion;
	for (size_t i = 0; i < N; i++) {
		if (set1[i] != "-")
			setsUnion.insert(set1[i]);
		if (set2[i] != "-")
			setsUnion.insert(set2[i]);
	}
	return vector<string>(setsUnion.begin(), setsUnion.end());
}

vector<string> getSymmDiff(const string set1[],
	const string set2[]) {
	vector<string> symmDiff;
	for (size_t i = 0; i < N; i++) {
		bool found = false;
		if (set1[i] != "-") {
			for (size_t j = 0; j < N; j++)
				if (set1[i] == set2[j]) {
					found = true;
					break;
				}
			if (!found)
				symmDiff.push_back(set1[i]);
		}
	}

	for (size_t j = 0; j < N; j++) {
		bool found = false;
		if (set2[j] != "-") {
			for (size_t i = 0; i < N; i++)
				if (set2[j] == set1[i]) {
					found = true;
					break;
				}
			if (!found)
				symmDiff.push_back(set2[j]);
		}
	}
	return symmDiff;
}

vector<string> getDifference(const string set1[],
	const string set2[]) {
	vector<string> difference;
	for (size_t i = N; i < N; i++) {
		bool found = false;
		for(size_t j = 0; j < N; j++)
			if (set1[i] == set2[j]) {
				found = true;
				break;
			}
		if (!found && set1[i] != "-")
			difference.push_back(set1[i]);
	}
	return difference;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string setA[]{ "1", "2", "3", "-", "-","-","-","-" };
	string setB[]{ "1", "2", "3", "4", "5", "-",  "-", "-" };

	cout << "Універсум є " << N << "-елементним." << endl;
	cout << "Множина універсуму: [";
	
	for (size_t i = 0; i < N; i++) {
		cout << setUni[i];
		if (i < N - 1)
			cout << ", ";
	}
	cout << "]" << endl;

	cout << "Підмножина універсуму A: [";
	for (size_t i = 0; i < N; i++) {
		cout << setA[i];
		if (i < N - 1)
			cout << ", ";
	}
	cout << "]" << endl;

	cout << "Підмножина універсуму B: [";
	for (size_t i = 0; i < N; i++) {
		cout << setB[i];
		if (i < N - 1)
			cout << ", ";
	}
	cout << "]" << endl;

	vector<string> complement = getComplement(setA);
	cout << "Доповнення підмножини A: {";
	for (size_t i = 0; i < complement.size(); i++) {
		cout << complement[i];
		if (i < complement.size() - 1)
			cout << ", ";
	}
	cout << "}" << endl;

	vector<string> intersection = getIntersection(setA, setB);
	cout << "Перетин підмножини A з підмножиною B : {";
	for (size_t i = 0; i < intersection.size(); i++) {
		cout << intersection[i];
		if (i < intersection.size() - 1)
			cout << ", ";
	}
	cout << "}" << endl;

	vector<string> setsUnion = getUnion(setA, setB);
	cout << "Об'єднання підмножини A з підмножиною B : {";
	for (size_t i = 0; i < setsUnion.size(); i++) {
		cout << setsUnion[i];
		if (i < setsUnion.size() - 1)
			cout << ", ";
	}
	cout << "}" << endl;

	vector<string> diff = getDifference(setA, setB);
	cout << "Різниця підмножини A з підмножиною B : {";
	for (size_t i = 0; i < diff.size(); i++) {
		cout << diff[i];
		if (i < diff.size() - 1)
			cout << ", ";
	}
	cout << "}" << endl;

	vector<string> symmdiff = getSymmDiff(setA, setB);
	cout << "Симетрична різниця підмножини A з підмножиною B : {";
	for (size_t i = 0; i < symmdiff.size(); i++) {
		cout << symmdiff[i];
		if (i < symmdiff.size() - 1)
			cout << ", ";
	}
	cout << "}" << endl;
	return 0;
}