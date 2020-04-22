#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

struct Node {
    bool is_end;
    Node* children[26];
};

Node *create() {
    Node *node = new Node();
    node->is_end = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(Node *root, string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (root->children[s[i] - 'A'] == NULL) {
            root->children[s[i] - 'A'] = create();
        }
        root = root->children[s[i] - 'A'];
    }
    root->is_end = true;
}

bool search(Node *root, string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (root->children[s[i] - 'A'] == NULL) {
            return false;
        }
        root = root->children[s[i] - 'A'];
    }
    return root->is_end;
}

void recur(int i, int l, string &s, Node *root, vector<vector<int>> &v, string &ans) {
    if (i == l) {
        if (!search(root, s)) ans = s;
        return;
    } 
    for (int j = 0; j < v[i].size(); j++) {
        s.push_back('A' + v[i][j]);
        recur(i+1, l, s, root, v, ans);
        s.pop_back();
    }
    return;
}

void sherlock(int t) {
    int n, l;
    cin >> n >> l;
    Node *root = create();
    vector<vector<int>> v(l, vector<int> (26));
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        insert(root, s);
        for (int j = 0; j < l; j++) {
            v[j][s[j] - 'A'] = 1;
        }
    }
    int p = 1;
    vector<vector<int>> v1(l);
    for (int i = 0; i < l; i++) {
        int need = (n+1) / p + 1;
        // cout << need << ",";
        for (int j = 0; j < 26; j++) {
            if (v[i][j] && need > 0) {
                v1[i].push_back(j);
                need--;
            } 
        }
        // cout << v1[i].size() << " ";
        p *= v1[i].size();
    }
    // cout << endl;
    s.clear();
    string ans = "-";
    recur(0, l, s, root, v1, ans);
    cout << "Case #" << t << ": " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}