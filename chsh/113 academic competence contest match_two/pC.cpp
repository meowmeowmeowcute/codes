# include <bits/stdc++.h>
using namespace std;

int n, input_i, total = 0, maximum = 0;
bool candy_got[(int)1e9+1];
string input_line;
stringstream input_ss;
deque<int> graph;

int main (){
    cin >> n;
    cin.ignore();
    getline(cin, input_line);
    input_ss << input_line;
    while(input_ss>>input_i){
        if (candy_got[input_i]){
            while(graph.front() != input_i){
                candy_got[graph.front()] = false;
                graph.pop_front();
                total--;
            }
            graph.pop_front();
            total--;
        }
        graph.push_back(input_i);
        candy_got[input_i] = true;
        total++;
        maximum = max(maximum, total);
    }
    cout << maximum;
    return 0;

}