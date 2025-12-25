# include <bits/stdc++.h>
using namespace std;

int m, n, k, inp;
char graph[50][50];
string answer = "";
int dy[6] = {-1, 0, 1, 1, 0, -1};
int dx[6] = {0, 1, 1, 0, -1, -1};
set<char> answers;
int main(){ 
    cin >> m >> n >> k;
    int yn = m, xn = 1;
    for (int y = 0; y < m+2; y++)
        for (int x = 0; x < n+2; x++)
            if (x == 0 || x == n+1 || y == 0 || y == m+1)
                {graph[y][x] = '?';}
            else 
                {cin >> graph[y][x];}
                
    while(k--){
        cin >> inp;
        if(graph[yn+dy[inp]][xn+dx[inp]] != '?'){
            yn += dy[inp];
            xn += dx[inp];
        }
        answer += graph[yn][xn];
        answers.insert(graph[yn][xn]);
    }       
    cout << answer << "\n";
    cout << answers.size() << "\n";

    return 0;
}


