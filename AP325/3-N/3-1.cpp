# include <bits/stdc++.h>
# define ll long long
using namespace std;

vector<int> graph[(int)1e5+5];
int n, h[(int)1e5+5], k, inp, maximum = 0;

int update(int father){
    int total = 0;
    int mh = 0;
    for(int son : graph[father-1]){
        if (h[son-1] == -1){
            total += update(son) + h[son-1];
        }else{
            total += 
        }
    }   
}

int main(){
    memset(h, -1, sizeof(h));
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> k;
        if (k){
            for (int j = 0; j<k; j++){
                cin >> inp;
                graph[i].push_back(inp);
            }
        }else{
            h[i] = 0;
        }
    }

    for (int i = 0; i<n; i++){
        for(int pot : graph[i]){
            if (h[pot-1] == -1)
        }
    }
}