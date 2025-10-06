#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll a[3], b[3];
    for (int i = 0; i < 3; i += 1) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i]) swap(a[i], b[i]);
    }
    ll root = sqrtl(a[0]*b[0] + a[1]*b[1] + a[2]*b[2]);
    if (root != (ll)root) {
        cout << 0;
        return;
    }
    auto canCombine = [&](int x, int y, int xx, int yy, int xxx, int yyy) {
        if (x == xx) {
            int newx = x;
            int newy = y + yy;
            if (newx > newy) swap(newx, newy);
            if (newx == xxx && newy + yyy == newx) return true;
            if (newy == yyy && newx + xxx == newy) return true;
        }
        return false;
    };
    if (canCombine(a[0], b[0], a[1], b[1], a[2], b[2]) ||
        canCombine(b[0], a[0], b[1], a[1], a[2], b[2]) ||
        canCombine(a[1], b[1], a[2], b[2], a[0], b[0]) ||
        canCombine(b[1], a[1], b[2], a[2], a[0], b[0]) ||
        canCombine(a[0], b[0], a[2], b[2], a[1], b[1]) ||
        canCombine(b[0], a[0], b[2], a[2], a[1], b[1])) {
        cout << root;
        return;
    }
    cout << 0;
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