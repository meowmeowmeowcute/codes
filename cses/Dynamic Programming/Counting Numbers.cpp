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

int a, b;
string goal;
int dp[20][10];

int dfs(int id, int last_dight, bool is_limit, bool is_leadzero){
    
    if(id == goal.size()) return 1;  

    int ans = 0;
    int limit = is_limit ? goal[id]-'0' : 9;    
    
    
    if(!is_limit && !is_leadzero && dp[id][last_dight]!=-1)
        return dp[id][last_dight];   

    for (int i = 0; i<=limit; i++)
        if (i != last_dight || is_leadzero){
            bool nxt_limit = (is_limit && i == limit);
            bool nxt_zero = (is_leadzero && i == 0);        
            ans+=dfs(id+1, i, nxt_limit, nxt_zero);
        }         

    if(!is_limit && !is_leadzero) dp[id][last_dight] = ans;

    return ans;
}

int slove(int n){
    if (n<0) return 0;
    goal = to_string(n);
    memset(dp, -1, sizeof(dp));
    return dfs(0, -1, 1, 1);
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    


    cin >> a >> b;
    cout << slove(b)-slove(a-1);


}   



