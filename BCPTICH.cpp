#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int t;
    ll n;
    cin >> t >> n;
    cout << t << ' ';
    ll ans = 0;
    ll m = 2 * n;
    for (ll i = 2; i <= sqrtl(m); i += 1) {
        if (m % i == 0) {
            if ((m / i + i - 1) % 2 == 0 && (i - (m / i + i - 1) / 2 >= 1 || m / i - (m / i + i - 1) / 2 >= 1)) {
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc += 1) {
        solve();
    }
}