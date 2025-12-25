#include <bits/stdc++.h>
using namespace std;

int n, m, q;
const int MAX = 1e7 + 5;
int par[MAX], sz[MAX];
bool is_at[MAX];
int max_area = 0;

int idx(int y, int x)
{
    return y * m + x;
}

int find(int x)
{
    return x == par[x] ? x : par[x] = find(par[x]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    par[a] = b;
    sz[b] += sz[a];
    max_area = max(max_area, sz[b]);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    string row;
    for (int i = 0; i < n * m; i++)
    {
        par[i] = i;
        sz[i] = 1;
        is_at[i] = false;
    }

    for (int y = 0; y < n; y++)
    {
        cin >> row;
        for (int x = 0; x < m; x++)
        {
            if (row[x] == '@')
            {
                int id = idx(y, x);
                is_at[id] = true;
                for (int d = 0; d < 4; d++)
                {
                    int ny = y + "2011"[d] - '1'; 
                    int nx = x + "1120"[d] - '1';
                    if (ny >= 0 && ny < n && nx >= 0 && nx < m)
                    {
                        int nid = idx(ny, nx);
                        if (is_at[nid]) unite(id, nid);
                    }
                }
                max_area = max(max_area, 1); 
            }
        }
    }

    cin >> q;
    while (q--)
    {
        int y, x; cin >> y >> x;
        int id = idx(y, x);
        if (is_at[id])
        {
            cout << max_area << "\n";
            continue;
        }
        is_at[id] = true;
        for (int d = 0; d < 4; d++)
        {
            int ny = y + "2011"[d] - '1';
            int nx = x + "1120"[d] - '1';
            if (ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                int nid = idx(ny, nx);
                if (is_at[nid]) unite(id, nid);
            }
        }
        cout << max_area << "\n";
    }
}
