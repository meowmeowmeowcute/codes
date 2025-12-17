#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int ky[4] = {-1, 0, 1, 0};
int kx[4] = {0, 1, 0, -1};
char ktp[4] = {'U', 'R', 'D', 'L'};

int visited[1002][1002];
char father[1002][1002];
int graph[1002][1002];
pii start, goal;
string ans;

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
                father[mvy][mvx] = ktp[i];
                q.push({mvy, mvx});
                visited[mvy][mvx] = 1;
            }
        }
    }
}

void gen_ans(){
    pii to = goal;
    while (to!=start){
        char dir = father[to.first][to.second];
        // cout << "f: " << to.first << " s: " << to.second << " d: " << dir << "\n";
        if(dir == 'U'){to.first+=ky[2];to.second+=kx[2];}
        if(dir == 'R'){to.first+=ky[3];to.second+=kx[3];}
        if(dir == 'D'){to.first+=ky[0];to.second+=kx[0];}
        if(dir == 'L'){to.first+=ky[1];to.second+=kx[1];}
        ans += dir;
    }
    reverse(ans.begin(), ans.end());
}

int main (){
    int n, m;
    char s;
    cin >> n >> m;
    for (int y = 1; y<=n; y++){
        for (int x = 1; x<=m; x++){
            cin >> s;
            if (s == 'A'){
                start = {y, x};
            }
            if (s == 'B'){
                goal = {y, x};
            }
            if (s == '#'){
                graph[y][x] = 0;
            }else{
                graph[y][x] = 1;
            }
        }
    }
    bfs(start.first, start.second);
    if (visited[goal.first][goal.second]){
        cout << "YES\n";
        gen_ans();
        cout << ans.end()-ans.begin() << "\n";
        cout << ans;
    }else{
        cout << "NO\n";
    }   
}