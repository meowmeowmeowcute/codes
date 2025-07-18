# include <bits/stdc++.h>
# define int long long

# define MAX 100005
# define inf 100000000000000000
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
#define elif else if

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


int n, k, l, total = 0, inv[1000005], pre[1000005];
vi a;
int pow_long(int x, int y, int p){
    if (y == 0) return 1;
    if (y & 1) return (pow_long(x, y-1, p)*x)%p;
    int pow_n = pow_long(x, y/2, p);
    return (pow_n*pow_n)%p;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    pre[0] = 1;
    cin >> n;
    a.resize(n+1);
    string useless;
    FN(n){
        cin >> useless >> a[_];
        total+=a[_];
    }
    FN(total){
        pre[_] = pre[_-1]*_;
        pre[_]%=mod;
        inv[_] = pow_long(pre[_], mod-2, mod);
    }
    inv[0] = 1;
/*
    FN(total){
        outs(inv[_]);
    }nl;
*/
    int ans = pre[total];
//    outl(ans);
    FN(n){
        ans*= inv[a[_]];
        ans%=mod;
    }
    outl(ans);
}   

/*
5
1 1
2 1
3 3
4 1
5 1

*/