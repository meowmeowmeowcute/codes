#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, t, ans;
int graph[(int)3e5+5];
set<int> mini;

signed main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
        if (graph[i] > 0) mini.insert(graph[i]);
    }

    while (!mini.empty()) {
        int minimum = *mini.begin();
        bool moved = false;

        for (int i = 0; i < n; i++) {
            if (graph[i] == minimum && graph[i] > 0) {
                if (graph[i] > t) {
                    cout << ans << endl;
                    return 0;
                }

                int j = i + 1;
                while (j < n && graph[j] == 0) j++;

                ans += graph[i];

                if (j < n) {
                    if (graph[j] > 0) mini.erase(graph[j]);
                    graph[j] += graph[i];
                    if (graph[j] <= t) mini.insert(graph[j]);
                }

                mini.erase(graph[i]);
                graph[i] = 0;
                moved = true;
                // ?? 改為 continue（不要中斷這輪，還有其他相同 minimum 的）
                
            }
        }

        if (!moved) break;
    }

    cout << ans << endl;
}
