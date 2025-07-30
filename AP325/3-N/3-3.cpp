# include<bits/stdc++.h>
using namespace std;

stack <int> nu;
stack <char> ops;
string str;
int ans = 0;
int f(int a, int b, char c){
    if(c == '-'){
        return a-b;
    }else if (c == '+'){
        return a+b;
    }else if (c == '*'){
        return a*b;
    }else if (c == '/'){
        return a/b;
    }
    return false;
    
}

int check(char a){
    if (a == '*' or a == '/'){
        return 2;
    }else if (a == '-' or a == '+'){
        return 1;
    }else {
        return 0;
    }
}

void func(){
    int a = nu.top();
    nu.pop();
    int b = nu.top();
    nu.pop();
    int k = f(b, a, ops.top());
    nu.push(k);
    ops.pop();
}

int main(){
    cin >>str;
    int l = str.size();
    for (int i = 0; i<l; i++){
        int tp= check(str[i]);
        if (tp ==0){
            nu.push(str[i]-'0');
        }
        else {
            while (!ops.empty() and check(str[i])<=check(ops.top())){
                func();
            }
            ops.push(str[i]);
        }
    }
    while(!ops.empty()){
        func();
    }
    cout << nu.top() << "\n";
    nu.pop();
    
}