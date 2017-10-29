#include <vector>
#include <queue>
using namespace std;

class SolutionFriend {
public:
	int findCircleNum(vector<vector<int>>& M) {
		return solution_dfs(M);
	}

	int solution_bfs(vector<vector<int>>& M) {
		int n = M.size(), res = 0;
		deque<bool> visited(n, false);
		queue<int> q;

		for (size_t i = 0; i<n; ++i) {
			if (visited[i])
				continue;
			q.push(i);
			while (!q.empty()) {
					int t = q.front();
				q.pop();
				visited[t] = true;
					for (size_t j = 0; j<n; ++j) {
						if (M[t][j] == 0 || visited[j])
							continue;
						q.push(j); 
					}
			}
			++res;
		}
		return res;
	}

	int solution_dfs(vector<vector<int>>& M) {
		int n = M.size(), res = 0;
		deque<bool> visited(n, false);

		for (size_t i = 0; i<n; ++i) {
			if (visited[i])
				continue;
			dfs(M, i, visited);
			++res;
		}
		return res;
	}

	void dfs(const vector<vector<int>>& M, int pos, deque<bool>& visited) {
		visited[pos] = true;
			for (size_t i = 0; i<M.size(); ++i) {
				if (M[pos][i] == 0 || visited[i])
					continue;
				dfs(M, i, visited);
			}
	}
};