# include<bits/stdc++.h>
using namespace std;

# define pb push_back

int n, m, a, b; 
vector<int> graph[100005];
int visited[100005];
int flag = false;

void bfs (int start){
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    int cur;
    while (!q.empty()){
        cur = q.front();
        q.pop();
        for (auto p : graph[cur]){
            if (visited[p] == visited[cur]){
                flag = true;
                break;
            }
            if (!visited[p]){
                q.push(p);
                visited[p] = 3-visited[cur];
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
    for (int i = 1; i<=n; i++   ){
        if (!visited[i]){
            bfs(i);
            // cout << "<" << i << ">\n"; 
        }
    }
    if (flag){
        cout << "IMPOSSIBLE";
    }else{
        for (int i = 1; i<=n; i++){
            cout << visited[i] << ' ';
        }
    }

}