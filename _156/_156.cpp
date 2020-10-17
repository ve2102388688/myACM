#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
	vector<string> allWords;
	multiset<string> lowerCase;

	string line;
	while (cin >> line, line!="#") {
		allWords.push_back(line);

		transform(line.begin(), line.end(), line.begin(), ::tolower);
		sort(line.begin(), line.end());
		lowerCase.insert(line);
	}

	vector<string> ananagrams;
	for (size_t i = 0; i < allWords.size(); i++) {
		string word = allWords[i];
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		sort(word.begin(), word.end());

		if (lowerCase.count(word) == 1)
			ananagrams.push_back(allWords[i]);
	}

	sort(ananagrams.begin(), ananagrams.end());
	for(const auto& e: ananagrams){
		cout << e << "\n";
	}

	return 0;
}

