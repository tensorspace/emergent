#include <vector>
using namespace std;

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		vector<int> visited(M.size(), 0);
		int count(0);
		for (int i = 0; i < M.size(); i++)
			if (visited[i] == 0) {
				dfs(M, visited, i);
				count++;
			}
		return count;
	}
private:
	void dfs(vector<vector<int>>& M, vector<int> visited, int i) {
		for (int j = 0; j < M.size(); j++) {
			if (M[i][j] == 1 && visited[j] == 0) {
				visited[j] = 1;
				dfs(M, visited, j);
			}
		}
	}
};

void main() {
	Solution sln;
	vector<vector<int>> M = { {1, 1, 0},{1, 1, 0},{0, 0, 1} };
	sln.findCircleNum(M);
}