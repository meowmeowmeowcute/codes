# include <bits/stdc++.h>
using namespace std;
# define MAX 200005

int main (){
    int n, k, l = 0, r = 0, graph[MAX], appear[MAX], cls=0, ans =0;
    cin >> n >> k;
    for (int i = 0; i<n; i++){
        cin >> graph[i];
    }
    while(r<n){
        if (l<=r-k){
            appear[graph[l]]--;
            if (appear[graph[l]] == 0){
                cls--;
            }
            l++;
        }

        appear[graph[r]]++;
        if (appear[graph[r]] == 1){
            cls++;
        }
        ans = max(cls, ans);
        r++;
    }
    cout << ans;

}