#include <vector>
#include <string>
using namespace std;

void main() {
	vector<int> units = { 600, 60, 10, 1 };
	string time = "19:34", result;
	int current_time = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
	string next_time = "0000";
	for (int i = 1; i <= 1440; i++) {
		int trial = (current_time + i) % 1440;
		for (int j = 0; j < 4; j++) {
			next_time[j] = '0' + trial / units[j];
			trial %= units[j];
			if (time.find(next_time[j]) == string::npos) break;
		}
		result = next_time.substr(0, 2) + ':' + next_time.substr(2, 2);
	}
}