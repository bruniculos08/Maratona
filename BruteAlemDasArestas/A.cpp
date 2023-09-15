#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> Adj[maxn];
bool vis[maxn];
int dist[maxn];


int main()
{
    int u, v, n, e;

    cin >> n;
    cin >> e;

    for(int i = 0; i < n; i++)
    {
        vis[i] = false;
        dist[i] = maxn;
    } 

    for(int i = 0; i < e; i++)
    {            
        cin >> u >> v;
        Adj[u - 1].push_back(v - 1);
        Adj[v - 1].push_back(u - 1);
    }
    
    int c = 0;
    vector<int> cavalo;
    
    for(int v = 0; v < n; v++)
    {
        if(vis[v]) continue;
        cavalo.push_back(v);
        dfs(v);
        c++;
    }
vector<int> pai;
vector<int> tamanho;
    cout << c - 1 << endl;

    for(int i = 0; i < c - 1; i++)
    {
        cout << cavalo[i] + 1 << " " << cavalo[i + 1] + 1 << endl;
    }

    return 0;
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