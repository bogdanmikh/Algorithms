#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> g;
vector<int> h;
vector<bool> used;
int maxH = 0;

void dfs(int ver, int curH) {
    used[ver] = true;
    maxH = max(maxH, curH);
    for (auto u : g[ver]) {
        dfs(u, curH + 1);
    }
}

void dfsH(int ver, int curH) {
    h[ver] = curH;
    used[ver] = true;
    maxH = max(maxH, curH);
    for (auto u : g[ver]) {
        dfsH(u, curH + 1);
    }
}

int main() {
    int n; cin >> n;

    g.resize(n);
    used.resize(n);

    for (int i = 0; i < n; i++) {
        int cnt; cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int ver; cin >> ver;
            ver--;
            g[i].push_back(ver);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) dfs(i, 1);
    }
    used.assign(n, false);
    h.resize(n);
    for (int i = 0; i < n; i++) {
        if (!used[i]) dfsH(i, 1);
    }
    vector<vector<int>> ans(maxH + 1);
    for (int i = 0; i < n; ++i) {
        ans[h[i]].emplace_back(i);
    }
    cout << maxH << endl;
    std::reverse(ans.begin(), ans.end());
    ans.pop_back();
    for (const auto &v: ans) {
        cout << v.size() << " ";
        for (const auto &u: v) {
            cout << u + 1 << " ";
        }
        cout << endl;
    }
}
