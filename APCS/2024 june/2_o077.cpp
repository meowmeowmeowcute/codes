#include <bits/stdc++.h>
using namespace std;

bool in_area(int y, int x, int lis_y, int lis_x)
{
    if (y >= 0 && y <= lis_y && x >= 0 && x <= lis_x)
    {
        return true;
    }
    return false;
}

int manhattan_distance(int y, int x, int target_y, int target_x)
{
    // return manhattan_distance
    return abs(y - target_y) + abs(x - target_x);
}

const int max_pos = 100; // adjust this value based on the input sizet max_pos = 25;  // adjust this value based on the input size
int graph[max_pos][max_pos] = {};
int main()
{
    int H, W, N, y, x, t, c;
    cin >> H >> W >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> y >> x >> t >> c;
        for (int iy = 0; iy < H; iy++)
        {
            for (int ix = 0; ix < W; ix++)
            {
                if (in_area(iy, ix, H, W))
                {
                    if (manhattan_distance(iy, ix, y, x) <= t)
                    {
                        graph[iy][ix] += c;
                    }
                }
            }
        }
    }

    for (int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            cout << graph[y][x] << " ";
        }
        cout << endl;
    }
}