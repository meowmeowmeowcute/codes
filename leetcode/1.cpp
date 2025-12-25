#include <bits/stdc++.h>
#define mi(a, b) ((a) < (b) ? (a) : (b))
#define ma(a, b) ((a) > (b) ? (a) : (b))
#define ab(a) ((a) >= 0 ? (a) : -1 * (a))
#define int long long
#define MAX 100005
#define err(a) cerr << #a << " : " << a << '\n'
#define inf 10000000000
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define ff first
#define ss second
#define T true
#define F false
#define ent << "\n"
#define sps << ' '
#define FKN(I, N) for (int I = 1; I <= (N); I++)
#define FKNM(I, N, M) for (int I = (N); I <= (M); I++)
#define set_M() int M = (L + R) / 2
#define li 2 * id
#define ri 2 * id + 1
using namespace std;

char _;
int inp, id = 0;
vpii a;

bool compare(const pii &a, const pii &b) {
    return a.ff < b.ff;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> _;
    while (_ != ']') {
        cin >> inp >> _;
        a.push_back({inp, id++});
    }
    cin >> inp;
    sort(a.begin(), a.end());

    for(pii i : a){
        err(i.ff);err(i.ss);
    }

    FKN(i, id) {
        auto it = lower_bound(a.begin() + i - 1, a.end(), pii({inp-a[i-1].ff, a[i-1].ss}), compare);
        if (a[(it - a.begin())].ff+a[i-1].ff == inp){
            cout << '[' << a[i-1].ss << ',' << a[it-a.begin()].ss << ']';
            return 0;
        }
    }
}
