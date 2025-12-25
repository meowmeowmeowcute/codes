# include <bits/stdc++.h>
using namespace std;

int main(){
    int n, first = 0, second = 0, id; cin >> n;
    int attack[n], defance[n], bility[n];
    for (int i = 0; i < n; i++) cin >> attack[i] >> defance[i];
    for (int i = 0; i < n; i++) bility[i] = defance[i]*defance[i]+attack[i]*attack[i];
    for (int i = 0; i < n; i++){
        if(first < bility[i]) first = bility[i];
    }
    for (int i = 0; i < n; i++){
        if(second < bility[i] && bility[i]!=first){
            second = bility[i];
            id = i;
        }
    }
    cout << attack[id] << " " << defance[id];
}