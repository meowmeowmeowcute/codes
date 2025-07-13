# include <bits/stdc++.h>
# define mi(a, b) ((a)<(b)?(a):(b))
# define ma(a, b) ((a)>(b)?(a):(b))
# define ab(a) ((a)>=0?(a):-1*(a))
# define int long long
# define MAX 200005
# define inf 10000000000
# define mod 1000000007
# define pii pair<int, int>
# define vi vector<int>
# define vpii vector<pii>
# define ff first
# define ss second
# define T true
# define F false
# define err(a) cerr << #a << " : " << a << '\n'
# define ent << "\n"
# define sps << ' '
# define FKN(I,N) for(int I=1;I<=(N);I++)
# define FKNM(I,N,M) for(int I=(N);I<=(M);I++)
# define set_M() int M = (L+R)/2
# define li 2*id
# define ri 2*id+1
using namespace std;

int n, m, k, id = 1, ans = 0;
int applicants[MAX], apartments[MAX];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    FKN(i, n)cin >> applicants[i];
    FKN(i, m)cin >> apartments[i];
    sort(applicants+1, applicants+n);
    sort(apartments+1, apartments+m);
    FKN(i, n){
        if(apartments[i]+k>= applicants[i] and applicants[i] >= apartments[i]-k){
            ans++;
            id+=1;
        }
        if(apartments[i]+k<= applicants[i])id++;
    }
    FKN(i, n)
    cout << ans;
}   

