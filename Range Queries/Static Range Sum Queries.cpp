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
#define FNAT(i,j) for(auto i : j)
#define FNNM(i,j,k) for(int i = j;i<=k;i++)
#define FNNMQ(i, j, k, l) for (int i = j; i<=k; i=i+l)
#define FN(...) __overload_for__(__VA_ARGS__,FNNMQ,FNNM,FNN, FN_)(__VA_ARGS__)

#define nl cout<<"\n"
#define out(i) cout<<(i)
#define outs(i) cout<<(i)<<" "
#define outl(i) cout<<(i)<<"\n"

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

int n, q, k, m, l, a[MAX];
int seg[MAX*4];
void build(int L, int R, int id){
    if(L == R){
        seg[id] = a[L];
        return;
    } 
    set_M();
    build(L, M, li);
    build(M+1, R, ri);
    seg[id] = (seg[li]+seg[ri]);
}

void modify(int x, int v, int L, int R, int id){
    if (L == R){
        seg[id] = v;
        return;
    }
    set_M();
    if (x>=L and x<=M)modify(x, v, L, M, li);
    else modify(x, v, M+1, R, ri);
    seg[id] = (seg[li]+seg[ri]);
}

int query(int l, int r, int L, int R, int id){
    if(l == L and r == R)return seg[id];
    set_M();
    if(r<=M)return query(l, r, L, M, li);
    else if (l>M) return query(l, r, M+1, R, ri);
    else return (query(l, M, L, M, li)+query(M+1, r, M+1, R, ri));
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    FN(n)cin >> a[_];
    build(1, n, 1);
    FN(q){
        cin >> m >> l;
        outl(query(m, l, 1, n, 1));
    }
}   

