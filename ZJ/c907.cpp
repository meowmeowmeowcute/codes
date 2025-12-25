# include <bits/stdc++.h>
using namespace std;

int n, inp, y[10000] = {}, x[10000] = {}, maximum = 0, st_size = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0, j; i < n; i++){
		cin >> inp;
		j = i;
		while(st_size&&y[st_size-1]>inp){
			st_size--;
			maximum = max(maximum, y[st_size]*(i-x[st_size]));
			j = x[st_size];
		}
		if (!st_size||y[st_size-1]<inp){
			y[st_size] = inp;
			x[st_size] = j;
			st_size++;
		}
	}
	while(st_size){
		st_size--;
		maximum = max(maximum, y[st_size]*(n-x[st_size]));
	}
	cout << maximum << "\n";
}
