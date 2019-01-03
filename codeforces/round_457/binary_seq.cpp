#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
        unsigned long long n;
        int k;
        cin >> n >> k;
        int m = 0;
        vector<int> ret;
        while(n) {
                if (n&1) {
                        ret.push_back(1);
                        m++;
                }
                else
                        ret.push_back(0);
                n>>=1;
        }
        // cout << m << endl;
        reverse(ret.begin(),ret.end());

        if (k < ret.size()) cout << "No" << endl;
        else {
                int size = ret.size();
                for (int i = 0; i < k; i++) {
                        ret.push_back(0);
                }
                int l = 0;
                while (m < k) {// m increases to k;
                        while (ret[l] == 0) l++;
                        ret[l]--;
                        ret[l+1] += 2;
                        m++;
                }
                cout << "Yes" << endl;
                for (int i = 0; i < ret.size(); i++) {
                        for (int j = 0; j < ret[i]; j++) {
                                cout << size-i-1 << " ";
                        }
                }
                cout << endl;
        }
}
