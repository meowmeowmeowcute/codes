# include <bits/stdc++.h>
using namespace std;

int main(){
    int n, inp, longest = 0, last = 0, length = 0;
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> inp;
        if (last < inp){
            longest = max(longest, length);
            length = 1;
        }
        last = inp;
        length++;
    }
    longest = max(longest, length);
    cout << longest-1 << endl;
    return 0;
 
}