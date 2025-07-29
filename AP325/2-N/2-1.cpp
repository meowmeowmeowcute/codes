# include <bits/stdc++.h>
using namespace std;

int main(){
    int n, inp;
    cin >> n;
    set<int> graph;
    for (int i = 0; i<n; i++){
        cin >> inp;
        graph.insert(inp);
    }
    cout<< graph.size() << "\n";
    for(auto i : graph){
        cout << i << ' ';
    }
    return 0;
}