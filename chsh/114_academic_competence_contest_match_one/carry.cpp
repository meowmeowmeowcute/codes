#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll t, a;

string f(ll a, ll r){
    string ans = "";
    ll t = a;
    for(; t; t /= r){
        if (t % r > 9){
            ans += char('A' + t % r - 10);
        } else {
            ans += char('0' + t % r);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// 排序比較函數
bool compare(const pair<string, ll>& a, const pair<string, ll>& b) {
    if (a.first == b.first) {
        return a.second < b.second; // 如果字典序相同，按基數排序
    }
    return a.first < b.first; // 按照字典序排序
}

int main(){
    cin >> t;
    
    while (t--){
        cin >> a;
        vector<pair<string, ll>> graph;
        int k = 15;
        while (k--){
            graph.push_back({f(a, k + 2), k + 2});
        }
        sort(graph.begin(), graph.end(), compare);
    
        for (auto &[k, v] : graph){
            cout << k << ' ' << v << "\n";
        }
    }
    
    // 使用比較函數來排序

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 將十進位數字 x 轉換為 base 進位的字串
string to_base(long long x, int base) {
    if (x == 0) return "0";
    string digits = "";
    while (x > 0) {
        int rem = x % base;
        if (rem >= 10) digits += (char)('A' + rem - 10);
        else digits += (char)('0' + rem);
        x /= base;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long x;
        cin >> x;

        vector<pair<string, int>> converted;

        for (int base = 2; base <= 16; ++base) {
            string repr = to_base(x, base);
            converted.emplace_back(repr, base);
        }

        // 根據字典序排序，若相同則依 base 升冪排序
        sort(converted.begin(), converted.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        for (auto &[repr, base] : converted) {
            cout << repr << " " << base << "\n";
        }
    }

    return 0;
}
*/