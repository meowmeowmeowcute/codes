# include <bits/stdc++.h>
using namespace std;

string inp;
int width;
int idx = 0;
int total = 0;

void counter(int w){
    //cout << "counter: " << w << endl;
    char str = inp[idx];
    idx++;
    if (str == '2'){
        for (int i = 0; i <4; i++){
            counter(w/2);   
        }
    }
    else if (str == '1'){
        total+= (w)*(w);
        //cout << "total: " << total << endl;
    }
}

int main() {
    cin >> inp >> width;
    counter(width);
    cout << total << endl;
    return 0;
}