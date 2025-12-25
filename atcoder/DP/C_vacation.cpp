# include <bits/stdc++.h>
# define mi(a, b) ((a)<(b)?(a):(b))
# define ma(a, b) ((a)>(b)?(a):(b))
# define ab(a) ((a)>=0?(a):-1*(a))
# define int long long
# define MAX 100005
# define inf 10000000000
# define pii pair<int, int>
# define vi vector<int>
# define vpii vector<pii>
# define ff first
# define ss second
# define T true
# define F false
# define ent << "\n"
# define sps << ' '
# define err(a) cerr << #a << " : " << a sps
# define FKN(I,N) for(int I=1;I<=(N);I++)
# define FKNM(I,N,M) for(int I=(N);I<=(M);I++)
# define set_M() int M = (L+R)/2
# define li 2*id
# define ri 2*id+1
using namespace std;

int n, v[MAX][5], dp[MAX][5], maximum = 0;

pii from[3] = {{2, 3}, {1, 3}, {1, 2}};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n ;
    FKN(y, n){
        FKN(x, 3){
            cin >> v[y][x];
        }
    }
    dp[1][1] = v[1][1];
    dp[1][2] = v[1][2];
    dp[1][3] = v[1][3];
    FKNM(y, 2, n){
        FKN(x, 3){
            dp[y][x] = ma(v[y][x]+dp[y-1][from[x-1].ff], v[y][x]+dp[y-1][from[x-1].ss]);
        }
    }
    FKNM(i, 1, 3){
        maximum = ma(maximum, dp[n][i]);
    }
    cout << maximum;
}


