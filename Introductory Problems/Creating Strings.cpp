#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end()); 
    set<string> perms;        

    do {
        perms.insert(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << perms.size() << '\n';
    for (const auto &str : perms) {
        cout << str << '\n';
    }
}
