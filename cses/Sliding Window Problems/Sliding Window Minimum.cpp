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
        // 移除尾端比目前值大的
        while (!dq.empty() && dq.back().second >= x)
            dq.pop_back();
        dq.emplace_back(i, x);

        // 移除視窗外的值
        if (!dq.empty() && dq.front().first <= i - k)
            dq.pop_front();

        // XOR 視窗最小值
        if (i >= k - 1)
            ans ^= dq.front().second;

        // 產生下一個數字
        x = (a * x + b) % c;
    }

    cout << ans << '\n';
}
