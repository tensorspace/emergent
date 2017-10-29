#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int check_chain(const string& s, unordered_map<string, int>& word_map) {
	int longest = 1;
	string short_string;
	int s_size = s.size();
		for (size_t i = 0; i<s_size; ++i) {
			short_string = s;
			short_string.erase(short_string.begin() + i);
				if (word_map.find(short_string) != word_map.end()) {
					longest = max(longest, word_map[short_string] + 1);
				}
		}
			return longest;
}

int lc_dp(vector<string>& words) {
	if (words.empty())
		return 0;

		int n = words.size();

		vector<pair<int, string>> s_sorted;
	for (string& s : words) {
		sort(s.begin(), s.end());
		s_sorted.push_back({ s.size(),s });
	}
		sort(s_sorted.begin(), s_sorted.end());

	unordered_map<string, int> word_map;
	word_map.insert({ s_sorted[0].second,1 });

	vector<int> chain_len(n, 1);
	int longest = 1;

	for (size_t i = 0; i<n; ++i) {
		string s = s_sorted[i].second;
		int cl = check_chain(s, word_map);
		chain_len[i] = cl;
		longest = max(longest, cl);
		word_map.insert({ s,cl });
	}

	return longest;
}


int main() {
	// vector<string> words{"b","ba","bca","bdca","ebdca"};
	// vector<string> w2{"b","ba","bca","bdca","ebdca","b"};
	vector<string> w3{ "4","9","a","b","bca","ba","bde","bda","bdcae","bdca","abcde" };

	// cout<<lc_dp(words)<<endl;
	// cout<<lc_dp(w2)<<endl;
	cout << lc_dp(w3) << endl;

		return 0;
}