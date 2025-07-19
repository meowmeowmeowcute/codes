# include <bits/stdc++.h>
# define mi(a, b) ((a)<(b)?(a):(b))
# define ma(a, b) ((a)>(b)?(a):(b))
# define ab(a) ((a)>=0?(a):-1*(a))
# define int long long
# define MAX 100005
# define err(a) cerr << #a << " : " << a << '\n'
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
# define FKN(I,N) for(int I=1;I<=(N);I++)
# define FKNM(I,N,M) for(int I=(N);I<=(M);I++)
# define set_M() int M = (L+R)/2
# define li 2*id
# define ri 2*id+1
using namespace std;

int n;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    if ((n>2)and !(n%4)or (n-3)%4 == 0){
        cout << "YES\n";
        if (n&1){
            cout << (n+1)/2 ent;
            cout << "1 2 ";
            FKNM(i, 4, 4+(n-3)/4-1)cout << i sps;
            FKNM(i, 4+(n-3)/4*3, n) cout << i sps;
            cout ent << n/2 ent;
            cout << "3 ";
            FKNM(i, 4+(n-3)/4, 4+(n-3)/4*3-1)cout << i sps;
        }else{
            cout << n/2 ent;
            FKNM(i, 1, n/4)cout << i sps;
            FKNM(i, n/4*3+1, n) cout << i sps;
            cout ent << n/2 ent;
            FKNM(i, n/4+1, n/4*3)cout << i sps;
        }
    }else{
        cout << "NO\n";
    }

}   

