# include<bits/stdc++.h>
# define long long int
using namespace std;

int y, x, k, graph[100][100];

signed main(){
    int q = 1;
    cin >> y >> x >> k;
    for (int i = 0; i<y; i++){
        for (int j = 0; j<x; j++){
            graph[i][j] = q;
            q++;
        }
    }

    int even = ((k-1)/2+1)%x-1;
    int odd = ((k-1)/2)%y;
    for (int i = 0; i<y; i++){
        for (int j = 0; j<x; j++){
            cout << graph[(i+odd)%y][(j+even)%x] << ' ';
        }
        cout << endl;
    }
}