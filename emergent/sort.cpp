#include <vector>
#include <algorithm>
using namespace std;
int partition(vector<int> arr, int low, int high) {
	int pivot(arr[high]), i(low - 1);
	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;
			iter_swap(&arr[i], &arr[j]);
		}
	}
	iter_swap(&arr[i + 1], &arr[high]);
	return i + 1;
}
void quickSort(vector<int> arr, int low, int high) {
	if (low < high) {
		int pi(partition(arr, low, high));
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}