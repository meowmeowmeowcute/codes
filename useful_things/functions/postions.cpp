# include <stdc++.h>
using namespace std;

bool in_area(int y, int x, int lis_y, int lis_x){
    if (y>=0 && y<=lis_y && x>=0 && x<=lis_x){
        return true;
    }
    return false;
}

int manhattan_distance(int y, int x, int target_y, int target_x){
    //return manhattan_distance
    return abs(y-target_y) + abs(x-target_x);
}   