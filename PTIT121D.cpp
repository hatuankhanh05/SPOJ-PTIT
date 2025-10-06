#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll len[28];

void calLen() {
    len[0] = 3;
    for (int i = 1; i <= 27; i += 1) {
        len[i] = len[i - 1] * 2 + i + 2 + 1;
    }
}

char find(ll n, int k) {
    if (k == 0) {
        if (n == 1) return 'm';
        else return 'o';
    }
    if (n <= len[k - 1]) return find(n, k - 1);
    if (n > len[k - 1] + k + 2 + 1) return find(n - len[k - 1] - k - 2 - 1, k - 1);
    if (n == len[k - 1] + 1) return 'm';
    return 'o';
}

void solve() {
    ll n;
    cin >> n;
    cout << find(n, 27);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    calLen();
    for (int tc = 1; tc <= t; tc += 1) {
        solve();
    }
}