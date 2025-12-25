#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int width, height, n, length = 0;
deque <pair<int, int>> nodes;
int graph[210][210] = {0};
int visited[210][210] = {0};
int dis[210][210] = {0};
int dir_y[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dir_x[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int BFS(int start_y, int start_x, int end_y, int end_x){
    memset(visited, 0, sizeof(visited));
    memset(dis, 0, sizeof(dis));
    
    deque<pair<int, int>> path;
    path.push_back({start_y, start_x});
    visited[start_y][start_x] = 1;

    while (!path.empty()){
        pair<int, int> cur = path.front();
        path.pop_front();
        for (int i = 0; i<8; i++){
            int ny = cur.first + dir_y[i];
            int nx = cur.second + dir_x[i];
            
            if (ny >= 0 && ny < height && nx >= 0 && nx < width){
                if(graph[ny][nx]){
                    if (!visited[ny][nx]){
                        visited[ny][nx] = 1;
                        dis[ny][nx] = dis[cur.first][cur.second] + 1;
                        path.push_back({ny, nx});
                        if (ny == end_y && nx == end_x){
                            return dis[ny][nx];
                        }
                    }
                }
            }
        }
    }
       
}

int main(){
    cin >> width >> height >> n;
    for (int i = 0; i<n;  i++){
        int x, y;;
        cin >> x >> y;
        nodes.push_back({y, x});
    }
    for (int y = 0; y<height; y++){
        for (int x = 0; x<width; x++){
            int t;
            cin >> t;
            if (t){
                graph[y][x] = 0;
            }
            else{
                graph[y][x] = 1;
            }
        }       
    }
    pair<int , int> start = nodes.front();
    nodes.pop_front();
    for (int i = 0; i<n-1; i++){
        pair<int , int> end = nodes.front();
        nodes.pop_front();
        length+=BFS(start.first, start.second, end.first, end.second);
        start = end;
    }
    cout << length << "\n";
    return 0;
}
