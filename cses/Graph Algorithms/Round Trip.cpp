# include <bits/stdc++.h>
# define int long long
 
# define MAX 200005
# define inf 100000000000000000
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
 
// # define __overload_for__(i,j,k,l,m,...) m
// # define FN_(i) FNN(_, i)
// # define FNN(i,j) for(int i = 1;i<=j;i++)
// # define FNAT(i,j) for(auto i : j)
// # define FNNM(i,j,k) for(int i = j;i<=k;i++)
// # define FNNMQ(i, j, k, l) for (int i = j; i<=k; i=i+l)
// # define FN(...) __overload_for__(__VA_ARGS__,FNNMQ,FNNM,FNN, FN_)(__VA_ARGS__)
 
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
# ifdef cin
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
# else
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
# endif
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
 
int n, m, a, b;
int father[MAX];
int dis[MAX];
int visited[MAX];
vi graph[MAX];
vi cir;
bool have_cir = 0;
 
void dfs(int p, int fa){
    visited[p] = 1;
    father[p] = fa;
    // cout << p << " ";
    for (auto i:graph[p]){
        if (i == fa)continue;
        if(visited[i] ==1){
            int k = p;
            cir.pb(i);
            while(k!=i && k!=0){
                cir.pb(k);
                k = father[k];
            }
            cir.pb(i);
            have_cir = 1;
            return;
        }
        else if (visited[i]==0 ){
            dfs(i, p);
            if (have_cir)return;
        }
    }    
    visited[p] = 2;
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    
 
    cin >> n >> m;
    for (int i = 0; i<m; i++){
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    for (int i = 1; i<=n; i++){
        if (visited[i] ==0){

            dfs(i, 0);
        }
        if (have_cir){
            break;
        }
        // cout << "\n";
    }
    // cout << "______________\n";
    if (have_cir){
        cout<< cir.size() << "\n";
        for (auto i : cir){
            cout << i << " ";
        }
    }else{
        cout << "IMPOSSIBLE";
    }
 
 
//dfs
}   
 
