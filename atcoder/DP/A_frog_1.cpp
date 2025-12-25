# include <bits/stdc++.h>
# define mi(a, b) ((a)<(b)?(a):(b))
# define ma(a, b) ((a)>(b)?(a):(b))
# define ab(a) ((a)>=0?(a):-1*(a))
# define int long long
# define MAX 100005
# define err(a) cerr << #a << " : " << a << '\n'
# define inf 10000000000
# define pii pair<int, int>
# define vi vector<int>
# define vpii vector<pii>
# define ff first
# define ss second
# define T true
# define F false
# define ent << "\n"
# define RMN(M, N) for(int i = M; i<=N; i++)
# define RNT(N) for (int i = 0; i<N; i++)
# define set_M() int M = (L+R)/2
# define li 2*id
# define ri 2*id+1
using namespace std;
int n, a[MAX], dp[MAX];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i<=n; i++){
        cin >> a[i];
    }
    dp[1] = 0;
    dp[2] = a[2]-a[1];
    dp[2] = ab(dp[2]);
    for (int i = 3; i<=n; i++){
        int one = a[i]-a[i-1];
        int two = a[i]-a[i-2];
        dp[i] = mi(dp[i-2]+ab(two), dp[i-1]+ab(one));
    }
    /*
    RMN(1, n){
        cout << dp[i];
    }cout << '\n';
    */
    cout << dp[n];
}

