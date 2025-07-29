# include <bits/stdc++.h>
using namespace std;

long long n, k, graph[26], maximum = 0;

void slove(long long idx_crr, long long inp){
    if(idx_crr <= n)
        if (inp<=k){
            maximum = max(maximum,inp);
            cout<< maximum << endl;
            slove(idx_crr+1, inp+graph[idx_crr]);
            slove(idx_crr+1, inp);
            return;
        }
        else{
            return;
        }
    
}

int main(){
    cin >>n>>k;
    for (int i = 0; i<n; i++){
        cin >> graph[i];
    }
    slove(0, 0);
    cout << maximum << "\n";
    return 0;
}