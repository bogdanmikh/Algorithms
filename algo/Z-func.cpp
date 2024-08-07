#include "../bits/stdc++.h"

using namespace std;

vector<int> badZ(const string& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1; i < n; ++i) {
        while (z[i] + i < n && s[z[i] + i] == s[z[i]]) {
            z[i]++;
        }
    }
//    std::sort(z.begin(), z.end());
    return z;
}

vector<int> zFunc(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (z[i] + i < n && s[z[i]] == s[z[i] + i]) {
            z[i]++;
        }
        if (z[i] + i - 1 > r) {
            l = i;
            r = z[i] + i - 1;
        }
    }
    return z;
}

bool hasSubstring(const string &str, const string &substr) {
    string mergedStr = substr + "#" + str;
    auto zFunc = badZ(mergedStr);
    return binary_search(zFunc.begin(), zFunc.end(), substr.size());
}

//abacaba
//0 0 1 0 3 0 1

void sol() {
    string s;
    cin >> s;
    auto res = zFunc(s);
    for (const auto &item : res) {
        cout << item << " ";
    }
    cout << endl;
//
//    string substr;
//    cin >> substr;
//    if (hasSubstring(s, substr)) {
//        cout << "Have this: " << substr << " Substr" << endl;
//    } else {
//        cout << "Dont Have this: " << substr << " Substr" << endl;
//    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    int t = 1;
//    cin >> t;
    for (int i = 0; i < t; ++i) {
        sol();
    }
}