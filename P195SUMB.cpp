#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    ll a[n];
    for (ll &x : a) cin >> x;
    if (n == 0) {
        cout << 0 << " " << 0;
    }
    ll tl = 0, tr = 0;
    int l = 0, r = n - 1;
    int cntl = 0, cntr = 0;
    while (l <= r) {
        if (tl <= tr) {
            tl += a[l];
            l += 1;
            cntl += 1;
        } else {
            tr += a[r];
            r -= 1;
            cntr += 1;
        }
    }
    cout << cntl << " " << cntr;
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