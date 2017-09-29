#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
	int m, n, h, step(0);
	char tok;
	cin >> m >> n >> h;
	vector<int> start(4, 0), temp(4, 0), end(3, 0), next;
	vector<vector<vector<int> > > labyrinth(h, vector<vector<int> >(m, vector<int>(n, 0)));
	deque<vector<int> > path;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++) {
				cin >> tok;
				if (tok == '1') {
					start[0] = i;
					start[1] = j;
					start[2] = k;
					start[3] = 0;
					path.push_back(start);
					labyrinth[i][j][k] = 1;
				}
				if (tok == 'o') {
					labyrinth[i][j][k] = 1;
				}
				if (tok == '2') {
					end[0] = i;
					end[1] = j;
					end[2] = k;
				}
			}
	while (!path.empty()) {
		temp = path.front();
		if (temp[0] == end[0] && temp[0] == end[0] && temp[0] == end[0]) {
			step = temp[3];
			break;
		}
		path.pop_front();
		if (temp[0] + 1 < h && labyrinth[temp[0] + 1][temp[1]][temp[2]] == 0) {
			next = temp;
			next[0] = temp[0] + 1;
			next[3] = temp[3] + 1;
			path.push_back(next);
			labyrinth[next[0]][next[1]][next[2]] = 1;
		}
		if (temp[1] + 1 < m && labyrinth[temp[0]][temp[1] + 1][temp[2]] == 0) {
			next = temp;
			next[1] = temp[1] + 1;
			next[3] = temp[3] + 1;
			path.push_back(next);
			labyrinth[next[0]][next[1]][next[2]] = 1;
		}
		if (temp[1] - 1 >= 0 && labyrinth[temp[0]][temp[1] - 1][temp[2]] == 0) {
			next = temp;
			next[1] = temp[1] - 1;
			next[3] = temp[3] + 1;
			path.push_back(next);
			labyrinth[next[0]][next[1]][next[2]] = 1;
		}
		if (temp[1] - 1 >= 0 && labyrinth[temp[0]][temp[1] - 1][temp[2]] == 0) {
			next = temp;
			next[1] = temp[1] - 1;
			next[3] = temp[3] + 1;
			path.push_back(next);
			labyrinth[next[0]][next[1]][next[2]] = 1;
		}
	}
	return step * 5;
}