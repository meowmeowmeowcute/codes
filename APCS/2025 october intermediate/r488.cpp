# include <bits/stdc++.h>
using namespace std;
# define int long long

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

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    
    
    int length, width, height;
    cin >> length >> width >> height;
    int small = height;
    int graph[length][width];
    for (int i = 0; i<length; i++){
        for (int j = 0; j<width; j++){
            graph[i][j] = height;
        }
    }
    int k, x, y;
    cin >> k;
    int pos[length][width];
    memset(pos, 0, sizeof(pos));
    for (int i = 0; i<k; i++){
        cin >> x >> y;
        pos[x][y] += 1;
    }
    int m, n, v;
    cin >> m;
    for (int i = 0; i<m; i++){
        bool have = 0;
        cin >> x >> y >> n >> v;
        for (int i = x-(n-1)/2; i<x+(n-1)/2+1; i++){
            for (int j = y-(n-1)/2; j<y+(n-1)/2+1; j++){
                if(i>=0 && i<length && j>=0 && j<width && pos[i][j]){
                    have = 1;
                    k-=pos[i][j];
                    pos[i][j] =0;
                }
            }
        }

        if(!have){
            for (int i = x-(n-1)/2; i<x+(n-1)/2+1; i++){
                for (int j = y-(n-1)/2; j<y+(n-1)/2+1; j++){
                    if(i>=0 && i<length && j>=0 && j<width){
                        graph[i][j]-=v;
                        if(graph[i][j]<small){
                            small = graph[i][j];
                        }
                    }
                }
            }
        }
    }
    int big = -INF;
    int total = 0;
    for (int i = 0; i<length; i++){
        for (int j = 0; j<width; j++){
            total+=pos[i][j];
            if (graph[i][j]>big){
                big = graph[i][j];
            }
        }
    }
    
    cout << big << ' ' << small << ' ' << k;
}