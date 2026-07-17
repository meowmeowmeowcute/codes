# include <bits/stdc++.h>
using namespace std;
//# define int long long

// # include <ext/pb_ds/assoc_container.hpp>
// # include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// // Define a balanced tree (PBDS Tree) that supports order statistics (ranking)
// typedef tree<
//     int,                    // Key type
//     null_type,              // Value type : use null_type for a set
//     less<int>,              // Comparison method
//     rb_tree_tag,            // Tree type : Red-Black Tree
//     tree_order_statistics_node_update // Enables order statistics support
// > indexed_set;

# define MAX 200005
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
# define mod 1000000007

# define pii pair<int, int>
# define vi vector<int>
# define vpii vector<pii>

# define pb(...) push_back(__VA_ARGS__)
# define bg(i) i.begin()
# define ed(i) i.end()
# define all(i) bg(i),ed(i)

# define ff first
# define ss second

# define nl cout<<"\n"
# define out(i) cout<<(i)
# define outs(i) cout<<(i)<<" "
# define outl(i) cout<<(i)<<"\n"
# define elif else if

# define set_M() int M = (L+R)/2
# define li 2*id
# define ri 2*id+1

inline int ab(int x) {
    return x >= 0 ? x : -x;
}

string one(string input){
    string output = input;
    for (int i = 0; i<input.length(); i+=2){
        output[i] = input[i+1];
        output[i+1] = input[i];
    }
    return output;
}
string two(string input){
    string output = input;
    for (int i = 0; i<input.length(); i+=2){
        if (input[i]>input[i+1]){
            output[i] = input[i+1];
            output[i+1] = input[i];
        }
    }
    return output;
}
string three(string input){
    string output = input;
    for (int i = 0; i<input.length()/2; i++){
        output[2*i] = input[i];
        output[2*i+1] = input[i+input.length()/2];
    }
    return output;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);    
    string k;
    cin >> k;
    int n;
    cin >> n;
    while(n--){
        int inp;
        cin >> inp;
        if(inp ==0){
            k = one(k);
        }else if (inp == 1){
            k = two(k);
        }else{
            k = three(k);
        }
    }
    cout << k;
};      