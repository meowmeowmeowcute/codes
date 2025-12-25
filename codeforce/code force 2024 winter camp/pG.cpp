# include <bits/stdc++.h>
using namespace std;

set <int> ls;

int q, k, number;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> q;
    while((cin >> k) && !cin.eof() && q--) {
        switch(k){
            case 1:
                cin>>number;
                ls.insert(number);
                break;
            case 2:
                cin >> number;
                if (ls.count(number)){
                    cout << "1\n";
                }
                else{
                    cout << "0\n";
                }
                break;
            case 3:
                if (!ls.empty()){
                    cout << *ls.begin() << "\n";
                    ls.erase(ls.begin());
                }
                else{
                    cout << "-1\n";
                }
                break;
        }
    }
}