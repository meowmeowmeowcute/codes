# include <bits/stdc++.h>
using namespace std;

int n, inp;
vector<int> graph[32768] = {};

int main(){
    while(cin >> n && !cin.eof()){
        int i = 1;
        cin >> inp;
        graph[i].push_back(inp);
    }
}