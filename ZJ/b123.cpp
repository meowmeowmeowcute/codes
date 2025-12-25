# include <bits/stdc++.h>
using namespace std;

int graph[205][205] = {};
int h, w;

int main() {
    cin >> h >> w;
    for (int y = 0; y<h; y++) {
        for (int x = 0; x<w; x++) {
            cin >> graph[y][x];
        }
    }
}