# include <bits/stdc++.h>
using namespace std;

int n, graph[15][15], maximum = 0, used[15];//used -> used[x] = y

void slove(int y_idx, int used[], int val){
//    cout << "y_idx: " << y_idx << ", val:" << val << endl;
    if (y_idx == n){
        maximum = max(maximum, val);
        return;
    }

    for (int x_crr = 0; x_crr < n; x_crr++){

        

        if (used[x_crr] == -1){
            bool allowed = true;
            for(int x_test = 0; x_test < n; x_test++){
                if (x_crr != x_test && used[x_test] != -1){
                    if (used[x_test] - x_test == y_idx - x_crr){
//                        cout << "right down\n";
                        allowed = false;
                        break;
                    }
                    if (used[x_test] + x_test == y_idx + x_crr){
                        allowed = false;
//                        cout << "left down\n";
                        break;
                    }
                }
            }
            if (allowed){
                used[x_crr] = y_idx;
                slove(y_idx+1, used, val+graph[y_idx][x_crr]);
                used[x_crr] = -1; //backtrack
            }
        }

    }
    slove(y_idx+1, used, val);
    return;
}

int main(){
    fill(used, used+15, -1);
    cin >> n;
    for (int y = 0; y < n; y++){
        for (int x = 0; x < n; x++){
            cin >> graph[y][x];
        }
    }
    slove(0, used, 0);
    cout << maximum << "\n";
    return 0;
}

/*
3
1 4 2
5 3 2
7 8 5
 */