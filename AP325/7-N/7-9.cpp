# include<bits/stdc++.h>
using namespace std;

# define pii pair<int, int>
# define vpii vector<pii>
# define MAX 10005
# define inf 1000000000


int n, m, j, q, k, cant = 0, ans = 0;
vpii graph[MAX];
vector<int> dist;

priority_queue<pii, vector<pii>, greater<pii>> pq;

int main (){
    cin >> n >> m;
    dist.assign(n, inf);
    dist[0] = 0;
    for (int i = 0 ; i<m; i++){
        cin >> j >> q >> k;
        graph[j].push_back({q, k});
        graph[q].push_back({j, k});
    }
    pq.push({0, 0});//dist, point
    while(!pq.empty()){
        auto [d, from] = pq.top();
        pq.pop();
        if (d>dist[from])continue;
        for(auto [to, w] : graph[from]){
            if (dist[from]+w<dist[to]){
                dist[to] = dist[from]+w;
                pq.push({dist[to], to});
            }
        }
    }
    for (int i = 0; i<n; i++){
        if (dist[i]==inf){
            cant++;
        }else{
            ans = max (ans , dist[i]);
        }
    }
    cout << ans << "\n" << cant;
}