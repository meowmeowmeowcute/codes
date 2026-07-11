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

int graph_A[205][205];
int graph_B[205][205];

int h, w;
bool same(int type, int i, int j) {
    if (type == 0) return graph_A[i][j] == graph_B[i][j];
    if (type == 1) return graph_A[i][j] == graph_B[j][h-1-i];
    if (type == 2) return graph_A[i][j] == graph_B[h-1-i][w-1-j];
    return graph_A[i][j] == graph_B[w-1-j][i];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    

    cin >> w >> h;
    for (int i = 0; i<h; i++){
        for (int j = 0; j<w; j++){
            cin >> graph_A[i][j];
        }
    }    
    for (int i = 0; i<h; i++){
        for (int j = 0; j<w; j++){
            cin >> graph_B[i][j];
        }
    }

    int cmp =0;
    int results[4] = {0, 0, 0, 0};// 先比較 0°、180°
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            results[0] += same(0, i, j);
            results[2] += same(2, i, j);
        }
    }

    // 只有正方形才能比較 90°、270°
    if (h == w) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                results[1] += same(1, i, j);
                results[3] += same(3, i, j);
            }
        }
    }
    for (int i = 0; i<4; i++){
        cmp = max(cmp, results[i]);
    }
    cout << (cmp*100)/(h*w) << '%';
    


};   