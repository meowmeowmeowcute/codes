# include <bits/stdc++.h>
using namespace std;
# define MAX 100005


int n, k, a[MAX], b[MAX];
stack<pair<int, int>> graph;
int maxi = 0;
int total = 0;

int main(){
    cin >> n >> k;
    for (int i = 0; i<n; i++)cin >> a[i];
    for (int i = 0; i<n; i++)cin >> b[i];
    for (int i = 0; i<n; i++){
        if (!graph.empty()){
            int lx = graph.top().first;
            int lh = graph.top().second;
            while (lx+lh<=a[i] and lx+lh<=k){
                maxi = max(maxi, lh);
                graph.pop();
                total++;
                if(!graph.empty()){
                    lx = graph.top().first;
                    lh = graph.top().second;
                }else {break;}
            }
        }
        if ( !graph.empty()){
            int lx = graph.top().first;
            int lh = graph.top().second;
            if (a[i]-b[i]>=lx and a[i]-b[i]>=0){
                maxi = max(maxi, b[i]);
                total++;
            }else{
                graph.push({a[i], b[i]});
            }
        }else{
            if (a[i]-b[i]>=0){
                maxi = max(maxi, b[i]);
                total++;
            }else{
                graph.push({a[i], b[i]});
            }
        }
    }
    while(!graph.empty()){
        if(graph.top().first+graph.top().second<=k){
            maxi = max(maxi, graph.top().second);
            graph.pop();
            total++;
        }else{break;}
    }
    cout << total << "\n" << maxi;

}