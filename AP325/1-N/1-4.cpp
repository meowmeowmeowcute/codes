# include <bits/stdc++.h>
# define ll long long
using namespace std;

int n, level, graph[50010];//level == limit
ll pre_mix = 0;
vector<ll> pre_mixs;
bool debug = false;

void print(string val_name, ll val, bool debug){
    if (debug) cout << val_name << val << "\n";
}

ll abss(ll x){
    if(x < 0) return -x;
    return x;
}

ll cut(ll l, ll r, ll depth){
    
    print("l: ", l, debug);
    print("r: ", r, debug);
    print("depth: ", depth, debug);

    if (r - l < 2) return 0;
    if (depth == level) return 0;
    ll min = LLONG_MAX;
    ll min_idx = -1;
    ll tmp = -1;
    ll left = 0;
    ll right = 0;
    for (ll i = l+1; i<=r; i++){
        right += 1LL*graph[i]*(i-l);
    }

    print("left: ", left, debug);
    print("right: ", right, debug);
    
    for (ll i = l+1; i<r; i++){
        if(l-1>=0) left += pre_mixs[i-1]-pre_mixs[l-1];
        else left += pre_mixs[i-1];
        right -= pre_mixs[r]-pre_mixs[i-1];
        print("left: ", left, debug);
        print("right: ", right, debug);
        tmp = abss(right-left);
        if (tmp<min){
            min = tmp;
            min_idx = i;

            print("min: ", min, debug);
            print("min_idx: ", min_idx, debug);

        }
    }

    ll total = graph[min_idx] + cut(l, min_idx-1, depth+1) + cut(min_idx+1, r, depth+1);
    return total;
}

int main(){
    cin >> n >> level;
    for(ll i = 0; i <n; i++){
        cin >> graph[i];
        pre_mix+=graph[i];
        pre_mixs.push_back(pre_mix);
    }

    ll ans = cut(0, n-1, 0);
    cout << ans;
    
}