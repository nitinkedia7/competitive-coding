#include <bits/stdc++.h>
using namespace std;


bool consistent(int codesum, int eatsum, int a, int b) {
    if (codesum < a || eatsum < b) return false;
    return true;
}

bool codeharder(int codesum, int eatsum, int a, int b) {
    // a coding target, b eating target
    return (codesum - a) <= (eatsum - b);
}

// code ratio ascending
bool ccomp(pair<int,int> &a, pair<int,int> &b) {
    if (a.first == 0 && b.first == 0) {
        return a.second > b.second;
    }
    if (a.first == 0) {
        return true;
    }
    if (b.first == 0) {
        return false;
    }
    {
        if (a.second == 0 && b.second == 0) {
            return a.first < b.first;
        }
        if (a.second == 0) {
            return false;
        }
        if (b.second == 0) {
            return true;
        }
        {
            double x = a.first;
            x /= a.second;
            double y = b.first;
            y /= b.second;
            return x < y;
        }
    }
}

bool ecomp(pair<int,int> &a, pair<int,int> &b) {
    // return !ccomp(a, b);
    if (a.second == 0 && b.second == 0) {
        return a.first > b.first;
    }
    if (a.second == 0) {
        return true;
    }
    if (b.second == 0) {
        return false;
    }
    {
        if (a.first == 0 && b.first == 0) {
            return a.second < b.second;
        }
        if (a.first == 0) {
            return false;
        }
        if (b.first == 0) {
            return true;
        }
        {
            double x = a.second;
            x /= a.first;
            double y = b.second;
            y /= b.first;
            return x < y;
        }
    }
}

int lowerbound(vector<pair<int,int>> &v, int target) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid].second < target) {
            l = mid + 1;
        } 
        else r = mid - 1;
    }
    return l;
}

int lowerboundprime(vector<pair<int,int>> &v, int target) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid].first < target) {
            l = mid + 1;
        } 
        else r = mid - 1;
    }
    return l;
}

string func(void) {
    string ans;
    int d, s;
    cin >> d >> s;
    int c, e;
    vector<pair<int,int>> slots(s);
    int codesum = 0, eatsum = 0;
    for (int i = 0; i < s; i++) {
        cin >> c >> e;
        slots[i] = {c, e};
        codesum += c;
        eatsum += e;
    }
    vector<pair<int,int>> slotscopy = slots;
    sort(slots.begin(), slots.end(), ccomp);
    sort(slotscopy.begin(), slotscopy.end(), ecomp);

    vector<pair<int,int>> oldslots = slots;
    vector<pair<int,int>> oldslotscopy = slotscopy;
    
    // prefix sum
    for (int i = 1; i < s; i++) {
        slots[i].second += slots[i-1].second;
        slotscopy[i].first += slotscopy[i-1].first;
    }
    
    for (int i = s - 2; i >= 0; i--) {
        slots[i].first += slots[i+1].first;
        slotscopy[i].second += slotscopy[i+1].second;
    }
    
    int a, b;
    bool codehard;
    for (int i = 0; i < d; i++) {
        cin >> a >> b;
        if (!consistent(codesum, eatsum, a, b)) {
            ans += 'N';
            continue;
        }
        codehard = codeharder(codesum, eatsum, a, b);
        if (codehard) {
            int l = lowerbound(slots, b); // eat first
            // b should now be satisfied, check if a is doable
            double a1 = l >= s-1 ? 0 : slots[l+1].first;
            if (slots[l].second > b) {
                int prevsum = l == 0 ? 0 : slots[l-1].second;
                int diff = b - prevsum;
                double f = diff;
                assert(oldslots[l].second);
                f /= (oldslots[l].second);  
                a1 += (1 - f) * oldslots[l].first;
            }
            if (a1 >= a) {
                ans += 'Y';
                continue;
            } 
            else {
                ans += 'N';
                continue;
            }
        }
        else {
            int l = lowerboundprime(slotscopy, a); // code first
            // a should now be satisfied, check if b is doable
            double b1 = l >= s-1 ? 0 : slotscopy[l+1].second;
            if (slotscopy[l].first > a) {
                int prevsum = l == 0 ? 0 : slotscopy[l-1].first;
                int diff = a - prevsum;
                double f = diff;
                assert(oldslotscopy[l].first);
                f /= (oldslotscopy[l].first);  
                b1 += (1 - f) * oldslotscopy[l].second;
            }
            if (b1 >= b) {
                ans += 'Y';
                continue;
            } 
            else {
                ans += 'N';
                continue;
            }
        }
    }
    slots.clear();
    slotscopy.clear();
    oldslots.clear();
    slotscopy.clear();

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        cout << "Case #" << t << ": " << func() << endl;
    }
    return 0;
}