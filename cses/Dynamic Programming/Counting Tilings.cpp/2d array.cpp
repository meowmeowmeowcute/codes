# include <bits/stdc++.h>
# define int long long

# define MAX 200005
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
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

int n, m;
int dp[1005][1024+5];

void dfs(int i, int row, int cur_mask, int nxt_mask){

    if (row == n){
        dp[i+1][nxt_mask] += dp[i][cur_mask];
        if(dp[i+1][nxt_mask]>=mod){
            dp[i+1][nxt_mask]-=mod;
        }
        return;
    }

    if (cur_mask & (1<<row)){
        dfs(i, row+1, cur_mask, nxt_mask);
    }else{
        dfs(i, row+1, cur_mask, (nxt_mask | (1<<row)));
        if (row+1<n && !(cur_mask & (1<<(row+1)))){
            dfs(i, row+2, cur_mask, nxt_mask);
        }
    }
    

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    

    cin>> n >> m;
    dp[0][0] = 1;

    for (int i = 0; i<m; i++){
        for (int mask = 0; mask<=(1<<n)-1; mask++){
            if(dp[i][mask]>0){
                dfs(i, 0, mask, 0);
            }
        }
    }
    cout << dp[m][0];

}       



