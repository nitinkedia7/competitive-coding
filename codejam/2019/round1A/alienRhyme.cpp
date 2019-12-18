#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node * children[26];
    int isEnd;
};

Node* create() {
    Node *temp = new Node();
    for (int i = 0; i < 26; i++) temp->children[i] = NULL;
    temp->isEnd = 0;
    return temp;
}

void insert(Node *root, string &s) {
    int cc;
    for (int i = 0; i < s.length(); i++) {
        cc = s[i] - 'A'; 
        if (root->children[cc] == NULL) {
            root->children[cc] = create();
        }
        root = root->children[cc];
    }
    // cout << "Inserted " << s << endl;
    root->isEnd = 1;
}

int dfs(Node *u, Node *root, int &ss) {
    if (u == NULL) return 0;
    int cs = u->isEnd;
    for (int i = 0; i < 26; i++) {
        cs += dfs(u->children[i], root, ss);
    }
    if (u != root && cs >= 2) {
        cs -= 2;
        ss += 2;
    }
    return cs;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<string> v(n);
    Node *root = new Node();
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        reverse(v[i].begin(), v[i].end());
        insert(root, v[i]);
    }
    int ss = 0;
    dfs(root, root, ss);
    cout << "Case #" << t << ": " << ss << endl;
    v.clear();
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) sherlock(i+1);
    return 0;
}
