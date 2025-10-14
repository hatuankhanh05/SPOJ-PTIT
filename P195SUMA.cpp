#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a + n);
    if (k == 0) {
        if (a[0] == 1) {
            cout << -1;
        } else {
            cout << 1;
        }
        return;
    }
    if (k >= n) {
        cout << a[n - 1];
        return;
    }
    if (a[k] == a[k - 1]) {
        cout << -1;
    } else {
        cout << a[k - 1];
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