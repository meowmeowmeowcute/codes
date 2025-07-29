# include <bits/stdc++.h>
using namespace std;

int main(){
    int n, inp;
    cin >> n;
    set<int> graph;
    vector<int> vec;
    map<int, int> ma;
    for (int i = 0; i<n; i++){
        cin >> inp;
        graph.insert(inp);
        vec.push_back(inp);
    }
    int k = 0;
    for(auto i : graph){
        ma[i] = k;
        k++;
    }
    for(auto i : vec){
        cout<< ma[i] << ' ';
    }
    return 0;
}