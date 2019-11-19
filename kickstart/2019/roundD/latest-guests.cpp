#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void printp(vector<pair<int,int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << "," << v[i].second << " ";
    }
    cout << endl;
}

vector<pair<int,int>> prodir(int n, int g, int m, vector<int> &start, vector<char> &type, vector<int> &gtc) {
    // group size for each consulate, map from guest to last consulate
    vector<int> groupsize(n);
    for (int i = 0; i < g; i++) {
        if (type[i] == 'A') continue;
        int lastconsu = (start[i] + m) % n;
        groupsize[lastconsu]++;
        gtc[i] = lastconsu;   
    }
    if (*max_element(groupsize.begin(), groupsize.end()) == 0) {
        vector<pair<int,int>> lastvisit(n, {-1, -1});
        return lastvisit;
    }
    print(groupsize);
    print(gtc);
    vector<pair<int,int>> lastvisit(n);
    // iterate on consulates
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (groupsize[j] == 0) {
            j = (j + 1) % n;
        }
        cout << i << "," << j << " ";
        int dist = j <= i ? i - j : n - (i - j);
        if (m - dist > 0) {
            lastvisit[i] = {j, m - dist};
        }
        else if (m -dist == 0) {
            lastvisit[i] = {j, m};
        }
        else {  
            lastvisit[i] = {-1, m - dist};
        }
    }
    cout << endl;
    printp(lastvisit);
    // lastvisit: for each hotel store the group id which visited it last and that timestamp
    return lastvisit;
}

vector<pair<int,int>> antidir(int n, int g, int m, vector<int> &start, vector<char> &type, vector<int> &gtc) {
    vector<int> groupsize(n);
    int pm = -1 * m;
    int pn = n;
    while (pm < 0) {
        pm += pn;
        pn *= 2;
    }
    for (int i = 0; i < g; i++) {
        if (type[i] == 'C') continue;
        int lastconsu = (start[i] + pm) % n;
        groupsize[lastconsu]++;
        gtc[i] = lastconsu;
    }
    if (*max_element(groupsize.begin(), groupsize.end()) == 0) {
        vector<pair<int,int>> lastvisit(n, {-1, -1});
        return lastvisit;
    }
    cout << endl;
    print(groupsize);
    print(gtc);
    vector<pair<int,int>> lastvisit(n);
    int j = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        // if (j > i) {
        //     j--;
        // }
        while (groupsize[j] == 0) {
            j = (j - 1 + n) % n;
        }
        cout << i << "," << j << " ";
        int dist = j >= i ? j - i : n - (i - j);
        if (m - dist > 0) {
            lastvisit[i] = {j, dist};
        } 
        else if (m - dist == 0) {
            lastvisit[i] = {j, m};
        }
        else {
            lastvisit[i] = {-1, dist};
        }
    }
    cout << endl;
    printp(lastvisit);
    return lastvisit;
}

void sherlock(int t) {
    int n, g, m;
    cin >> n >> g >> m;
    vector<int> start;
    vector<char> type;
    int h;
    char dir;
    for (int i = 0; i < g; i++) {
        cin >> h >> dir;
        assert(dir == 'C' || dir == 'A');
        start.push_back(h - 1);
        type.push_back(dir);
    }

    vector<pair<int,int>> prolast, antilast;
    vector<int> gtc(g);
    prolast = prodir(n, g, m, start, type, gtc);
    antilast = antidir(n, g, m, start, type, gtc);
    vector<int> group1(n), group2(n);
    for (int i = 0; i < n; i++) {
        // for each hotel
        int gid1 = prolast[i].first;
        int gid2 = antilast[i].first;
        if (gid1 == -1 && gid2 == -1) {
            continue;
        }
        else if (gid1 == -1) {
            group2[gid2]++;
        }
        else if (gid2 == -1) {
            group1[gid1]++;
        }
        else {
            int t1 = prolast[i].second;
            int t2 = antilast[i].second;
            if (t1 < t2) {
                group2[gid2]++;    
            }
            else if (t1 > t2) {
                group1[gid1]++;
            }
            else {
                group2[gid2]++;  
                group1[gid1]++;  
            }
        }
    }
    cout << "Case #" << t << ": ";
    for (int i = 0; i < g; i++) {
        if (type[i] == 'C') {
            cout << group1[gtc[i]] << " ";
        }
        else {  
            cout << group2[gtc[i]] << " ";
        }
    }
    cout << endl;
}

int main() {
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        sherlock(t);
    }
}