# include <bits/stdc++.h>
# define int long long
# define pii pair<int, int> 
# define ARR (int)3e5+5
using namespace std;

priority_queue<pii, vector<pii>, greater<pii>> pq;
int pre[ARR], nex[ARR], n, t, graph[ARR];

signed main(){
    cin >> n >> t;
    for (int i = 0; i<n; i++){
        cin >> graph[i];
        pq.push({graph[i], i});
    }
    for (int i = 1; i<=n; i++){
        pre[i] = i-1;
        nex[i-1] = i;
    }
    int ans = 0;
    while(!pq.empty()){
        auto [cur, id] = pq.top();
        pq.pop();
        if (cur!=graph[id])continue;
        if (cur>t)break;
        graph[nex[id]]+=graph[id];
        ans+=graph[id];
        graph[id] = 0;
        nex[pre[id]] = nex[id];
        pre[nex[id]] = pre[id];
        if (nex[id]<n) pq.push({graph[nex[id]], nex[id]});
    }    
    cout << ans;   
}