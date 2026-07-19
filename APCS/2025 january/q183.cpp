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

int n, mxm = 0;
multiset<int> dists;
vi dfs_stack;
vi maximum;
vi minimum;

void update();
void dfs();
void try_point(int);

void update(){
    if (dfs_stack.size() == n){
        vi ans = dfs_stack;
        sort(all(ans));
        if(!maximum.size())maximum = ans;
        if(!minimum.size())minimum = ans;
        maximum = max(maximum, ans);
        minimum = min(minimum, ans);
    }
    return;
}

void dfs(){
    update();
    if(dfs_stack.size() == n)return;
    if(dists.empty())return;
    int left = mxm-*dists.rbegin();
    try_point(left);
    int right = *dists.rbegin();
    if (right != left) try_point(right);
}

void try_point(int point){
    multiset<int>used_dist;
    for (auto p : dfs_stack){
        int need = ab(point-p);
        auto it = dists.find(need);
        if(it==ed(dists)){
            used_dist.clear();
            break;
        }else{
            used_dist.insert(*it);
        }
    }
    if (used_dist.size() != 0){
        for(auto i : used_dist){
            auto it = dists.find(i);
            if (it!=dists.end())
                dists.erase(dists.find(i));
        }
        dfs_stack.pb(point);
        dfs();
        for(auto i : used_dist){
            dists.insert(i);
        }
        dfs_stack.pop_back();
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    
    cin >> n;
    if (n == 1){
        cout << 0 << '\n' << 0;
        return 0;
    }
    for (int i = 0; i<n*(n-1)/2; i++){
        int inp; cin >> inp;
        dists.insert(inp);
    }
    mxm = *dists.rbegin();
    dfs_stack.pb(0);
    dfs_stack.pb(*dists.rbegin());
    dists.erase(prev(dists.end()));

    dfs();
    for(auto i : minimum) cout << i << ' ';
    cout << '\n';
    for(auto i : maximum) cout << i << ' ';


};   