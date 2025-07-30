# include <bits/stdc++.h>
# define int long long 
# define MAX 200005
using namespace std ;

# define pii pair<int, int> 
stack<pii> graph;
int ans = 0;
int n, inp;
int a[MAX], b[MAX];
signed main(){
    cin >> n;
    for (int i = 0; i<n; i++) cin>> a[i];
    for (int i = 0; i<n; i++) cin>> b[i];
    for (int i = 0; i<n; i++) a[i]+=b[i];
    for (int i = 0; i<n ;i++){
        if (!graph.empty()){
                while(!graph.empty() and graph.top().first<=a[i]){
                    graph.pop();
                }
        }
        if (!graph.empty()){
            ans+=i-graph.top().second;
        }
        else{
            ans+=i;
        }
        graph.push({a[i], i});
    }
    cout << ans << "\n";
}