#include "bits/stdc++.h"

using namespace std;

void sol() {
    int n, l;
    cin >> n >> l;
    vector<int> arr(n);
    for (auto &item: arr) {
        cin >> item;
    }
    sort(arr.begin(), arr.end());
    int maxDiff = 2 * max(arr[0], l - arr[n - 1]);
    for (int i = 2; i < n - 1; ++i) {
        maxDiff = max(arr[i] - arr[i - 1], maxDiff);
    }
    cout << std::fixed << setprecision(10);
    cout << float(maxDiff) / 2. << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
//    cin >> t;
    for (int i = 0; i < t; ++i) {
        sol();
    }
}