# include <bits/stdc++.h>
using namespace std;

string inp;
int odd = 0;
int even = 0;
int idx = 0;

int main(){
    cin >> inp;
    for (auto number : inp){
        if (idx%2 == 0){
            even += number - '0';
        }
        else{
            odd += number - '0';
        }
        idx++;
    }
    cout << abs(even - odd) << endl;
    return 0;
}