#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int ky[4] = {-1, 0, 1, 0};
int kx[4] = {0, 1, 0, -1};

int visited[1002][1002];
int graph[1002][1002];
int ans = 0;

void bfs(int y, int x){
    queue<pii> q;
    q.push({y, x});
    visited[y][x] = 1;
    while(!q.empty()){
        pii cyx = q.front();
        q.pop();
        int cy = cyx.first;int cx = cyx.second;
        for (int i = 0; i <4; i++){
            int mvy = cy+ky[i];
            int mvx = cx+kx[i];
            if (graph[mvy][mvx]&&!visited[mvy][mvx]){
                q.push({mvy, mvx});
                visited[mvy][mvx] = 1;
            }
        }
    }
    ans++;
}


int main (){
    int n, m;
    char s;
    cin >> n >> m;
    for (int y = 1; y<=n; y++){
        for (int x = 1; x<=m; x++){
            cin >> s;
            if (s == '#'){
                graph[y][x] = 0;
            }else{
                graph[y][x] = 1;
            }
        }
    }
    for (int y = 1; y<=n; y++){
        for (int x = 1; x<=m; x++){
            if(graph[y][x]&&!visited[y][x]){
                bfs(y, x);
            }
        }
    }
    cout << ans;
    
}