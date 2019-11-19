#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k, l, r;
	cin >> n >> k;
	int rm = INT_MIN;
	vector<tuple<int,int,int>> seg(n);
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		seg[i] = {l, r, i + 1};
		rm = max(rm, r);
	}
	sort(seg.begin(), seg.end());
	multiset<pair<int,int>, greater<pair<int,int>>> maxh;
	multiset<pair<int,int>> minh; 
	int ov = 0, ans = 0;
	l = 0;
	vector<int> v;
	for (int i = 1; i <= rm; i++) {
		// 1. Remove exhausted r's, 2. Add new seg's, 3. Remove greedily
		while (!minh.empty() && minh.begin()->first < i) {
			maxh.erase(maxh.find(*minh.begin()));
			minh.erase(minh.begin());
			ov--;
		}
		while (l < n && get<0>(seg[l]) == i) {
			minh.insert({get<1>(seg[l]), get<2>(seg[l])});
			maxh.insert({get<1>(seg[l]), get<2>(seg[l])});
			ov++;
			l++;
		}
		while (ov > k) {
			v.push_back(maxh.begin()->second);
			minh.erase(minh.find(*maxh.begin()));
			maxh.erase(maxh.begin());
			ov--;
			ans++;
		}
		// cout << i << "," << ov << " ";
	}
	cout << ans << endl;
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
	return 0;
}