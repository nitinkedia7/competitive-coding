#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  int array[n];
  for (int i = 0; i < n; i++) cin >> array[i];
  sort(array, array+n);

  vector<int> v;
  int running = array[0];
  v.push_back(1);
  for (int i = 1; i < n; i++) {
    if (running == array[i]) {
      v[v.size()-1]++;
    }
    else {
      running = array[i];
      v.push_back(1);
    }
  }
  // for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  for (int i = v.size()-1; i >=0; i--) {
    if (v[i]%2 == 1) {
      cout << "Conan" << endl;
      return 0;
    }
  }
  cout << "Agasa" << endl;
}
