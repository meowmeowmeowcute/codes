# include <bits/stdc++.h>
using namespace std;

#define MAX(a,b) ((a>b) ? (a) : (b))

int k, w[1005] = { }, v[1005] = { }, c = 100;

int knapsack(int w[], int v[], int c, int k){
    if (c == 0 || k == 0) return 0;

    if (w[k-1]>c){
        return knapsack(w, v, c, k-1);
    }
    else{
        return MAX(knapsack(w, v, c, k-1), v[k-1] + knapsack(w, v, c-w[k-1], k-1));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while((cin >> k) && !cin.eof()){
        
        for (int i = 0; i < k; i++){
            cin >> w[i];
            cin >> v[i];
        }
        cout << knapsack(w, v, c, k) << "\n";
    }
}