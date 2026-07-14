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

int n, m, r, k, t, cnt = 0;
bool run = true;
vector<int> ans;
vector<int> class_cnt(17, 0);
//use global array and use backtracking

int skill[75];

void dfs(int id,int mask){
    if (!run)return;
    if (ans.size() == k){
        cnt +=1;
        if(cnt == t){
            for (auto i : ans){
                cout<< i << ' ';
            }
            run = false;
        }
        return;
    }

    for (int i = id; i<=m*r; i++){
        if (mask&(1<<(skill[i]-1))){
            continue;
        }
        if (class_cnt[(i-1)/r]>=2){
            continue;
        }
        
        ans.pb(i);
        class_cnt[(i-1)/r]+=1;

        dfs(i+1, mask|1<<(skill[i]-1));

        ans.pop_back();
        class_cnt[(i-1)/r]-=1;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 
    
    cin >> n >> m >> r >> k >> t;
    for(int i = 1; i<=m*r; i++){
        cin >> skill[i];
    }

    dfs(1, 0);
};   