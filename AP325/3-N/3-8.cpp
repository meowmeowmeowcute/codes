# include<bits/stdc++.h>
# define MAX 200005
using namespace std;

deque<int> mis, mas;
int graph[MAX], n, l, ans = 0;


void chkma(int idx){
    while(!mas.empty() and graph[mas.back()]<graph[idx]){
        mas.pop_back();
    }
    mas.push_back(idx);
}
void chkmi(int idx){
    while(!mis.empty() and graph[mis.back()]>graph[idx]){
        mis.pop_back();
    }
    mis.push_back(idx);
}
int main (){
    cin >> n>> l;
    for (int i = 0; i<n; i++){
        cin >> graph[i];
    }
    chkma(0);
    chkmi(0);
    for (int i = 1; i<n ;i++){
        if(mas.front()<=i-l){
            mas.pop_front();
        }
        chkma(i);
        if (mis.front()<=i-l){
            mis.pop_front();
        }
        chkmi(i);
        int diff = graph[mas.front()]-graph[mis.front()];
        ans = max(ans, diff);
    }
    cout << ans ;
}