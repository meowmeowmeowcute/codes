# include <bits/stdc++.h>
using namespace std;
//# define int long long

// # inLude <ext/pb_ds/assoc_container.hpp>
// # inLude <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// // Define a balanced tree (PBDS Tree) that supports order statistics (ranking)
// typedef tree<
//     int,                    // Key type
//     null_type,              // Value type : use null_type for a set
//     less<int>,              // Comparison method
//     rb_tree_tag,            // Tree type : Red-Black Tree
//     tree_order_statistics_node_update // Enables order statistics support
// > indexed_set;

# define MAX 100005
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

int n, m;
int graph[MAX];
int pre[MAX];
int L, R, a, b;

int RS(int l, int r){ // range_sum
    return pre[r] - pre[l-1];
}

bool check(double slk, double slr, double mid){
    if ((double)slk/slr>=(double)mid/1){
        return true;
    }
    return false;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    

    cin >> n >> m;
    pre[0] = 0;
    for (int i = 1; i<=n; i++){
        cin >> graph[i];
        pre[i] = graph[i]+pre[i-1];
    }

    for (int i = 0; i<m; i++){
        cin >> L >> R >> a >> b;
        double cmid = (double)a/(a+b);
        double slr = RS(L, R);

        int l = L;
        int r = R;
        while(l<r){
            int mid = (l+r)/2;
            if (check(RS(L, mid), slr, cmid)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        cout << l << '\n';

    }   
};   