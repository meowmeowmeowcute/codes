# include<bits/stdc++.h>
using namespace std;

# define pb push_back

int n, m, a, b; 
vector<int> graph[100005];
int visited[100005];
vector<int> road;

void bfs (int start, int goal){
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    int cur;
    while (!q.empty()){
        cur = q.front();
        q.pop();
        if (cur == goal){
            break;
        }
        for (auto p : graph[cur]){
            if (!visited[p]){
                q.push(p);
                visited[p] = cur;
            }
        }
    }
}

int main (){
    cin >> n >> m;         
    for (int i = 0 ; i<m; i++){
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    bfs(1, n);
    if (visited[n]){
        int cur = n;
        while(cur!=1){
            road.pb(cur);
            cur = visited[cur];
        }
        road.pb(1);
        cout << road.size() << "\n";
        for (int i = road.size()-1; i>=0; i--){
            cout << road[i] << ' ';
        }
    }else{
        cout<< "IMPOSSIBLE";
    }
}