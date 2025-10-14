#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    int m = 2 * n;
    int a[m];
    for (int i = 0; i < m; i += 1) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < m - 1; i += 2) {
        int pos = -1;
        for (int j = i + 1; j < m; j += 1) {
            if (a[j] == a[i]) {
                pos = j;
            }
        }
        for (int j = pos; j - 1 > i; j -= 1) {
            swap(a[j], a[j - 1]);
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