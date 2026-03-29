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

string graph[3005];
bool dp[3005][3005];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    

    int n;
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> graph[i];
    }

    string ans = "";
    ans+=graph[0][0];
    dp[0][0] = 1;

    for (int step = 0; step<2*n-2; step++){
        char mini = 'Z' + 1;
        for (int i = 0; i<=step; i++){
            int j = step-i;
            if (i<n && j <n && dp[i][j]){
                mini = min(mini, (char)dp[i][j]);;;;
            }
        }

        ans+=mini;
    
        for(int i = 0; i<=step; i++){
            int j = step-i;
        }
    }
}   



