# include <bits/stdc++.h>
using namespace std;

int main(){

    bool best = false;
    bool worst = false;
    int n;
    int high = 1000;
    int low = 0;
    int ls[(int)1e4] = { };
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> ls[i];
        if (ls[i]>=60){
            best = true;
            if (ls[i]<high){
                high = ls[i];
            }
        }
        if (ls[i]<60){
            worst = true;
            if (ls[i]>low){
                low = ls[i];
            }        
        }
        
    }
    
    sort(ls, ls + n);
    
    for(int i = 0; i<n; i++){
        cout << ls[i] << " " ;
    }
    cout << "\n";

    if(worst && !best){
        cout << low << "\n";
        cout << "worst case\n"; 
    }
    else if(!worst && best){
        cout << "best case\n";
        cout << high << "\n";
    }
    else if(worst && best){
        cout << low << "\n" << high << "\n";
    }
    

}