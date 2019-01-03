#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector< pair<string, string> > v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    v[i].second += ';';
    // cout << v[i].first << v[i].second;
  }
  pair<string, string> p;
  for (int i = 0; i < m; i++) {
    cin >> p.first >> p.second;
    for (int j = 0; j < n; j++) {
      if (p.second == v[j].second) {
        cout << p.first << " " << p.second << " #" << v[j].first << endl;
        break;
      }
    }
  }
}
