# include <bits/stdc++.h>
using namespace std;

set<string> dict_all, dict_part;
string k, s; int l;

void generate_dict(string result){
    string new_result;
    for(int i=0; i<k.length(); i++){
        new_result=result+k[i];
        if(new_result.length()==l){
            dict_all.insert(new_result);
            continue;
        }
        generate_dict(new_result);
    }
}

int main(){
    cin >> k >> l >> s;
    generate_dict("");
    for(int i=0; i<s.length()-l+1; i++){
        dict_part.insert(s.substr(i, l));
    }
    for(auto i : dict_all){
        if(!dict_part.count(i)){
            cout << i << '\n';
            break;
        }
    }
}