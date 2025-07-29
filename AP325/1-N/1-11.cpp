# include <bits/stdc++.h>
using namespace std;

int width, height, minimum = (int)1e8;
int inp, graph[15][15];

int slove (int x_left, int x_right, int y_top, int y_bottom, int val){
    if (x_left == x_right){
        minimum = min(minimum, val);
        return 0;
    }
    if (y_top == y_bottom){
        minimum = min(minimum, val);
        return 0;
    }
    int one = 0;
    int temp = 0;
    for (int x = x_left; x <= x_right; x++){
        if (graph[y_top][x]){
            one++;
        }
    }
    temp = min(x_right-x_left+1-one, one);
    slove(x_left, x_right, y_top+1, y_bottom, val+temp);
    one = 0;

    for (int x = x_left; x <= x_right; x++){
        if (graph[y_bottom][x]){
            one++;
        }
    }
    temp = min(x_right-x_left+1-one, one);
    slove(x_left, x_right, y_top, y_bottom-1, val+temp);
    one = 0;

    for (int y = y_top; y <= y_bottom; y++){
        if (graph[y][x_left]){
            one++;
        }
    }
    temp = min(y_bottom-y_top+1-one, one);
    slove(x_left+1, x_right, y_top, y_bottom, val+temp);
    one = 0;

    for (int y = y_top; y <= y_bottom; y++){
        if (graph[y][x_right]){
            one++;
        }
    }
    temp = min(y_bottom-y_top+1-one, one);
    slove(x_left, x_right-1, y_top, y_bottom, val+temp);
    return 0;
}

int main(){
    cin >> height >> width;
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            cin >> graph[y][x];
        }
    }
    slove(0, width-1, 0, height-1, 0);
    cout << minimum << "\n";
    return 0;
}

/*
3 5
0 0 0 1 0
1 0 1 1 1
0 0 0 1 0
*/