class MajorityChecker {
private:
    int n;
    vector<tuple<int,int,int>> v;
    unordered_map<int, vector<int>> umap;
public:
    int findcount(int x, int l, int r) {
        // return count of x in [l, r) in logN
        int c = lower_bound(umap[x].begin(), umap[x].end(), r) - lower_bound(umap[x].begin(), umap[x].end(), l); 
        // cout << x << " " << l << " " << r << " " << c << endl;
        return c;
    }
    
    MajorityChecker(vector<int>& arr) {
        n = arr.size();
        for (int i = 0; i < n; i++) {
            umap[arr[i]].push_back(i);
        }
        
        // build segment tree leaves
        v.resize(2 * n);
        for (int i = 0; i < n; i++) {
            v[i + n] = {arr[i], i, i+1};
        }
        // build 1 .... n-1 n .... 2*n-1
        for (int i = n-1; i > 0; i--) {
            int l = get<1> (v[2 * i]);
            int r = get<2> (v[2 * i + 1]);
            int c1 = findcount(get<0> (v[2 * i]), l, r);
            int c2 = findcount(get<0> (v[2 * i + 1]), l, r);
            if (c1 > c2) {
                v[i] = {get<0> (v[2 * i]), l, r};
            }
            else {
                v[i] = {get<0> (v[2 * i + 1]), l, r};
            }
        }
        for (int i = 0; i < 2 * n; i++) {
            cout << get<0> (v[i]) << " ";
        }
        cout << endl;
    }
    
    int query(int left, int right, int threshold) {
        vector<int> can; // logN size
        int l = left + n;
        int r = right + 1 + n;
        while (l < r) {
            if (l % 2 == 1) { // right child;
                can.push_back(get<0> (v[l]));
                l++;
            }
            l /= 2;
            if (r % 2 == 1) {
                can.push_back(get<0> (v[r - 1]));
                r--;
            }
            r /= 2;
        }
        int mi, c = INT_MIN;
        for (int i = 0; i < can.size(); i++) {
            int d = findcount(can[i], left, right + 1);
            if (d > c) {
                c = d;
                mi = can[i];
            }
        }
        if (c >= threshold) return mi;
        else return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
*/