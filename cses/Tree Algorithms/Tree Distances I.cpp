# include <bits/stdc++.h>
# define int long long

# define MAX 200005
# define inf 10000000000
# define mod 1000000007

# define pii pair<int, int>
# define vi vector<int>
# define vpii vector<pii>

#define pb(...) push_back(__VA_ARGS__)
#define bg(i) i.begin()
#define ed(i) i.end()
#define all(i) bg(i),ed(i)

# define ff first
# define ss second

#define __overload_for__(i,j,k,l,m,...) m
#define FN_(i) FNN(_, i)
#define FNN(i,j) for(int i = 1;i<=j;i++)
#define FNNM(i,j,k) for(int i = j;i<=k;i++)
#define FNNMQ(i, j, k, l) for (int i = j; i<=k; i=i+l)
#define FN(...) __overload_for__(__VA_ARGS__,FNNMQ,FNNM,FNN, FN_)(__VA_ARGS__)
#define FNAT(i,j) for(auto i : j)

#define nl cout<<"\n"
#define out(i) cout<<(i)
#define outs(i) cout<<(i)<<" "
#define outl(i) cout<<(i)<<"\n"
#define errl cerr << '_'*10;

# define set_M() int M = (L+R)/2
# define li 2*id
# define ri 2*id+1

using namespace std;

template<typename T>
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

//better io
#ifdef cin
template<class T>
__fast_read& operator>>(__fast_read& fin,vector<T>&f) {
    for(auto &&i : f) fin>>i;
    return fin;
}
template<class T,class R>
__fast_read& operator>>(__fast_read& fin,pair<T,R>&x) {
    fin>>x.first>>x.second;
    return fin;
}
#else
template<class T>
std::istream& operator>>(std::istream& fin,std::vector<T>&f) {
    for(auto &&i : f) fin>>i;
    return fin;
}
template<class T,class R>
std::istream& operator>>(std::istream& fin,std::pair<T,R>&x) {
    fin>>x.first>>x.second;
    return fin;
}
#endif
template<class T>
std::ostream& operator<<(std::ostream& fout,std::vector<T>&f) {
    for(auto &i : f) fout<<i<<" ";
    return fout;
}
template<class T,class R>
std::ostream& operator<<(std::ostream& fout,std::pair<T,R>&x) {
    fout<<x.first<<" "<<x.second;
    return fout;
}

int n, a, b;
vpii mxvid(3, {0, 0});
int dist[3][MAX];
vi graph[MAX];

void bfs(int start, pii &vid, int id){
    vi vis(n+1, 0);
    queue<int> q;
    dist[id][start] = 0;
    q.push(start);
    vis[start] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        FNAT(i , graph[cur]){
            if(vis[i] == 0){
                vis[i] = 1;
                dist[id][i] = dist[id][cur]+1;
                if(dist[id][i]>vid.ff) vid = {dist[id][i], i};
                q.push(i);
            }
        }
    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    FN(i, n-1){
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    bfs(1, mxvid[0], 0);
    bfs(mxvid[0].ss, mxvid[1], 1);
    bfs(mxvid[1].ss, mxvid[2], 2);
    FN(n){
        outs(ma(dist[1][_], dist[2][_]));
    }
}



