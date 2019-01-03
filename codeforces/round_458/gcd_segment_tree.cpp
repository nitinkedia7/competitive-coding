#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
  if (a < b) return gcd(b,a);
  int temp;
  while (b > 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

int make_segtree(int *segtree, int size, int *array, int s, int e, int i) {
  if (s <= e) {
    if (s == e) {
      segtree[i] = array[s];
    }
    else {
      int m = (s+e)/2;
      if (2*i+2 < size) {
        segtree[i] = gcd(make_segtree(segtree, size, array, s, m, 2*i+1), make_segtree(segtree, size, array, m+1, e, 2*i+2));
      }
    }
    return segtree[i];
  }
}

int update_segtree(int *segtree, int size, int s, int e, int l, int i, int x) {
  if (i < size) {
    if (s == l and e == l) {
      segtree[i] = x;
    }
    else if (s <= l && l <= e) {
      int mid = (s+e)/2;
      if (2*i+2 < size) segtree[i] = gcd(update_segtree(segtree, size, s, mid, l, 2*i+1, x), update_segtree(segtree, size, mid+1, e, l, 2*i+2, x));
    }
    return segtree[i];
  }
}

// int check(int *segtree, int size, int s, int e, int l, int r, int i, int x) {
//   if (i < size) {
//     if (l <= s && e <= r) {
//       if (segtree[i] % x != 0) {
//           if (s == e) return 1;
//           int mid = (s+e)/2;
//           if (segtree[2*i+1] % x != 0 && segtree[2*i+2] % x != 0) return 2;
//           else if (segtree[2*i+1] % x != 0) {
//             int r1 = check(segtree, size, s, mid, l, r, 2*i+1, x);
//             return r1;
//           }
//           else if (segtree[2*i+2] % x != 0) {
//             int r2 = check(segtree, size, mid+1, e, l, r, 2*i+2, x);
//             return r2;
//           }
//       }
//     }
//     else if (e < l || r < s);
//     else{
//       int mid = (s+e)/2;
//       int r1 = check(segtree, size, s, mid, l, r, 2*i+1, x);
//       if (r1 > 1) return r1;
//       int r2 = check(segtree, size, mid+1, e, l, r, 2*i+2, x);
//       if (r2 > 1) return r2;
//       return r1+r2;
//     }
//     return 0;
//   }
// }

void check_helper(int *segtree, int size, int s, int e, int l, int r, int i, int x, int *flag, int *index, int *start, int *end, int *low, int *high) {
    if (l <= s && e <= r) {
      if (segtree[i] % x != 0) {
        if (*flag == 0) {
          *index = i;
          *start = s;
          *end = e;
          *low = l;
          *high = r;
        }
        (*flag)++;
      }
    }
    else if (e < l || r < s);
    else  {
      int mid = (s+e)/2;
      check_helper(segtree, size, s, mid, l, r, 2*i+1, x, flag, index, start, end, low, high);
      check_helper(segtree, size, mid+1, e, l, r, 2*i+2, x, flag, index, start, end, low, high);
    }
}
void check(int *segtree, int size, int s, int e, int l, int r, int i, int x) {
  if (i < size && s <= e && l <= r) {
    int flag = 0, index = -1, start = -1, end = -1, low = -1, high = -1;
    check_helper(segtree, size, s, e, l, r, 0, x, &flag, &index, &start, &end, &low, &high);
    if (flag > 1) cout << "NO" << endl;
    else if (flag == 1) check(segtree, size, start, end, low, high, index, x);
    else cout << "YES" << endl;
  }
}

int main() {
  int n;
  cin >> n;
  int array[n];
  for (int i = 0; i < n; i++) cin >> array[i];

  int size = 2*pow(2, ceil(log2(n)))-1;
  int segtree[size];
  make_segtree(segtree, size, array, 0, n-1, 0);
  // cout << "Segtree: ";
  // for (int i = 0; i < size; i++) cout << segtree[i] << " ";
  // cout << endl;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int type, l, r, x;
    cin >> type;
    if (type == 1) {
      cin >> l >> r >> x;
      check(segtree, size, 0, n-1, l-1, r-1, 0, x);
    }
    else {
      cin >> l >> x;
      update_segtree(segtree, size, 0, n-1, l-1, 0, x);
    }
  }
}
