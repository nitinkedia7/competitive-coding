#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> zebra;
    vector<int> azebra;

    string bs;
    cin >> bs;
    int n = bs.length();
    vector<int> main[n];
    for (int i = 0; i < n; i++) {
        if (bs[i] == '1') {
            if (zebra.size() == 0) {
                cout << -1 << endl;
                return 0;
            }
            else {
                int temp = zebra.back();
                zebra.pop_back();
                main[temp].push_back(i);
                azebra.push_back(temp);
            }
        }
        else {
            if (azebra.size() == 0) {
                main[i].push_back(i);
                zebra.push_back(i);
            }
            else {
                int temp = azebra.back();
                azebra.pop_back();
                main[temp].push_back(i);
                zebra.push_back(temp);
            }
        }
    }
    if (azebra.size() != 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << zebra.size() << endl;
    for (int i = 0; i < zebra.size(); i++) {
        int t = zebra[i];
        cout << main[t].size() << " ";
        for (int j = 0; j < main[t].size(); j++) {
            cout << main[t][j]+1 << " ";
        }
        cout << endl;
    }
}
