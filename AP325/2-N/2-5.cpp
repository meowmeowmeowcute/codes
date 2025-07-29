# include<bits/stdc++.h>
# define ll long long
using namespace std;

struct arr{
    ll arr[4] = {1, 1, 1, 0};
};
struct arr base_arr;

struct arr arr_mult(struct arr arr_a, struct arr arr_b, ll p){
    struct arr port;
    port.arr[0] = (arr_a.arr[0]*arr_b.arr[0] + arr_a.arr[1]*arr_b.arr[2])%p;
    port.arr[1] = (arr_a.arr[0]*arr_b.arr[1] + arr_a.arr[1]*arr_b.arr[3])%p;
    port.arr[2] = (arr_a.arr[2]*arr_b.arr[0] + arr_a.arr[3]*arr_b.arr[2])%p;
    port.arr[3] = (arr_a.arr[2]*arr_b.arr[1] + arr_a.arr[3]*arr_b.arr[3])%p;
    return port;
}
struct arr pow_arr(struct arr arr, ll times, ll p){
    if (times == 0 || times == 1) return base_arr;
    else if (times & 1) return arr_mult(pow_arr(arr, times-1, p), base_arr, p)
    struct arr arr_result = pow_arr(arr, times/2, p);
    return arr_mult(arr_result, arr_result, p);
}

signed main(){
    ll n;
    struct arr k;
    while(cin >> n && n!=-1){
        k = pow_arr(base_arr, n-1, 1000000007); 
        cout << k.arr[0] << "\n";  // 0th element of the pow_arr result is the nth Fibonacci number. 0-indexed.
    }
}