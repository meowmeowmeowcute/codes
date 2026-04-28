# include <bits/stdc++.h>
# define int long long

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

struct BIT{

    int n;
    vi tree;

    BIT(int n){
        this->n = n;
        tree.assign(n+1, 0);
    }

    //pre_sum
    int query(int id){
        int sum = 0;
        for (; id>0; id-=(id & -id)){
            sum+=tree[id];
            if (sum>=mod){
                sum-=mod;
            }
        }
        return sum;
    }

    void update(int id, int val){
        for (; id<=n;id+=(id & -id)){
            tree[id] += val;
            if (tree[id]>=mod){
                tree[id]-=mod;
            }
        }
    }

};


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    
    
    int n;
    cin >> n;
    vi graph(n);
    vi graph_sort(n);
    for (int i = 0; i<n; i++){
        cin >> graph[i];
        graph_sort[i] = graph[i];
    }

    sort(graph_sort.begin(), graph_sort.end());
    graph_sort.erase(unique(graph_sort.begin(), graph_sort.end()), graph_sort.end());
    int BIT_n = graph_sort.size()+1;
    BIT bit(BIT_n);

    int ans = 0;
    for (int i = 0; i<n; i++){
        int rank = lower_bound(graph_sort.begin(), graph_sort.end(), graph[i])-graph_sort.begin()+1;
        int cur_ways = bit.query(rank-1)+1; // self can be a subsequence
        if (cur_ways>=mod){
            cur_ways-=mod;
        }
        bit.update(rank, cur_ways);
        ans+=cur_ways;
        if(ans>=mod){
            ans-=mod;
        }
    }
    cout << ans;




}   



