# include <bits/stdc++.h>
using namespace std;
//# define int long long

// # include <ext/pb_ds/assoc_container.hpp>
// # include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// // 定義一個支援「排名」功能的平衡樹(set)(PBDS Tree）
// typedef tree<
//     int,                    // 鍵的型別 (Key)
//     null_type,              // 值的情別 (若是 set 則填 null_type)
//     less<int>,              // 排序方式
//     rb_tree_tag,            // 樹的種類 (紅黑樹)
//     tree_order_statistics_node_update // 讓此tree支援排名功能
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

auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    
    
    int n;
    cin >> n;
    vpii graph;
    map<pii, int> id;
    vi ans(MAX);

    for (int i = 0; i<n; i++){
        int a, b;
        cin >> a >> b;
        id[{a, b}] = i;
        graph.pb({a, b});
    }

    sort(graph.begin(), graph.end(), cmp);

    int min_b = INF;
    for (int i = n-1; i>=0; i--){
        if (graph[i].ss>=min_b)ans[id[graph[i]]] = 1;
        else ans[id[graph[i]]] = 0;
        min_b = min(min_b, graph[i].ss);
    }

    for (int i = 0; i<n;i++){
        cout << ans[i] << ' ';
    }

    int max_b = 0;
    for (int i = 0;i<n; i++){
        if (graph[i].ss<=max_b)ans[id[graph[i]]] = 1;
        else ans[id[graph[i]]] = 0;
        max_b = max(max_b, graph[i].ss);
        
    }

    cout << "\n";
    for (int i = 0; i<n;i++){
        cout << ans[i] << ' ';
    }
}   