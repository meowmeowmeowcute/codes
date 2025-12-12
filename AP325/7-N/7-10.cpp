# include <bits/stdc++.h>
using namespace std;

# define pii pair<int ,int>

int m, n, k, areaid = 0, graph[505][505], vis[505][505], boss[505][505];
vector<int> area;

int main (){
    cin >>  m >> n >> k;
    for (int y = 1; y<=m; y++){
        for (int x = 1; x <=n; x++){
            cin >> graph [y][x];
        }
    }
    for (int y = 1; y<=m; y++){
        for (int x = 1; x <=n; x++){
            if(!vis[y][x] and graph[y][x] !=0){
                queue<pii> q;
                
                q.push({y, x});
                while (!q.empty()){

                }
            }   
        }
    }

}