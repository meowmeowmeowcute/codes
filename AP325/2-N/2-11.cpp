# include <bits/stdc++.h>
# define ll long long
using namespace std;

ll pre = 0, inp, n, k, ans;
set<ll> pre_set;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    pre_set.insert(0);
    cin >> n >> k;
    for (ll i = 1; i <= n; i++){
        cin >> inp;
        pre+=inp;
        auto it = pre_set.lower_bound(pre-k);
        if(it!=pre_set.end()) ans = max(ans, pre-*it);
        pre_set.insert(pre);
    }
    cout << ans;
}