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

int main ()
{
    char suit, rank;
    scanf("%c%c ", &rank, &suit);

    char s, r;
    for (int i = 0; i < 5; i++) {
        scanf("%c%c", &r, &s);
        if (i != 4) scanf(" ");
        if (r == rank || s == suit) {
            cout << "YES" << endl;
            return 0;
        } 
    }
    cout << "NO" << endl;  
	return 0;
}