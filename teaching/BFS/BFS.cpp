#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    // 建立圖 (0~6 共 7 個節點)
    vector<vector<int>> graph(7);

    // 建立連線
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 5, 6};
    graph[3] = {1};
    graph[4] = {1};
    graph[5] = {2};
    graph[6] = {2};

    /*
          0
        /   \
       1     2
      / \   / \
     3   4 5   6
    */

    // 紀錄是否拜訪過
    vector<bool> visited(7, false);

    // BFS 使用 Queue
    queue<int> q;

    // 起點
    int start = 0;

    q.push(start);
    visited[start] = true;

    cout << "BFS 搜尋順序：" << endl;

    while (!q.empty())
    {
        // 取出隊伍最前面的節點
        int current = q.front();
        q.pop();

        cout << current << " ";

        // 查看所有相鄰節點
        for (int next : graph[current])
        {
            // 沒拜訪過才加入 Queue
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return 0;
}