# include<bits/stdc++.h>
# define int long long
# define lid id<<1
# define rid (id<<1)+1
using namespace std;

const int N = 5e5+5;
int arr[N];
int seg[N<<2];
int n, M;
void build(int l, int r, int id){
    if (l == r){
        //cout << id << "  " << l << "\n";
        seg[id] = arr[l];
        return;
    }
    int m = (l+r)>>1;
    build(l, m, lid);
    build(m+1, r, rid);
    seg[id] = max(seg[lid], seg[rid]);
}

int query(int l, int r, int L = 0, int R = n-1, int id = 1){
    if (l>R || r<L)return 0;
    if (l<=L&&r>=R)return seg[id];
    int m = (L+R)>>1;
    if (r<=m)return query(l, r, L, m, lid);
    if (l>m)return query(l, r, m+1, R, rid);
    return max(query(l, m, L, m, lid), query(m+1, r, m+1, R, rid));
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    build(0, n-1, 1);
    cin >> M;
    for(int i = 0; i<M; i++){
        int a, b;
        cin >> a >> b;
        if (a>b)swap(a, b);
        a--;b--;
        cout << query(a, b) << "\n";
    }

}