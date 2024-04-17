#include<iostream>
using namespace std;
bool isIcecreamSandwich(string word) {
	bool isSandwich(0), symbolChanged(0);
	int startEdgeSize(1), endEdgeSize(0), iceCreamSize(word.size());
	char edgesFill;
	isSandwich = ((edgesFill = word[0]) && (iceCreamSize >= 3) && (word[0] == word[iceCreamSize - 1]));
	if (isSandwich) {
		for (int i = startEdgeSize; i < iceCreamSize; i++) {
			if (edgesFill == word[i]) {
				(symbolChanged) ? endEdgeSize++ : startEdgeSize++;
			}
			else if (word[i - 1] != word[i]) {
				if (symbolChanged) return false;
				symbolChanged = true;
			}
		}
		isSandwich = endEdgeSize == startEdgeSize;
	}
	return isSandwich;
}
int main() {
	string word;
	cin >> word;
	cout << "isIcecreamSandwich( " << word << " ) --> " << (isIcecreamSandwich(word) ? "true" : "false");
}