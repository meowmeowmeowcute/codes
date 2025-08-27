# include<bits/stdc++.h>
using namespace std;
# define MAX 100005
# define int long long
# define vpii vector<pair<int, int>>

vpii graph;
int n, cur = 0, times[MAX], cost[MAX], ans;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first*b.second<b.first*a.second;
}

signed main(){
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> times[i];
    }
    for (int i = 0; i<n; i++){
        cin >> cost[i];
    }
    for (int i = 0; i<n; i++){
        graph.push_back({times[i], cost[i]});
    }
    sort(graph.begin(), graph.end(), cmp);
    for(auto i : graph){
        ans+=(cur+i.first)*i.second;
        cur+=i.first;
    }
    
    cout << ans;
}