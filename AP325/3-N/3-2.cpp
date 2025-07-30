# include <bits/stdc++.h>

using namespace std;
string str;
char last;
deque<int>graph;
map<char, char> con;

int main(){
    con['{'] = '}';
    con['['] = ']';
    con['('] = ')';

    while(cin >> str){
        int l = str.size();
        for(int i = l-1; i>=0; i--){
            if (!graph.empty()){
                last = graph.front();
            }
            else{
                last = 'P';
            }
            graph.push_front(str[i]);
            if (con[graph.front()] == last){
                graph.pop_front();
                graph.pop_front();
            }
        }
        if (!graph.empty()){
            cout << "no\n";
        }
        else{
            cout << "yes\n";
        }
        graph.clear();
    }
    
}