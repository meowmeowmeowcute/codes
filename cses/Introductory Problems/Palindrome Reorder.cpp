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

string a;
int letters[27];
int odd = 0;
int id;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a;
    for(auto i : a)letters[i-'0'-16]+=1;
    FKN(i, 26){
        if (letters[i]&1){
            id = i;
            odd+=1;
        }
    }
    if (odd>1){
        cout <<  "NO SOLUTION";
    }else if (odd){
        FKN(i, 26){
            if (i!=id){
                FKN(j, letters[i]/2)cout << char('A'+i-1);
            }
        }
        FKN(i, letters[id])cout << char('A'+id-1);
        FKN(i, 26){
            int k = ab(27-i);
            if (k!=id){
                FKN(j, letters[k]/2)cout << char('A'+k-1);
            }
        }
    }else{
        FKN(i, 26){
            FKN(j, letters[i]/2)cout << char('A'+i-1);
        }
        FKN(i, 26){
            int k = ab(27-i);
            FKN(j, letters[k]/2)cout << char('A'+k-1);
        }
    }
}   

