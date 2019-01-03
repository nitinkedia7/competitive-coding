#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
 
int main() {
    int n;
    cin >> n;
    vector < pair <int, int> > vect;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        vect.push_back( make_pair(i+1, temp) );
    }
    int m = 2 * n;
    string array;
    cin >> array;

    sort(vect.begin(), vect.end(), sortbysec);
    priority_queue <int> gquiz;
    int intro = 0, extro = 0;
    for (int i = 0; i < m; i++) {
        if (array[i] == '0') {
            cout << vect[intro].first << " ";
            gquiz.push(intro);
            intro++;
        }
        else {
            extro = gquiz.top();
            gquiz.pop();
            cout << vect[extro].first << " ";
        }
    }
    return 0;
}