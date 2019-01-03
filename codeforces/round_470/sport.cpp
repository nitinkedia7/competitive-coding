#include <iostream>
#include <vector>
using namespace std;

int greatest_prime(int x2, vector<int> prime) {
  int i = prime.size()-1;
  int p = 0;
  while (1) {
    if (x2 % prime[i] == 0) {
      p = prime[i];
      break;
    }
    i--;
    if (i < 0) break;
  }
  return p;
}

int main() {
  int x2;
  cin >> x2;

  int array[x2+1];
  vector<int> prime;
  for (int i = 0; i <= x2; i++) array[i] = 1;
  array[0] = 0;
  array[1] = 0;
  for (int i = 0; i <= x2; i++) {
    if (array[i]) {
      int num = 2*i;
      prime.push_back(i);
      while (num <= x2) {
        array[num] = 0;
        num += i;
      }
    }
  }
  // for (int i = 0; i <= x2; i++) cout << array[i] << " ";
  // cout << endl;
  // for (int i = 0; i < prime.size(); i++) cout << prime[i] << " ";
  // cout << endl;
  int p = greatest_prime(x2, prime);
  // cout << p << endl;
  int x0 = x2+1;
  for (int j = x2-p+1; j <= x2; j++) {
    int p1 = greatest_prime(j, prime);
    // cout << p1 << endl;
    if (p1 < j) {
      if (x0 > j-p1+1) x0 = j-p1+1;
    }
  }
  cout << x0 << endl;
}
