#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    string n;
    while (1) {
        cin >> n;
        if (n == "0") break;
        cout << n << ": ";
        ll ans = 0;
        for (char c : n) {
            int d = c - '0';
            if (d > 4) d -= 1;
            ans = ans * 9 + d;
        }
        cout << ans << '\n';
    }
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