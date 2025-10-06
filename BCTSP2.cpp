#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    int c[n][n];
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            cin >> c[i][j];
        }
    }
    int last = 0;
    ll ans = 0;
    int inf = 1e9 + 1;
    bool vst[n] = {};
    vst[0] = 1;
    for (int i = 0; i < n - 1; i += 1) {
        int next = -1;
        int mn = inf;
        for (int j = 0; j < n; j += 1) {
            if (!vst[j] && c[last][j] < mn) {
                mn = c[last][j];
                next = j;
            }
        }
        vst[next] = 1;
        last = next;
        ans += mn;
    }
    ans += c[last][0];
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;.
    while (t--) {
        solve();
    }
}