# include <bits/stdc++.h>
using namespace std;

int MAX = (int)1e5+2;
int levels[MAX] = { };
vector<int> graph[MAX] = { };


int main() {
    int n, parent, child;
    cin >> n;
    n-=1;
    while (n--)
    {
        cin >> parent >> child;
        graph[parent].push_back(child);
    }
    
}