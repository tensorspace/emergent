#include<map>
#include<iostream>
using namespace std;

void main() {
	map<int, bool> mp;
	map<int, bool>::iterator it;
	int n, m, start, end, sum(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> m;
		mp[m] = true;
	}
	start = mp.begin()->first;
	end = start;
	for (it = ++mp.begin(); it != mp.end(); ++it) {
		if (it->first == end + 1) end = it->first;
		else {
			if ((start - end) % 2 != 0) sum += (start + end + 1) * ((end - start - 1) / 2 + 1) / 2;
			else sum += (start + end) * ((end - start) / 2 + 1) / 2;
			start = it->first;
			end = start;
		}
	}
	if ((start - end) % 2 != 0) sum += (start + end + 1) * ((end - start - 1) / 2 + 1) / 2;
	else sum += (start + end) * ((end - start) / 2 + 1) / 2;
	cout << sum;
}