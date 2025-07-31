# include <bits/stdc++.h>
# define int long long 
# define MAX 200005
using namespace std ;

# define pii pair<int, int> 

template<typename T>
inline int ab(int x) {
    return x >= 0 ? x : -x;
}
template<typename T>
inline T mi(T a, T b) {
    return a < b ? a : b;
}
template<typename T>
inline T ma(T a, T b) {
    return a > b ? a : b;
}

//better io
#ifdef cin
template<class T>
__fast_read& operator>>(__fast_read& fin,vector<T>&f) {
    for(auto &&i : f) fin>>i;
    return fin;
}
template<class T,class R>
__fast_read& operator>>(__fast_read& fin,pair<T,R>&x) {
    fin>>x.first>>x.second;
    return fin;
}
#else
template<class T>
std::istream& operator>>(std::istream& fin,std::vector<T>&f) {
    for(auto &&i : f) fin>>i;
    return fin;
}
template<class T,class R>
std::istream& operator>>(std::istream& fin,std::pair<T,R>&x) {
    fin>>x.first>>x.second;
    return fin;
}
#endif
template<class T>
std::ostream& operator<<(std::ostream& fout,std::vector<T>&f) {
    for(auto &i : f) fout<<i<<" ";
    return fout;
}
template<class T,class R>
std::ostream& operator<<(std::ostream& fout,std::pair<T,R>&x) {
    fout<<x.first<<" "<<x.second;
    return fout;
}



int ans = 0;
int n, inp;
int a[MAX], b[MAX];
vector <pii> graph;
signed main(){
    cin >> n;
    for (int i = 0; i<n; i++) cin>> a[i];
    for (int i = 0; i<n; i++) cin>> b[i];
    for (int i = 0; i<n; i++) b[i]+=a[i];
    for (int i = 0; i<n ;i++){
        if (!graph.empty()){
            int l = 0, r = graph.size();
            while(l<=r){
                int m = (l+r)/2;
                if (m == 0 and graph[0].first<b[i]){
                    ans+=i;
                    break;
                }
                if (graph[m]>)
            }




            while(!graph.empty() and graph.front().first<=a[i]){
                cout << graph.front() << "\n";
                graph.pop_back();
            }
        }
        if (!graph.empty()and b[i]<graph.front().first){
            ans+=i-graph.front().second-1;
        }
        else{
            ans+=i;
        }
        cout << "ans : "  << ans << "\n";
        graph.push_back({a[i], i});
    }
    cout << ans << "\n";
}