#include "bits/stdc++.h"

using namespace std;

vector<int> zFunc(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (z[i] + i < n && (s[z[i]] == s[z[i] + i] || s[z[i] + i] == '?')) {
            z[i]++;
        }
        if (z[i] + i - 1 > r) {
            l = i;
            r = z[i] + i - 1;
        }
    }
    return z;
}

void sol() {
    string s, t;
    cin >> s >> t;
    vector<int> z = zFunc(t + '$' + s);
    int ind = -1;
    for (int i = 0; i < z.size(); i++) {
        if (z[i] == t.size()) {
            ind = i - t.size() - 1;
            break;
        }
    }
    if (ind == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    string ans;
    for (int i = 0; i < s.size(); ++i) {
        if (ind == i) {
            ans += t;
            i += t.size();
            continue;
        }
        if (s[i] == '?') {
            ans.push_back('a');
        } else {
            ans.push_back(s[i]);
        }
    }
    cout << ans << endl;
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
