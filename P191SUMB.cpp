#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Problem {
    int d, g;

    Problem (int d, int g) {
        this->d = d;
        this->g = g;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, b;
    cin >> s >> b;
    int a[s];
    for (int &x : a) {
        cin >> x;
    }
    vector<Problem> problems;
    for (int i = 0; i < b; i += 1) {
        int d, g;
        cin >> d >> g;
        problems.push_back(Problem(d, g));
    }
    sort(problems.begin(), problems.end(), [&](Problem x, Problem y) {
        return x.d < y.d;
    });
    vector<int> pref(b + 1, 0);
    for (int i = 1; i <= b; i += 1) {
        pref[i] = pref[i - 1] + problems[i - 1].g;
    }
    for (int i = 0; i < s; i += 1) {
        int x = a[i];
        int pos = upper_bound(problems.begin(), problems.end(), x, [&](int search_level, const Problem &p) {
            return search_level < p.d;
        }) - problems.begin();
        cout << pref[pos] << ' ';
    }
}