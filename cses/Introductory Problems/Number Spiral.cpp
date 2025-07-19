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

int n, cy, cx, u, mv;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;

    FKN(i, n){
        cin >> cy >> cx;
        if (cy>cx){
            mv = 1+((cy-1)+1)*(cy-1);
            if (cy&1){
                cout << mv-cy+cx;
            }else{
                cout << mv+cy-cx;
            }
        }
        else if (cy<cx){
            mv = 1+((cx-1)+1)*(cx-1);
            if (cx&1){
                cout << mv+cx-cy;
            }else{
                cout << mv-cx+cy;
            }
        }else{
            cout <<1+((cx-1)+1)*(cx-1);
        }
        cout sps;
    }
    // }
}   

