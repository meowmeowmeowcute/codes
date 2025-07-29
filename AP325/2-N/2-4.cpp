# include<bits/stdc++.h>
using namespace std;

long long mod_big(string x, long long p){
    long long result = 0;
    for (auto i : x){
        result = (result*10 + (i - '0')) % p;
    }
    return result;
}

long long pow_long(long long x, long long y, long long p){
    if (y == 0) return 1;
    if (y & 1) return (pow_long(x, y-1, p)*x)%p;
    long long pow_n = pow_long(x, y/2, p);
    return (pow_n*pow_n)%p;
}

int main(){
    string x;
    long long y, p;
    cin >> x >> y >> p;
    long long x_ = mod_big(x, p);
    cout << pow_long(x_, y, p);
}