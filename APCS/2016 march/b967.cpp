#include<bits/stdc++.h>
using namespace std;
int n, fat, son;
vector<int>graph[(int)1e5];
pair<int, int> dfs(int start){
	vector<int> dist(2*n, -1);
	dist[start] = 0;
	stack<int> st;
	st.push(start);
	dist[start] = 1;
	int cur, mind = 0, far = -1;
	while(!st.empty()){
		cur = st.top();
		st.pop();
		for (auto sub : graph[cur]){
			if(dist[sub] == -1){
				dist[sub] = dist[cur]+1;
				st.push(sub);
				if (dist[sub]>mind){
					mind = dist[sub];
					far = sub;
				}
			}
		}
	}
	return {far, mind};
}
int main(){
	cin >> n;
	for(int i= 0; i<n-1; i++){
		cin >> fat >> son;
		graph[fat].push_back(son);
		graph[son].push_back(fat);
	}
	auto [A, _] = dfs(0);
	auto [B, anss] = dfs(A);
	cout << anss-1;

}
