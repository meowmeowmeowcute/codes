# include <bits/stdc++.h>
using namespace std;

int n, m, k, xa, ya;
int crid = 1;
int maxarea = 0;
vector<int> rela;
rela.push_back(0);
vector<int> areas;
char str;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
void bfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, vector<vector<int>> &id, int yi, int xi){
    int area = 1;
    deque<pair<int, int>> dq;
    dq.push_back({yi, xi});
    id[yi][xi] = crid;
    visited[yi][xi] = 1;
    while(!dq.empty()){
        pair<int, int> node = dq.front();
        dq.pop_front();
        int y = node.first;
        int x = node.second;
        for (int i = 0; i<4; i++){
            int xp = x+dx[i];
            int yp = y+dy[i];
            if (xp>=0 && xp<m && yp>=0 && yp<n){
                if (!visited[yp][xp] && graph[yp][xp]){
                    dq.push_back({yp, xp});
                    id[yp][xp] = crid;
                    visited[yp][xp] = 1;
                    area++;
                }
            }
        }
    }
    rela.push_back(crid);
    crid++;
    areas.push_back(area);
    if (area>maxarea){
        maxarea = area;
    }
}

void bfs_c(vector<vector<int>> &graph, vector<vector<bool>> &visited, vector<vector<int>> &id, int yi, int xi){
    int area = 1;
    deque<pair<int, int>> dq;
    dq.push_back({yi, xi});
    id[yi][xi] = crid;
    visited[yi][xi] = 1;
    while(!dq.empty()){
        pair<int, int> node = dq.front();
        dq.pop_front();
        int y = node.first;
        int x = node.second;
        for (int i = 0; i<4; i++){
            int xp = x+dx[i];
            int yp = y+dy[i];
            if (xp>=0 && xp<m && yp>=0 && yp<n){
                if (!visited[yp][xp] && graph[yp][xp]){
                    dq.push_back({yp, xp});
                    id[yp][xp] = crid;
                    visited[yp][xp] = 1;
                    area++;
                }
            }
        }
    }
    rela.push_back(crid);
    crid++;
    areas.push_back(area);
    if (area>maxarea){
        maxarea = area;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<vector<int>> id(n, vector<int>(m));
    for (int y = 0; y<n; y++){
        for (int x = 0; x<m; x++){
            cin >> str;
            if (str == '@'){
                graph[y][x] = 1;
            }
        }
    }
    for(int y = 0; y<n; y++){
        for (int x = 0; x<m; x++){
            if (!visited[y][x] && graph[y][x]){
                bfs(graph, visited, id, y, x);
            }
        }
    }
    set<int> graph_c[areas.size()];
    cin >>k;
    set<int> items; 
    for (int i = 0; i<k; i++){
        cin >> ya >> xa;
        for (int j = 0; j<4; j++){
            int yp = ya+dy[j];
            int xp = xa+dx[j];
            if (xp>=0 && xp<m && yp>=0 && yp<n){
                if (id[yp][xp]){
                    items.insert(id[yp][xp]);
                }
            }
        }
        for(auto l : items){
            for(auto j : items){
                if (j!=l){
                    graph_c[l].insert(j);
                }
            }
        }
        int area_c = 1;
        for(auto l : graph_c[*items.begin()]){
            area_c+= areas[l];
        }
        if (area_c>maxarea){
            maxarea = area_c;
        }
        cout << maxarea;

    }
    
    
/*
    for(int y = 0; y<n; y++){
        for (int x = 0; x<m; x++){
            cout << graph[y][x] << ' ';
        }
        cout << "\n";
    }
    cout << "\n";
    for(int y = 0; y<n; y++){
        for (int x = 0; x<m; x++){
            cout << visited[y][x] << ' ';
        }
        cout << "\n";
    }
    cout << "\n";
    for(int y = 0; y<n; y++){
        for (int x = 0; x<m; x++){
            cout << id[y][x] << ' ';
        }
        cout << "\n";
    }
    cout << "\n== Areas ==\n";
    for (int i = 0; i < areas.size(); i++) {
        cout << "Region " << i + 1 << " size: " << areas[i] << "\n";
    }
*/
}