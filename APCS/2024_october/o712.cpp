#include <bits/stdc++.h>
#define ll long long 
using namespace std;
/*
-1 -1 -1 -1 -1
-1 -- -- -- -1
-1 -- -- -- -1
-1 -- -- -- -1
-1 -1 -1 -1 -1
*/
int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, 1, 0, -1};
int height, width, k, roboty, robotx, score = 0, dir_id = 1, dimond = 0;
/*
dir_id = 1 dir = right
dir_id = 2 dir = down
dir_id = 3 dir = left
dir_id = 4 dir = up
*/
int graph[105][105];
bool end_check(int roboty, int robotx){
    return graph[roboty+1][robotx+1];
}
void turn(){
    //cout << "turn\n";
    dir_id++;
    if (dir_id-1 == 4){
        dir_id = 1;
    }
}
bool toward_wall(int roboty, int robotx, int dir_id){
    //cout << "wall check\n";
    return (graph[1 + roboty + dir_y[dir_id-1]][1 + robotx + dir_x[dir_id-1]] == -1);
}
void forward(){
    roboty+=dir_y[dir_id-1];
    robotx+=dir_x[dir_id-1];
}
void space(){
    cout << ' ';
}
void print_values(){
    int arr[] = {roboty, robotx, dir_id, graph[roboty+1][robotx+1]};
    for (auto i : arr){
        cout << i;
        space();
    }cout << "\n";
}
int main(){
    //input
    cin >> height >> width >> k >> roboty >> robotx;
    //init
    memset(graph, -1, sizeof graph);
    for (int y = 0; y<height; y++){
        for (int x = 0; x<width; x++){
            cin >> graph[y+1][x+1];
        }
    }
    //loop
    //step1
    while(end_check(roboty, robotx)){
        //print_values();
        //step2
        score+=graph[roboty+1][robotx+1];
        graph[roboty+1][robotx+1]--;
        dimond++;
        //step3
        if (score%k == 0){
            turn();
        }
        //step4
        while(toward_wall(roboty, robotx, dir_id)){
            turn();
        }
        //forward
        forward();
    }
    cout << dimond;
}