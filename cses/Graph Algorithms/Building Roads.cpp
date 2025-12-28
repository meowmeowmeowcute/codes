# include<bits/stdc++.h>
using namespace std;
 
# define pb push_back
 
int n, m, a, b; 
vector<int> graph[100005];
int visited[100005];
int boss_of_area[100005];
int cur_idx = 0;
 
void bfs (int start){
    cur_idx++;
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    int cur;
    while (!q.empty()){
        cur = q.front();
        q.pop();
        for (auto p : graph[cur]){
            if (!visited[p]){
                q.push(p);
                visited[p] = 1;
            }
        }
    }
    boss_of_area[cur_idx] = start;
 
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
    cout << cur_idx-1 << "\n";
    for (int i = 1; i<cur_idx; i++){
        cout << boss_of_area[i] << ' ' << boss_of_area[i+1] << '\n';
    }
