# include <bits/stdc++.h>

# define MAX 200000
# define inf 100000000000000000
# define mod 1000000007

# define pii pair<int32_t, int32_t>
# define vi vector<int>
# define vpii vector<pii>

#define pb(...) push_back(__VA_ARGS__)
#define bg(i) i.begin()
#define ed(i) i.end()
#define all(i) bg(i),ed(i)

# define ff first
# define ss second

#define __overload_for__(i,j,k,l,m,...) m
#define FN_(i) FNN(_, i)
#define FNN(i,j) for(int i = 1;i<=j;i++)
#define FNAT(i,j) for(auto &i : j)
#define FNNM(i,j,k) for(int i = j;i<=k;i++)
#define FNNMQ(i, j, k, l) for (int i = j; i<=k; i=i+l)
#define FN(...) __overload_for__(__VA_ARGS__,FNNMQ,FNNM,FNN, FN_)(__VA_ARGS__)

#define nl cout<<"\n"
#define out(i) cout<<(i)
#define outs(i) cout<<(i)<<" "
#define outl(i) cout<<(i)<<"\n"
#define elif else if

# define set_M() int M = (L+R)/2
# define li 2*id
# define ri 2*id+1

using namespace std;

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

const int bullet_type[8][2]= {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
struct p{
    int x;int y;int dir;
    bool entered = false;
    bool run = false;
};

inline bool in_map(int y, int x){
    if(y>=0 and y<=4 and x>=0 and x<=4){
        return true;
    }
    return false;
}

int n, k, m, l;
int game_map[5][5];
p b[MAX];
int bullet_runs = 0;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    game_map[2][2] = 1;

    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> b[i].dir >> b[i].x >>b[i].y;
        if(in_map(b[i].y, b[i].x)){
            b[i].entered = true;
            game_map[b[i].y][b[i].x] = -1;
        }
    }
    while(bullet_runs<n){
        queue<pii> bfs;
        for(int y = 0; y<5; y++){
            for(int x = 0; x<5; x++){
                if(game_map[y][x]==1){
                    bfs.push({y+1, x});
                    bfs.push({y, x+1}); 
                    bfs.push({y-1, x}); 
                    bfs.push({y, x-1});
                }
            }
        }

        if (bfs.empty()){
            outl(0);
            return 0;
        }

        while(!bfs.empty()){
            int y = bfs.front().ff;int x = bfs.front().ss;
            bfs.pop();
            if(in_map(y, x)and game_map[y][x] == 0)game_map[y][x] =  1;
        }

        for(int y = 0; y<5; y++){
            for(int x = 0; x<5; x++){
                if(game_map[y][x] == -1)game_map[y][x] = 0;
            }
        }

        for(int i = 1; i<=n; i++){
            if(!b[i].run){
                b[i].x+=bullet_type[b[i].dir][0];
                b[i].y+=bullet_type[b[i].dir][1];
                if(in_map(b[i].y, b[i].x)){
                    b[i].entered = true;
                    game_map[b[i].y][b[i].x] = -1;
    
                }else if (b[i].entered){
                    b[i].run = true;
                    bullet_runs++;
                }
            }

        }

        
    }
    outl(1);
    return 0;
}   

