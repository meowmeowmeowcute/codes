# include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, p, inp;

ll pow_long(ll x, ll y, ll p){
    if (y == 0) return 1;
    if (y & 1) return (pow_long(x, y-1, p)*x)%p;
    ll pow_n = pow_long(x, y/2, p);
    return (pow_n*pow_n)%p;
}

int main(){
    cin >> n >> p;
    for (int i = 0; i < n; i++){
        cin >> inp;
        cout << pow_long(inp, p-2, p) << ' ';
    }
    return 0;
}