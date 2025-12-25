# include <bits/stdc++.h>
using namespace std;

long long slove (int root){
    int k;
    long long total = 0;
    long long tmp;
    if ((root%2)){ //©_¼Æ
        for(int i = 0; i<3; i++){
            cin >> k;
            if (k == 0) return 0;
            total += abs(root-k);
            tmp = slove(k);
            total += tmp;
        }
    }
    else{
        for(int i = 0; i<2; i++){
            cin >> k;
            if (k == 0) return 0;
            total += abs(root-k);
            tmp = slove(k);
            total += tmp;
        }
    }
    cout<< "root = " << root << endl;
    cout << "total = " << total << endl;
    return total;
}

int main(){
    int j;
    long long ans;
    cin >> j;
    ans = slove(j);
    cout << ans << endl;
    return 0;
}


