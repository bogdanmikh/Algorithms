#include "bits/stdc++.h"

using namespace std;

// x1 y1 1 2
// x2 y2 2 3
// x1 - y1 == x2 - y2 || x1 + y1 == x2 + y2
//y: 1 2 3 4
//   0 0 0 0 | x: 1
//   0 0 1 0 | x: 2
//   0 0 0 0 | x: 3
//   1 0 0 0 | x: 4

void sol() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    map<int, int> main, nemain;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += main[x[i] - y[i]];
        ans += nemain[x[i] + y[i]];

        main[x[i] - y[i]]++;
        nemain[x[i] + y[i]]++;
    }
    cout << ans << endl;
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
