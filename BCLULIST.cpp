#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            for (int k = 0; k * 2 <= j; k += 1) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
    ll res = 0;
    for (int i = 0; i <= m; i += 1) res += dp[n][i];
    cout << n << ' ' << m << ' ' << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc += 1) {
        cout << "Data set " << tc << ": ";
        solve();
    }
}