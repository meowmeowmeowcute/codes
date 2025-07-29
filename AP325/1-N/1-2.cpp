# include <bits/stdc++.h>
using namespace std;

int fun(){
    string n;
    int x, y, z;
    cin >> n;
    if(n == "f"){
        x = fun();
        return 2*x-3;
    }
    else if (n == "g"){
        x = fun();
        y = fun();
        return 2*x+y-7;
    }
    else if(n == "h"){
        x = fun();
        y = fun();
        z = fun();
        return 3*x-2*y+z;
    }
    else{
        return stoi(n);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fun() << "\n";
}         