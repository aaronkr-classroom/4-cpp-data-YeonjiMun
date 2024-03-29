//chp3ex3.cpp
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout; using std::cin;
using std::endl; using std::vector;
using std::string; using std::streamsize;

int main() {
	cout << "Enter all words  followed EOF:" << endl;
	vector<string> words;

	string word;

	while (cin >> word) {
		words.push_back(word);
	}
	//결과를 출력
	cout << "Words: " << words.size();

	return 0;
}