#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<int> &v, int left, int right) { // [left, right]
	if (left >= right) return;
	int p = (left + right) / 2;

	// partition using a pivot
	swap(v[p], v[right]);
	int i = l - 1;
	for (int j = left; j < right; j++) {
		if (v[j] <= v[right] {
			i++;			
			swap(v[i], v[j]);		
		}
	}
	i++;		
	swap(v[i], v[right]);
	p = i;
	// recursively sort the two partitons
	quicksort(v, left, p - 1);
	quicksort(v, p + 1, right);	 
	return;
}

int main() {
	// call qsort
	return 0;
}
