#include <iostream>
#include <algorithm>
using namespace std;

struct Test {
    int x, y, z;
};

bool comp(Test t1, Test t2) {
    return (t1.x < t2.x);
}

int main() {
    int k;
    cin >> k;

    int len[k];
    Test arr[200000];
    int sum = 0;
    int index = 0;
    for (int i = 0; i < k; i++) {
        cin >> len[i];
        sum = 0;
        for (int j = index; j < index+len[i]; j++) {
            cin >> arr[j].x;
            sum += arr[j].x;
            arr[j].y = i;
            arr[j].z = j-index;
        }
        for (int j = index; j < index+len[i]; j++) {
            arr[j].x = sum-arr[j].x;

        }
        index += len[i];
    }
    // for (int i = 0; i < index; i++) {
    //     cout << arr[i].x << " " << arr[i].y << " " << arr[i].z << endl;
    // }
    sort(arr, arr+index, comp);
    // cout << endl;
    // for (int i = 0; i < index; i++) {
    //     cout << arr[i].x << " " << arr[i].y << " " << arr[i].z << endl;
    // }
    for (int i = 1; i < index; i++) {
        if (arr[i].x == arr[i-1].x && arr[i].y != arr[i-1].y) {
            cout << "YES" << endl;
            cout << arr[i].y+1 << " " << arr[i].z+1 << endl;
            cout << arr[i-1].y+1 << " " << arr[i-1].z+1 << endl;;
            return 0;
        }
    }
    cout << "NO" << endl;
}