# include <bits/stdc++.h>
# define ll long long
using namespace std;

ll n, m, k, inp, ans = 0, idx;
ll arr[100010];

int main(){
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for (ll i = 0; i < m; i++){
        cin >> inp;
        idx = lower_bound(arr, arr+n, k-inp)-arr;
        if (idx!=n && arr[idx] == k-inp){
            ans++;
        }
    }
    cout << ans;
    return 0;
}