#include <bits/stdc++.h>
using namespace std;

void calcleftcost(vector<int> &dist, vector<int> &cost, vector<long long> &leftcost, int k) {
    // k denotes number of stalls to the left
    if (k == 0) return;
    int n = dist.size();
    priority_queue<int> pq;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int curcost = cost[i] + dist[0] - dist[i];
        if (pq.size() < k) {
            pq.push(curcost);
            sum += curcost;
            continue;
        }
        leftcost[i] = sum + k * 1LL * (dist[i] - dist[0]);
        pq.push(curcost);
        sum += curcost;
        sum -= pq.top();
        pq.pop();
    }
    // for (int i = 0; i < n; i++) {
    //     cout << leftcost[i] << " ";
    // }
    // cout << endl;
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
    vector<long long> leftcost(n), rightcost(n);
    int l = k / 2 + (k % 2 ? 1 : 0);
    int r = k / 2;
    assert(l + r == k);
    calcleftcost(dist, cost, leftcost, l);
    reverse(dist.begin(), dist.end());
    reverse(cost.begin(), cost.end());
    for (int i = 0; i < n; i++) {
        dist[i] *= -1;
    }
    calcleftcost(dist, cost, rightcost, r);
    // for (int i = 0; i < n; i++) {
    //     cout << leftcost[i] << "," << rightcost[n-i-1] << " ";
    // }
    // cout << endl;
    long long mincost = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (l <= i && r <= n - 1 - i) {
            mincost = min(mincost, leftcost[i] + cost[n - i- 1] + rightcost[n - 1 - i]);
        }
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