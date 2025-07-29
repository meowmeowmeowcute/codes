# include <bits/stdc++.h>
using namespace std;

int m, n, maximum, idx, ans = 0;
long long graph[50000] = { };
string inp;


int main(){
    cin >> m >> n;
    maximum = (1<<m)-1;
    for (int i = 0; i<n; i++){
        cin >> inp;
        for (int j = 0; j<inp.length(); j++){
            graph[i] |= 1<<(inp[j]-'A');
        }
    }
    sort(graph, graph+n);
    for (int i = 0; i<n; i++){
        idx = lower_bound(graph, graph+n, maximum-graph[i])-graph;
        if (idx!=n && graph[idx]==maximum-graph[i]){
            ans++;
        }
    }
    cout << ans/2 << "\n";
    return 0;
}