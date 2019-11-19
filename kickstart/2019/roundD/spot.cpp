#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v) {
    for (int i = 0; i< v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sherlock(int t) {
    int k, n;
    cin >> k >> n;
    vector<int> dist(n), cost(n);
    vector<pair<int,int>> distcost(n);
    for (int i = 0; i < n; i++) {
        cin >> dist[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < n; i++) {
        distcost[i] = {dist[i], cost[i]};
    }
    sort(distcost.begin(), distcost.end());
    for (int i = 0; i < n; i++) {
        dist[i] = distcost[i].first;
        cost[i] = distcost[i].second;
    }
    // print(dist);
    // print(cost);
    // initialise actual cost for warehouse at x0;
    vector<int> vis(n);
    vector<long long> rightcost(n), leftcost(n);
    set<pair<int,int>> rhs, lhs;
    for (int i = 1; i < n; i++) {
        rhs.insert({cost[i] + (dist[i] - dist[0]), i});
    }
    pair<int,int> p;
    int rc = k, lc = 0;
    for (int i = 0; i < k; i++) {
        p = *rhs.begin();
        vis[p.second] = 1;
        rightcost[0] += p.first;
        rhs.erase(rhs.begin());
    }
    // now shift the warehouse to one stop right
    for (int i = 1; i < n; i++) {
        // lhs size gives us used spots to the left
        rightcost[i] = rightcost[i-1] - rc * (dist[i] - dist[i-1]);
        int cur = rc - (vis[i] ? 1 : 0);
        if (vis[i]) { // cur location was a hotel, now new warehouse
            rightcost[i] -= cost[i];
            vis[i] = 0;
            rc--;
        }
        else {
            rhs.erase({cost[i] + (dist[i] - dist[0]), i});
        }
        lhs.insert({cost[i-1] + dist[0] - dist[i-1], i-1});
        // need to find new req spots from lhs and rhs
        int delta = dist[i] - dist[0];
        auto x = lhs.begin();
        while (cur < k) {
            if (!lhs.empty() && !rhs.empty()) {
                int lc = (*x).first + delta;
                int rc = (*rhs.begin()).first - delta;
                if (lc < rc) {
                    vis[(*x).second] = 1;
                    leftcost[i] += lc;
                    x++;
                }
                else {
                    vis[(*rhs.begin()).second] = 1;
                    rhs.erase(rhs.begin());
                    rightcost[i] += rc;
                }
            }
            else if (!lhs.empty()) {
                int lc = (*x).first + delta;
                vis[(*x).second] = 1;
                leftcost[i] += lc;
                x++;
            }
            else if (!rhs.empty()) {
                int rc = (*rhs.begin()).first - delta;
                vis[(*rhs.begin()).second] = 1;
                rhs.erase(rhs.begin());
                rightcost[i] += rc;
            }
            else {
                assert(false);
            }
            cur++;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << leftcost[i] << "," << rightcost[i] << " ";
    // }
    // cout << endl;
    long long mincost = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        mincost = min(mincost, rightcost[i] + cost[i] + leftcost[i]);
    }
    cout << "Case #" << t << ": " << mincost << endl;
}

int main() {
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        sherlock(t);
    }
}