#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    bool b[n + 1] = {};
    int rest = 0;
    int ans = 1;
    for (int i = 0; i < n; i += 1) {
        b[a[i]] = true;
        rest += 1;
        if (b[i + 1] == true) {
            rest -= 1;
        }
        if (rest == 0) {
            ans += 1;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc += 1) {
        solve();
    }
}