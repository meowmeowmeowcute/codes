# include <bits/stdc++.h>
# define ll long long
using namespace std;

ll n, p, inp, graph[50], mid, gap = 0, mod, idx;
vector<ll> graph_mult_a, graph_mult_b;
void slove(ll idx_crr, ll idx_max, ll inp, ll p){
    if (idx_crr>=idx_max){
        if (inp < p){
            (idx_max == n ? graph_mult_b : graph_mult_a).push_back(inp);
            gap = min(gap, p-inp);
        }
        return;
    }
    if (inp < p) slove(idx_crr+1, idx_max, inp+graph[idx_crr], p);
    slove(idx_crr+1, idx_max, inp, p);
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> p;
    gap = p;
    if (n == 1){    
        cin >> inp;
        cout << inp;
        return 0;
    }
    else{
        for (int i=0; i<n; i++){
            cin >> inp;
            graph[i] = inp;
        }
    }
    mid = n/2;
    slove(0, mid, 0, p);
    slove(mid, n, 0, p);
    sort(graph_mult_b.begin(), graph_mult_b.end());
    for(ll a : graph_mult_a){
        auto itr = upper_bound(graph_mult_b.begin(), graph_mult_b.end(), p-a)-graph_mult_b.begin()-1;
        if (itr>=0){
            gap = min(gap, p-(a+graph_mult_b[itr]));
        }
    }
    cout << p-gap;
    return 0;
}