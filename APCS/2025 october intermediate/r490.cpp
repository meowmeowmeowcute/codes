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

map<string, int> relate;

bool check(string k){
    int total[2]= {0,0};
    for (int i = 0; i<12; i++){
        total[i%2]+=k[i]-'0';
    }
    int n = (total[0]+3*total[1])%10+k[12]-'0';
    if (n == 10 || n ==0){
        return 1;
    }return 0;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    
    int n;
    cin >> n;
    for (int i = 0; i<n; i++){
        string inp;
        cin >>inp;
        if (check(inp)){
            relate[inp.substr(0,3)]+=1;
        }
    }
    int ans = 0;
    string nam;
    for (auto &[country, cnt] : relate) {
        if (cnt > ans) {
            ans = cnt;
            nam = country;
        }
    }
    cout << nam << ' ' << ans;

};   