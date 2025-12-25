# include <bits/stdc++.h>
using namespace std;

int l, q, graph[(int)1e5];

int bin(int left, int right, int goal){
    //cout << left << " " << right << " " << goal << "\n";
    int idx_c = left;
    for(int jump = (right-left)/2; jump>0; jump>>=1){
        while(idx_c+jump<=right && graph[idx_c+jump]<=goal){
            idx_c += jump;
            //cout << idx_c << "\n";
        }
    }
    if(graph[idx_c]!=goal){
        return 0;
    }
    return idx_c+1;
}

int main (){
    cin >> l >> q;
    for (int i = 0; i<l ;i++){
        cin >> graph[i];
    }
    for (int i = 0; i<q; i++){
        int x;
        cin >> x;
        cout << bin(0, l-1, x) << "\n";
    }
}