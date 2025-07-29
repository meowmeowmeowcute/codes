#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k, x, a, b, c;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> x >> a >> b >> c;

    deque<pair<int, int>> dq;  // {index, value}
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && dq.back().second >= x)
            dq.pop_back();
        dq.emplace_back(i, x);

        if (!dq.empty() && dq.front().first <= i - k)
            dq.pop_front();

        if (i >= k - 1)
            ans ^= dq.front().second;

        x = (a * x + b) % c;
    }

    cout << ans << '\n';
}
