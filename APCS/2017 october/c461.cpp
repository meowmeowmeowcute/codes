# include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, ans, flag = 0;
    cin >> a >> b >> ans;
    if ((a && b)==ans){
		cout << "AND\n";
		flag = 1;
    }
    if ((a || b) == ans){
		cout << "OR\n";
		flag = 1;
    }
    if (a^b== ans){
		cout << "XOR\n";
		flag = 1;
    }
    if(!flag){
		cout << "IMPOSSIBLE";
    }
}
