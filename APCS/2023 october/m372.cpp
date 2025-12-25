#include <bits/stdc++.h>
#define MAX 500
using namespace std;

map<char, vector<int>> dir = {
	// up right bottom left
	{
		'X', {1, 1, 1, 1}
	},
	{
		'I', {1, 0, 1, 0}
	},
	{
		'H', {0, 1, 0, 1}
	},
	{
		'L', {1, 1, 0, 0}
	},
	{
		'7', {0, 0, 1, 1}
	},
	{
		'F', {0, 1, 1, 0}
	},
	{
		'J', {1, 0, 0, 1}
	}
};
int dir_y[4] = {-1, 0, 1, 0};
int dir_x[4] = {0, 1, 0, -1};
char graph[MAX+5][MAX+5];
int height, width, maximum = 0, visited[MAX+5][MAX+5], id = 1, idx[(MAX+5)*(MAX+5)];

void bfs(int ny, int nx){
	int y = ny;
	int x = nx;
	idx[id]++;
	visited[y][x] = 1;
	queue<pair<int, int>> path;
	path.push({y, x});
	while(!path.empty()){
		pair<int, int> top = path.front();
		y = top.first;
		x = top.second;
		path.pop();
		char cur = graph[y][x];
		for (int i = 0; i<4; i++){
			char goal = graph[y+dir_y[i]][x+dir_x[i]];
			if(cur!='0'&&goal!='0'&&!visited[y+dir_y[i]][x+dir_x[i]]){
				if(dir[cur][i] && dir[goal][(i+2)%4]){
					visited[y+dir_y[i]][x+dir_x[i]] = 1;
					path.push({y+dir_y[i], x+dir_x[i]});
					idx[id]++;
				}
			}
		}
	}
	maximum = max(maximum, idx[id]);
}

int main(){
	memset(graph, '0', sizeof(graph));
	cin >> height >> width;
	for(int y = 1; y<=height; y++){
		for(int x = 1; x<=width; x++){
			cin >> graph[y][x];
		}
	}
	for(int y = 1; y<=height; y++){
		for(int x = 1; x<=width; x++){
			if (graph[y][x] != '0' && !visited[y][x]){
				bfs(y, x);
				id++;
			}
		}
	}
	cout << maximum;
	return 0;
}

/*
#include <bits/stdc++.h>
#define MAX 500
using namespace std;

map<char, vector<int>> dir = {
    {'X', {1, 1, 1, 1}},
    {'I', {1, 0, 1, 0}},
    {'H', {0, 1, 0, 1}},
    {'L', {1, 1, 0, 0}},
    {'7', {0, 0, 1, 1}},
    {'F', {0, 1, 1, 0}},
    {'J', {1, 0, 0, 1}}
};

int dir_y[4] = {-1, 0, 1, 0};
int dir_x[4] = {0, 1, 0, -1};
char graph[MAX+5][MAX+5];
int height, width, maximum = 0, visited[MAX+5][MAX+5], id = 1, idx[(MAX+5)*(MAX+5)];

void bfs(int sy, int sx){
    cerr << "開始 BFS #" << id << "，起點: (" << sy << "," << sx << ") = " << graph[sy][sx] << "\n";
    idx[id]++;
    visited[sy][sx] = 1;
    queue<pair<int, int>> path;
    path.push({sy, sx});
    while (!path.empty()){
        auto [y, x] = path.front();
        path.pop();
        char cur = graph[y][x];
        cerr << "  處理 (" << y << "," << x << ") = " << cur << "\n";

        for (int i = 0; i < 4; i++){
            int ny = y + dir_y[i];
            int nx = x + dir_x[i];

            if (ny < 1 || ny > height || nx < 1 || nx > width) continue; // 邊界保護

            char goal = graph[ny][nx];
            if (goal != '0' && !visited[ny][nx] && dir[cur][i] && dir[goal][(i+2)%4]){
                visited[ny][nx] = 1;
                path.push({ny, nx});
                idx[id]++;
                cerr << "    -> 擴展到 (" << ny << "," << nx << ") = " << goal << "\n";
            }
        }
    }
    maximum = max(maximum, idx[id]);
}

int main(){
    memset(graph, '0', sizeof(graph));
    cin >> height >> width;
    for (int y = 1; y <= height; y++) {
        for (int x = 1; x <= width; x++) {
            cin >> graph[y][x];
        }
    }

    cerr << "地圖如下：\n";
    for (int y = 1; y <= height; y++) {
        for (int x = 1; x <= width; x++) {
            cerr << graph[y][x];
        }
        cerr << '\n';
    }

    for (int y = 1; y <= height; y++) {
        for (int x = 1; x <= width; x++) {
            if (graph[y][x] != '0' && !visited[y][x]) {
                bfs(y, x);
                id++;
            }
        }
    }

    cout << maximum << '\n';
}
*/