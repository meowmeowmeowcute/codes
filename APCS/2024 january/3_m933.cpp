# include <bits/stdc++.h>
using namespace std;

struct point{
    vector<int> from;
    int level = -1;
    int type = -1;
    int val = -1;
    int id = -1;
};

deque<point> dq;
vector<point> graph;
int input = 0, gate = 0, output = 0, link = 0, par = 0, sub = 0;
vector<int> answer = { };
set<int> maximum = { };

void BFS(){
    while(!dq.empty()){
        bool next = 0;
        point above = dq.front();
        for(auto ele:above.from){
            if (graph[ele-1].val==-1){
                dq.pop_front();
                dq.push_back(above);
                next = 1;
                break;
            }
        }
        if(next){continue;}
        int ab_ff = above.from[0]-1;
        int ab_ft = above.from[1]-1;
        if (above.type == -1){
            above.val = graph[ab_ff].val;
        }
        else if (above.type == 1){
            above.val = (graph[ab_ff].val&graph[ab_ft].val);
        }
        else if (above.type == 2){
            above.val = (graph[ab_ff].val|graph[ab_ft].val);
        }
        else if (above.type == 3){
            above.val = (graph[ab_ff].val^graph[ab_ft].val);
        }
        else if (above.type == 4){
            above.val = (!graph[ab_ff].val);
        }

        if(above.type ==  4){
            above.level = graph[ab_ff].level+1;
        }
        else{
            above.level = max(graph[ab_ff].level, graph[ab_ft].level)+1;
        }

        graph[above.id-1] = above;
        dq.pop_front();
        if (above.val==-1){
            dq.push_back(above);
        }
    }
}

int main(){
    cin >> input >> gate >> output >> link;
    for (int i = 1; i<=input+gate+output; i++){
        point tmp;
        tmp.id = i;
        graph.push_back(tmp);
    }
    for (int i = 0; i<input; i++){
        cin >> graph[i].val;
        graph[i].level = 0;
    }
    for (int i = input; i<input+gate; i++){
        cin >> graph[i].type;
    }
    for (int i = 0; i<link; i++){
        cin >> par >> sub;
        graph[sub-1].from.push_back(par);
    }
    for (int i = 0; i<input+gate+output; i++){
        if (graph[i].val == -1){
            dq.push_back(graph[i]);
        }
    }
    BFS();
    for(int i = input+gate; i<input+gate+output; i++){
        answer.push_back(graph[i].val);
        maximum.insert(graph[i].level);
    }
    cout << *(maximum.rbegin())-1 << "\n";
    for (int i:answer){
        cout << i << ' ';
    }
}
