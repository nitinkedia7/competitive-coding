#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int makesum(vector<int> &v, int s, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[s+i];
    }
    return sum;
}
int makesum1(vector<pair<int,int>> &v, int s, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[s+i].first;
    }
    return sum;
}


int main() {
    int t, n;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n;
        int N = 3*n;
        vector<int> bahu(N);
        for (int i = 0; i < N; i++) cin >> bahu[i];
        vector<pair<int,int>> bala(N);
        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            bala[i] = make_pair(temp, i);
        }

        sort(bahu.begin(), bahu.end());
        // for (int i = 0; i < N; i++) cout << bahu[i] << " ";
        // cout << endl;
        int sum = makesum(bahu, n, 2*n);
        int a = 0;
        // cout << a << ", " << sum << endl;
        do {
            // cout << "bahu" << endl;
            int l = makesum(bahu, n, n);
            int r = sum-l;
            if (abs(l-r) < abs(2*a-sum)) a = l;
        } while (next_permutation(bahu.begin()+n, bahu.end()));
        // cout << a << ", " << sum-a << endl;
        sort(bala.begin(), bala.end());
        int win = 0, total = 0;
        do {
            // cout << "bala" << endl;
            int l = makesum1(bala, 0, n);
            int r = makesum1(bala, n, n);
            if (a > l && sum-a > r) win++;
            total++;
        } while (next_permutation(bala.begin(), bala.end()));
        // cout << win << ", " << total << endl;
        long double p = 1.0;
        p = (win*p)/total;
        cout << "Case #" << c << ": ";
        printf("%.10Lf", p);
        cout << endl;
    }
}