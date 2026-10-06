#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() 
{
	string text((istreambuf_iterator<char>(cin)),
		istreambuf_iterator<char>());

	unordered_map<char, int> freq;
	for (char ch : text) {
		if (ch != '\n') { 
			freq[ch]++;
		}
	}

	vector<pair<char, int>> items;
	for (auto p : freq) {
		items.push_back(p);
	}

	sort(items.begin(), items.end(), [](auto a, auto b) {
		if (a.second != b.second) {
			return a.second > b.second; 
		}
		return a.first < b.first; 
		});

	for (auto p : items) {
		cout << p.first << ": " << p.second << endl;
	}
	return 0;
}
