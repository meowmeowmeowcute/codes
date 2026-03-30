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

int dp[63000];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    

    int n;
    cin >> n;
    int total = (1+n)*n/2;
    if(total%2!=0){
        cout << '0';
        return 0;
    }

    dp[0] = 1;

    for (int i = 1; i<n; i++){
        for (int j = total/2; j>=0; j--){
            if (j>=i){
                dp[j] = dp[j-i]+dp[j];
                if (dp[j]>=mod)dp[j]-=mod;
            }else{
                dp[j] = dp[j];
            }
        }
    }
    cout << dp[total/2];

}   



