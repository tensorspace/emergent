#include<vector>
#include<map>
#include<iostream>
using namespace std;
int dist(int r, int g, int b, int x, int y, int z) {
	return (r - x) * (r - x) + (g - y) * (g - y) + (b - z) * (b - z);
}
void main() {
	vector<string> result, pixels;
	result.insert(result.end(), "White");
	pixels.insert(pixels.end(), "000000001111111111111111");
	for (int i = 0; i < pixels.size(); i++) {
		int r(0), g(0), b(0);
		map<int, int> mp;
		for (int j = 0; j < 8; j++)
			if (pixels[i][j] == '1') r += 1 << 7 - j;
		for (int j = 8; j < 16; j++)
			if (pixels[i][j] == '1') g += 1 << 15 - j;
		for (int j = 16; j < 24; j++)
			if (pixels[i][j] == '1') b += 1 << 23 - j;
		mp[dist(r, g, b, 0, 0, 0)] = 0;
		mp[dist(r, g, b, 255, 255, 255)] = 1;
		mp[dist(r, g, b, 255, 0, 0)] = 2;
		mp[dist(r, g, b, 0, 255, 0)] = 3;
		mp[dist(r, g, b, 0, 0, 255)] = 4;
		if (mp.size() != 5) result.insert(result.end(), "Ambiguous");
		else {
			map<int, int>::iterator it(mp.begin());
			if (it->second == 0) result.insert(result.end(), "Black");
			if (it->second == 1) result.insert(result.end(), "White");
			if (it->second == 2) result.insert(result.end(), "Red");
			if (it->second == 3) result.insert(result.end(), "Green");
			if (it->second == 4) result.insert(result.end(), "Blue");
		}
	}
}