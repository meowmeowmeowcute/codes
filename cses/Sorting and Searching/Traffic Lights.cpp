# include <bits/stdc++.h>
//# define int long long

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

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    

    int l, n;
    cin >> l >> n;
    multiset<int> lights;
    multiset<int> dists;
    lights.insert(0);
    lights.insert(l);
    dists.insert(l);
    for (int i = 0; i<n; i++){
        int light;
        cin >> light;

        auto it = lights.upper_bound(light);
        int ed = *it;
        int bg = *prev(it);
        
        dists.erase(dists.find(ed-bg));
        dists.insert(light-bg);
        dists.insert(ed-light);

        lights.insert(light);
        
        cout << *dists.rbegin() << ' ';
    }

}   



