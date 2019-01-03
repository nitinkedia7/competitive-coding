#include <bits/stdc++.h>
using namespace std;

bool diff(int m, int *array, int *s, int *e, int iter) {
  int flag = iter;
  for (int i = 0; i < m; i++) {
    if (array[i] == 1) {
      if (flag == iter) {
          *s = i;
          *e = i;
      }
      else if (flag == iter+1) {
        *e = i;
      }
      flag++;
    }
  }
  if (flag <= iter) return false;
  else return true;
}

int ans(int n, int m, int **array) {
  int flag = 0;
  int min = 0;
  for (int j = 0; j < n; j++) {
    int s = 0, e = 0;
    for (int i = 0; i < m; i++) {
      if (array[j][i] == 1) {
        e = i;
        if (flag == 0) {
            s = i;
            e = i;
        }
        flag++;
      }
    }
    min += (e-s+1);
  }
  return min;
}

int ideal(int n, int m, int **array) {
  bool valid[n];
  int count = n;
  int iter = 0;
  while (count > 1) {
    int max = -1, count = 0;
    for (int i = 0; i < n; i++) {
      int s, e;
      if (diff(m, array[i], &s, &e, iter) == true) {
        if (e-s > max) max = e-s;
      }
    }
    for (int i = 0; i < n; i++) {
      int s, e;
      if (diff(m, array[i], &s, &e, iter) == true) {
        if (e-s == max) {
          valid[i] = true;
          count++;
        }
        else valid[i] = false;
      }
      valid[i] = false;
    }
  iter++;
  }
  for (int i = 0; i < n; i++) {
    if (valid[i] == true) return i;
  }
  return -1;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int **array = new int*[n];
  for (int i = 0; i < n; i++) {
    array[i] = new int[m];
  }
//int array[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> array[i][j];
    }
  }
  for (int i = 0; i < k; i++) {
    int spl = ideal(n, m, array);
    if (spl != -1) {
      int s, e;
      if (diff(m, array[spl], &s, &e, 0)) {
        array[spl][s] = 0;
      }
    }
    else break;
  }
  cout << ans(n, m, array) << endl;
}
