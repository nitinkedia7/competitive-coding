#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int MAXN = 1e6 + 2;

struct BIT{
	int bit[MAXN+10]={0},n;
	int sum(int i){
		int s=0;
		while(i>0){
			s+=bit[i];
			i-=i &(-i);
		}
		return s;
	}
	int query(int l,int r){
		return sum(r)-sum(l-1);
	}
	void add(int i,int x=1){
		while(i<=n){
			bit[i]+=x;
			i+= i&(-i);	
		}
	}
};

void sherlock(int t) {
    BIT b = *new BIT();
    int n, q;
    cin >> n >> q;
    b.n = n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        b.add(x, 1);
    }
    for (int i = 0; i < q; i++) {
        cin >> x;
        if (x >= 1) {
            b.add(x, 1);
        }
        else if (x < 0) {
            x *= -1;
            int l = 1, r = n, mid;
            while (l <= r) {
                mid = (l + r) / 2;
                if (b.query(1, mid) < x) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            b.add(l, -1);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (b.query(i, i)) {
            cout << i << " ";
            // return;
        }
    }
    cout << endl;
    cout << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
