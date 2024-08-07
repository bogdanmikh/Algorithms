#include "../bits/stdc++.h"

using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> dp(n + 1, INT_MAX); // dp[i] - мин число на которое заканчивается возрастающая послед. длины i
    dp[0] = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int ind = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        dp[ind] = min(arr[i], dp[ind]);
    }
    for (int i = n; i >= 0; --i) {
        if (dp[i] != INT_MAX) {
            cout << i << endl;
            return;
        }
    }
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