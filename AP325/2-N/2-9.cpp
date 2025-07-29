# include <bits/stdc++.h>
# define ll long long
using namespace std;

ll n, p, inp, graph[50], mid, total = 0, mod, idx;
vector<ll> graph_mult_a, graph_mult_b;
map<ll, ll> appeared;
void slove(ll idx_crr, ll idx_max, ll inp, ll p){
    if (idx_crr>=idx_max){
        if (inp){
            (idx_max == n ? graph_mult_b : graph_mult_a).push_back(inp);
            if(inp == 1) total++;
        }
        return;
    }
    slove(idx_crr+1, idx_max, (inp ? (inp*graph[idx_crr])%p : (graph[idx_crr])%p), p);//overflow
    slove(idx_crr+1, idx_max, inp, p);
    return;
}

ll pow_long(ll x, ll y, ll p){
    if (y == 0) return 1;
    if (y & 1) return (pow_long(x, y-1, p)*x)%p;
    ll pow_n = pow_long(x, y/2, p);
    return (pow_n*pow_n)%p;
}

int main(){
    cin >> n >> p;
    if (n == 1){
        cin >> inp;
        (inp%p == 1 ? cout << 1 : cout << 0);
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
        auto itr = appeared.find(a);
        if (itr == appeared.end()){
            appeared[a] = 0;
            mod = pow_long(a, p-2, p);
            auto it = lower_bound(graph_mult_b.begin(), graph_mult_b.end(), mod);
            idx = it-graph_mult_b.begin();
            if (it!=graph_mult_b.end() && graph_mult_b[idx] == mod){
                while(idx!=graph_mult_b.size()-1 && graph_mult_b[idx] == mod){
                    appeared[a]++;
                    idx++;
                }
            }
        }
        total += appeared[a];

    }
    cout << total;
    return 0;
}

/*
5 11
1 1 2 6 10
*/