# include <bits/stdc++.h>
using namespace std;

long long n, graph[26], total = 0;

void slove(int idx_crr, int inp){
    if (idx_crr>=n){
        if (inp==1){
            total++;
        }
        return;
    }
    slove(idx_crr+1, (inp*graph[idx_crr])%10009);
    slove(idx_crr+1, inp);
    return;
}

int main(){
    cin >>n;
    for (int i = 0; i<n; i++){
        cin >> graph[i];
    }
    slove(0, 1);
    cout << total-1 << endl;
    return 0;
}