

#include <bits/stdc++.h>
using namespace std;

int dir[(int)2e5+2] = { }; //store changed directory
int graph[(int)2e5+2] = { };
int temp_n;
//bool debug = false; 
/*
void print_dir(){
    for (int i = 1; i <= temp_n; i++){
        cout << i << " : " << dir[i] << "\n";
    }
}
*/
bool par_f(int par, int sub){
    int par_dir = dir[par];
    int sub_dir = dir[sub];

    /*if (debug){
        print_dir();
        cout << "par_f: " << par << "__" << sub << "\n";
        cout << "par_f_dir: " << par_dir << "__" << sub_dir << "\n";
    }*/

    if (graph[sub_dir] == par_dir){
        return true;
    }

    if (dir[graph[sub_dir]] == dir[1]){
        return false;
    }

    if (sub == sub_dir){
        return par_f(par, graph[sub_dir]);
    }
    else{
        return par_f(par, sub_dir);
    }
}


void swap(int *r, int *s)
{
   int temp = *r;
   *r = *s;
   *s = temp;
   return;
} 

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    graph[1] = 1;
    for (int i = 0; i<(2e5+2); i++){
        dir[i] = i;
    }
    int n, par, sub, q, o, x, y;
    cin >> n;
    temp_n = n;
    n-=1;
    while(n--){
        cin >> par >> sub;
        graph[sub] = par;
    }
    cin >> q;
    while(q--){
        cin >> o >> x >> y;
        if (o == 1){
            swap(dir[x], dir[y]);
            /*if (debug){
                print_dir();
            }*/
        }
        else{
            if (par_f(x, y)){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
            }
        }
        /*if (debug){
            cout << "\n";
        }*/
    }
}

/*

*/