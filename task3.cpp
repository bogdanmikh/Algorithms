#include "bits/stdc++.h"

using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int64_t> dp(n + 1);
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1];
        if (a[i - 1] + a[i] > -a[i - 1] - a[i]) {
            dp[i] += a[i - 1] + a[i];
        } else {
            dp[i] -= a[i - 1] - a[i];
            a[i - 1] *= -1;
            a[i] *= -1;
        }
//        cout << dp[i] << " ";
    }
    cout << dp[n - 1] << endl;;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        sol();
    }
}
