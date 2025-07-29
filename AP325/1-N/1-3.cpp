# include <bits/stdc++.h>
using namespace std;

int cuts[(int)5e4+5];

long long cut(int left, int right){
    //cout << left << " " << right << endl;
    if (right-left <= 1) return 0;
    int k = left;
    long long mid = (cuts[left] + cuts[right])/2;
    for (int jump = (right - left)/2; jump > 0; jump>>=1){
        while(k+jump<right && cuts[k+jump]<mid){
            k+=jump;
        }
    }
    if(cuts[k]-cuts[left] < cuts[right]-cuts[k+1]){
        k++;
    }
    return cuts[right]- cuts[left] + cut(left, k) + cut(k, right);
}


int main(){
    long long n, l;
    cin >> n >> l;
    cuts[0] = 0;
    cuts[n+1] = l;
    for (int i = 1; i <= n; i++){
        cin >> cuts[i];
    }
    cout << cut(0, n+1);
}