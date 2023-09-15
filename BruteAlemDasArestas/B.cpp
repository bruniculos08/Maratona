#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
vector<int> Adj[maxn];
int dist[maxn];

void subordinados(int v)
{
    return 
}

void bfs(int u)
{
    queue<int> around;
    around.push(u);
    dist[u] = 0;
    while(!around.empty())
    {
        int u = around.front();
        around.pop();
        for(int v : Adj[u])
        {
            if(dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                around.push(v);
            }
        }
    }
}

int main()
{
    int u, n;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        sub[i] = 0;
        pai[i] = i;
        dist[i] = maxn;
    } 

    for(int i = 1; i < n; i++)
    {            
        cin >> u;
        Adj[u - 1].push_back(i);
        Adj[i].push_back(u - 1);
        pai[i] = u - 1;
    }

    bfs(0);

    for(int i = 0; i < n; i++)
    {
        cout << sub[i] << " ";
    }

    return 0;
}
