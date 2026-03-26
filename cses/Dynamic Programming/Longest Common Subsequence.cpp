# include <bits/stdc++.h>
//# define int long long

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

int dp[1005][1005];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    
    
    int a[1001];
    int b[1001];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i<=n; i++){
        cin >> a[i];
    }
    for (int j = 1; j<=m; j++){
        cin >> b[j];
    }

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            if (a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = ma(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m];
    vi lcs;
    while(m>0 and n>0){
        if(a[n]==b[m]){
            lcs.pb(a[n]);
            n-=1;m-=1;
        }else{
            if(dp[n-1][m]>=dp[n][m]){
                n-=1;
            }else{
                m-=1;
            }
        }
    }

    cout << "\n";
    int l = lcs.size();
    for (int i = l-1; i>=0; i--){
        cout << lcs[i] << ' ';
    }

    
    



}   



