#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i += 1) {
        cin >> a[i];
    }
    vector<int> b;
    int ans = 0;
    for (int i = 1; i <= n; i += 1) {
        b.push_back(a[i]);
        b.erase(remove(b.begin(), b.end(), i), b.end());
        if (b.empty()) {
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