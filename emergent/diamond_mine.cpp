#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool isValid(int step, int x1, int x2, int n) { //check if the current state is valie
	int y1 = step - x1, y2 = step - x2;
	return ((x1 >= 0) && (x1 < n) && (x2 >= 0) && (x2 < n) && (y1 >= 0) && (y1 < n) && (y2 >= 0) && (y2 < n));
}

int getValue(int step, int x1, int x2, int n, vector<vector<vector<int>>> &dp) {  //assign minus infinity to non-existing location
	return isValid(step, x1, x2, n) ? dp[step % 2][x1][x2] : (-999999);
}

void main() {
	int n, x, y;
	cin >> n >> n;
	vector<vector<int>> mine(n, vector<int>(n, 0));
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n, 0)));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> mine[i][j];
			if (mine[i][j] < 0) mine[i][j] = -999999;
		}

	int P(n * 2 - 2); //the total steps
	int i, j, step, s;

	//set unaccessible location minus infinity
	for (i = 0; i < n; ++i)
		for (j = i; j < n; ++j)
			dp[0][i][j] = -999999;

	dp[0][0][0] = mine[0][0];

	for (step = 1; step <= P; ++step)
		for (i = 0; i < n; ++i)
			for (j = i; j < n; ++j) {
				dp[step % 2][i][j] = -999999;
				if (!isValid(step, i, j, n)) continue; //invalid location
				s = step % 2;
				if (i != j) {//dp for valid locations
					dp[s][i][j] = max(dp[s][i][j], getValue(step - 1, i - 1, j - 1, n, dp));
					dp[s][i][j] = max(dp[s][i][j], getValue(step - 1, i - 1, j, n, dp));
					dp[s][i][j] = max(dp[s][i][j], getValue(step - 1, i, j - 1, n, dp));
					dp[s][i][j] = max(dp[s][i][j], getValue(step - 1, i, j, n, dp));
					dp[s][i][j] += mine[i][step - i] + mine[j][step - j];  //if the two path are in different locations, pick both diamond
				}
				else {
					dp[s][i][j] = max(dp[s][i][j], getValue(step - 1, i - 1, j - 1, n, dp));
					dp[s][i][j] = max(dp[s][i][j], getValue(step - 1, i - 1, j, n, dp));
					dp[s][i][j] = max(dp[s][i][j], getValue(step - 1, i, j, n, dp));
					dp[s][i][j] += mine[i][step - i]; // if the two path are in the same location, pick diamond once
				}
			}
	cout << dp[P % 2][n - 1][n - 1];
}