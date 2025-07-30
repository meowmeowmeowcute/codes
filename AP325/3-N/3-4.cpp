# include <bits/stdc++.h>
# define int long long 
using namespace std ;

# define pii pair<int, int> 
stack<pii> graph;
int ans = 0;
int n, inp;

signed main(){
    cin >> n;
    for (int i = 0; i<n ;i++){
        cin >> inp;
        if (!graph.empty()){
                while(!graph.empty() and graph.top().first<=inp){
                    graph.pop();
                }
        }
        if (!graph.empty()){
            ans+=i-graph.top().second;
        }
        else{
            ans+=i+1;
        }
        graph.push({inp, i});
    }
    cout << ans << "\n";
}