# include <bits/stdc++.h>
//# define int long long

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

int dp[505][505];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    

    memset(dp, 0x3f, sizeof(dp));
    int n, m;
    cin >> n>> m;

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            if (i == j){
                dp[i][j] = 0;
                continue;
            }
            if (dp[i][j]!=INF){
                continue;
            }
            for (int k = 1; k<=i/2; k++){
                int v = 1 +dp[k][j]+dp[i-k][j];
                dp[i][j] = mi(v, dp[i][j]);
            }
            for (int k = 1; k<=j/2; k++){
                int v = 1 +dp[i][k]+dp[i][j-k];
                dp[i][j] = mi(v, dp[i][j]);
            }
            dp[j][i] = dp[i][j];
        }
    }
    cout << dp[n][m];
}   





