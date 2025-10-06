#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = (1LL << 31) - 1;

void solve() {
    int n;
    cin >> n;
    char grid[n][n];
    for (int i = 0; i < n; i += 1) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j += 1) {
            grid[i][j] = s[j];
            // cin >> grid[i][j];
        }
    }
    if (grid[0][0] == '#' || grid[n - 1][n - 1] == '#') {
        cout << "INCONCEIVALBE";
        return;
    }
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i += 1) {
        if (grid[0][i] == '#') {
            dp[0][i] = 0;
            break;
        }
        dp[0][i] += dp[0][i - 1];
        dp[0][i] %= MOD;
    }
    for (int i = 1; i < n; i += 1) {
        if (grid[i][0] == '#') {
            dp[i][0] = 0;
            break;
        }
        dp[i][0] += dp[i - 1][0];
        dp[i][0] %= MOD;
    }
    for (int i = 1; i < n; i += 1) {
        for (int j = 1; j < n; j += 1) {
            if (grid[i][j] == '#' || dp[i - 1][j] == 0 && dp[i][j - 1] == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (dp[i - 1][j] != 0) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }
            if (dp[i][j - 1] != 0) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }
    if (dp[n - 1][n - 1] != 0) {
        cout << dp[n - 1][n - 1];
    } else {
        vector<vector<bool>> vst(n, vector<bool>(n, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        const int di[] = {0, 0, -1, 1};
        const int dj[] = {1, -1, 0, 0};
        vst[0][0] = 1;
        while (!q.empty()) {
            auto [curri, currj] = q.front();
            q.pop();
            if (curri == n - 1 && currj == n - 1) {
                cout << "THE GAME IS A LIE";
                return;
            }
            for (int i = 0; i < 4; i += 1) {
                int newi = curri + di[i];
                int newj = currj + dj[i];
                if (newi < 0 || newi > n - 1 || newj < 0 || newj > n - 1) continue;
                if (vst[newi][newj] || grid[newi][newj] == '#') continue;
                vst[newi][newj] = 1;
                q.push({newi, newj});
            }
        }
        cout << "INCONCEIVABLE";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}