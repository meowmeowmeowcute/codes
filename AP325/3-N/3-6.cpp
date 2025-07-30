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
            pair<int, int> last  = graph.top();
            while (last.first+last.second<=a[i] and last.first+last.second<=k){
                pair<int, int> last  = graph.top();
                maxi = max(maxi, last.second);
                graph.pop();
                total++;
            }
            if (a[i]-b[i]>=last.first and a[i]-b[i]>=0){
                maxi = max(maxi, b[i]);
                total++;
            }else{
                graph.push({a[i], b[i]});
            }
        }else{
            graph.push({a[i], b[i]});
        }
    }
    cout << total << "\n" << maxi;

}