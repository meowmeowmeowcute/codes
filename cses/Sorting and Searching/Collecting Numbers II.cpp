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

vi value(MAX);
vi ids(MAX);

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    

    int n, m;
    cin >> n >> m;
    ids.assign(n+1, 0);
    value.assign(n+1, 0);
    for (int i = 1; i<=n; i++){
        cin >> value[i];
        ids[value[i]] = i;
    }

    int ans = 1;
    for (int i = 1; i<n; i++){
        if(ids[i]>ids[i+1]){
            ans+=1;
        }
    }

    int a, b;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        
        int v_a = value[a];
        int v_b = value[b];
        set<pii> turn;
        if (v_a-1!=0)turn.insert({v_a-1, v_a});
        if (v_a!=n)  turn.insert({v_a, v_a+1});
        if (v_b-1!=0)turn.insert({v_b-1, v_b});
        if (v_b!=n)  turn.insert({v_b, v_b+1});

        for (auto ii : turn){
            int f = ii.ff;
            int s = ii.ss;
            if (ids[f]>ids[s])ans-=1;
        }

        int tmp;
        tmp = value[a];
        value[a] = value[b];
        value[b] = tmp;
        tmp = ids[v_a];
        ids[v_a] = ids[v_b];
        ids[v_b] = tmp;

        for (auto ii : turn){
            int f = ii.ff;
            int s = ii.ss;
            if (ids[f]>ids[s])ans+=1;
        }
        
        cout << ans << "\n";
    }

    

}   



