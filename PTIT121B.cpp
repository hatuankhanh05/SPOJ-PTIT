#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    string s(n, '0');
    auto toGray = [&]() {
        string r(s);
        for (int i = 1; i < n; i += 1) {
            int bit = (s[i - 1] - '0') ^ (s[i] - '0');
            r[i] = char(bit + '0');
        }
        return r;
    };
    while (1) {
        cout << toGray() << '\n';
        int i = n - 1;
        while (i >= 0 && s[i] == '1') {
            i -= 1;
        }
        if (i < 0) break;
        s[i] = '1';
        for (int j = i + 1; j < n; j += 1) {
            s[j] = '0';
        }
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