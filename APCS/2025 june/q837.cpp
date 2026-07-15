# include <bits/stdc++.h>
using namespace std;
//# define int long long

// # include <ext/pb_ds/assoc_container.hpp>
// # include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// // Define a balanced tree (PBDS Tree) that supports order statistics (ranking)
// typedef tree<
//     int,                    // Key type
//     null_type,              // Value type : use null_type for a set
//     less<int>,              // Comparison method
//     rb_tree_tag,            // Tree type : Red-Black Tree
//     tree_order_statistics_node_update // Enables order statistics support
// > indexed_set;

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
int offset[35];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    
    
    string strs[35];
    int ans = 0;
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 1; i<=m; i++){
        cin >> strs[i];
    }

    for (int i = 1; i<= k; i++){
        for (int j = 1; j<=m; j++){
            int inp;cin >> inp;
            offset[j]=(offset[j]-inp%n+n)%n;
        }
        for (int l = 0; l<n; l++){
            int mx = 0;
            map<char, int> relate;
            for(int j = 1; j<=m; j++){
                relate[strs[j][(offset[j]+l)%n]]+=1;
                mx = max(mx, relate[strs[j][(offset[j]+l)%n]]);
            }
            ans += mx;
        }    
    }
    cout << ans;
};   