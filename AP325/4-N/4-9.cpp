# include <bits/stdc++.h>
using namespace std;

# define MAX 500004
# define inf 10000000000
# define int long long 

int n, k, graph[MAX], ans = 0;

bool check(int r){
    int cur = graph[0]+r, total = 1;
    for (int i= 0; i<n; i++){
        if (graph[i]>cur){
            cur = graph[i]+r;
            total++;
        }
    }
    return total<=k;
}

signed main(){
    cin >> n >> k;
    for (int i = 0; i<n; i++){
        cin >> graph[i];
    }
    sort(graph, graph+n);
    int l = graph[0], r = graph[n-1];
    while(l<r){
        int mid = (l+r)/2;
        if (check(mid)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    cout << l << "\n";

    




}

