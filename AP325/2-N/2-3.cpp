# include<bits/stdc++.h>
using namespace std;

long long pow_long(long long x, long long y, long long p){
    if (y == 0) return 1;
    if (y & 1) return (pow_long(x, y-1, p)*x)%p;
    long long pow_n = pow_long(x, y/2, p);
    return (pow_n*pow_n)%p;

}

int main(){
    int x, y, p;

    cin >> x >> y >> p;
    cout << pow_long(x, y, p);
}