# include<bits/stdc++.h>
using namespace std;

int n, k, inp;
priority_queue<int, vector<int >, greater<int>> graph;

int main(){
    cin >> n >> k;
    for (int i = 0; i<k; i++){
        graph.push(0);
    }
    for (int i = 0; i<n; i++){
        cin >> inp;
        int cur = graph.top();
        cur+=inp;
        graph.pop();
        graph.push(cur);
    }
    int ans;
    while(!graph.empty()){
        ans = graph.top();
        // cout << ans << "\n";
        graph.pop();
    }
    cout << ans;
}