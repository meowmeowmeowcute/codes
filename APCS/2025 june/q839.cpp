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
# define all(i) (bg(i),ed(i))

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

int graph[505][505];
int parent[505];
int groups = 0;
int n, k, maximum = 0, minimum = INF;

int find(int x){
    if (parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        parent[a] = b;
        groups-=1;
    } 
}

bool check(int v){
    for (int i = 1; i<=n; i++){
        parent[i] = i;
    }
    groups = n;
    for (int y = 0; y<n; y++){
        for (int x = 0; x<y; x++){
            if (graph[y][x]<v){
                unite(y+1, x+1);
            }
        }
    }
    if (groups>=k){
        return true;
    }
    return false;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    

    cin >> n >> k;
    for (int y = 0; y<n; y++){
        for (int x = 0; x<n; x++){
            cin >> graph[y][x];
            maximum = max(maximum, graph[y][x]);
            minimum = min(minimum, graph[y][x]);
        }
    }

    int l = minimum;
    int r = maximum;
    while(l<r){
        int mid = (l+r+1)/2;
        if(check(mid)){
            l = mid;
        }else{
            r = mid-1;
        }
    }
    cout << l;
};   