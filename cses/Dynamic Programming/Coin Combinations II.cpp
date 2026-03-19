# include <bits/stdc++.h>
# define int long long
 
# define MAX 200005
# define inf 1000000000
# define mod 1000000007
 
# define pii pair<int, int>
# define vi vector<int>
# define vpii vector<pii>
 
# define pb(...) push_back(__VA_ARGS__)
# define bg(i) i.begin()
# define ed(i) i.end()
# define all(i) bg(i),ed(i)
 
# define ff first
# define ss second
 
 
# define nl cout<<"\n"
# define out(i) cout<<(i)
# define outs(i) cout<<(i)<<" "
# define outl(i) cout<<(i)<<"\n"
# define elif else if
 
# define set_M() int M = (L+R)/2
# define li 2*id
# define ri 2*id+1
 
using namespace std;
 
inline int ab(int x) {
    return x >= 0 ? x : -x;
}
template<typename T>
inline T mi(T a, T b) {
    return a < b ? a : b;
}
template<typename T>
inline T ma(T a, T b) {
    return a > b ? a : b;
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    
 
    int n, x;
    cin >> n >> x;
    vi values(n);
    vi dp(x+5, 0);
    dp[0] = 1;
    for (int i = 0; i<n; i++){
        cin >> values[i];
    }
 
    for (int j = 0; j<n; j++){
        for(int i= 1; i<=x; i++){
            int v = values[j];
            if(i>=v){
                dp[i] += dp[i-v];
                while(dp[i]>=mod){
                    dp[i]-=mod;
                }
            }
        }
    }
    cout << dp[x];

    // cout << "\n--------\n";
    // for (int i =0; i<x; i++){
    //     cout << dp[i] << " ";
    // }
}   
 
 
