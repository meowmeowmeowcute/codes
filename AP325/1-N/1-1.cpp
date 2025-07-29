
/*
# include <bits/stdc++.h>
using namespace std;

int fun(){
    string n;
    int x, y;
    cin >> n;
    if(n == "f"){
        x = fun();
        return 2*x-1;
    }
    else if (n == "g"){
        x = fun();
        y = fun();
        return x+2*y-3;
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
*/
# include <bits/stdc++.h>
using namespace std;
stack<string> graph;
int main() {
    string n;
    while(cin >> n && n != "0"){
        graph.push(n);
    }
    stack<int> values; 
    while (!graph.empty()) {
        string top = graph.top();
        graph.pop();
        if (top == "f") {
            int x = values.top();
            values.pop();
            values.push(2*x-1);
        } else if (top == "g") {
            int x = values.top();
            values.pop();
            int y = values.top();
            values.pop();
            values.push(x+2*y-3);
        } else {
            values.push(stoi(top));
        }
    }
    cout << values.top() << endl;
}
