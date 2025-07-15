# include <bits/stdc++.h>
# define int long long
# define MAX 100005
# define inf 10000000000
# define mod 1000000007
# define pii pair<int, int>
# define vi vector<int>
# define vpii vector<pii>
# define ff first
# define ss second
# define err(a) cerr << #a << " : " << a << '\n'
# define errs(a) cerr << a << sps
# define ent  "\n"
# define sps  ' '
# define FKN(I,N) for(int I=1;I<=(N);I++)
# define FKNM(I,N,M) for(int I=(N);I<=(M);I++)
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


int n;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
}   

