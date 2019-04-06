#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define popb pop_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define all(c) c.begin(),c.end()
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

bool sameo(stack<char> &st) {
    while (!st.empty()) {
        if (st.top() != '(') return false;
        st.pop();
    }
    return true;
}
 
bool samec(stack<char> &st) {
    while (!st.empty()) {
        if (st.top() != ')') return false;
        st.pop();
    }
    return true;
} 

int main ()
{
    int N = 500000 + 10;
    int n;
    cin >> n;
    vector<int> o(N, 0), c(N, 0);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int l = s.length();
        stack<char> st;
        for (int j = 0; j < l; j++) {
            if (st.empty()) st.push(s[j]);
            else {
                if (st.top() == '(' && s[j] == ')') st.pop();
                else st.push(s[j]);
            }
        }
        int lc = st.size();
        stack<char> st1 = st;
        if (sameo(st)) o[lc]++;
        if (samec(st1)) c[lc]++;
    }
    ll p = o[0]/2;
    for (int i = 1; i < N; i++) {
        p += min(o[i], c[i]);
    }
    cout << p << endl;
	return 0;
}