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

string a, b;
int dp[20][10][2];
void dfs(int id, int last_dight, bool is_limit, bool is_leadzero){
    int limit = a[id];
    if(is_limit){
        for (int i = 0; i<=limit; i++){
            bool nxt_limit = 0;
            bool nxt_zero = 0;
            if (is_limit && i == limit)nxt_limit = 1;
            if (is_leadzero && i == 0)nxt_zero = 1;
            if (i != last_dight){
                dfs(id+1, i, nxt_limit, nxt_zero);
            } 
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    

}   



