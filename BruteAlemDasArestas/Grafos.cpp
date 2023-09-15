#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> Adj[maxn];
bool vis[maxn];
int dist[maxn];
vector<int> pai;
vector<int> tamanho;

void dfs(int u){
    vis[u] = true;
    for(int v : Adj[u]){
        if(vis[v]) continue;
        dfs(v);
    }
}

void dfstunado(int u, int x){
    vis[u] = true;
    if(u == x) return;
    for(int v : Adj[u]){
        if(vis[v]) continue;
        dfs(v);
    }
}

int main(){
    int u, v, n, e;
    cin >> n;
    cin >> e;
    for(int i = 0; i < n; i++){
        vis[i] = false;
        dist[i] = maxn;
    } 

    for(int i = 0; i < e; i++){            

        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    int x;
    cin >> x;
    dfstunado(1, x);
    if(vis[x]) cout << "WALTER" << endl;
    else cout << "NOT WALTER" << endl;
    return 0;
}

void bfs(int u){
    queue<int> around;
    around.push(u);
    dist[u] = 0;
    while(!around.empty()){
        int u = around.front();
        around.pop();
        for(int v : Adj[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                around.push(v);
            }
        }
    }
}

void inicializadsu(int n){
    for(int i = 0; i < n; i++){
        pai[i] = i;
        tamanho[i] = 0;
    }
}

int find(int a){
    if(pai[a] == a) return a;
    else find(pai[a]);
}

void uniao(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    
    if(tamanho[a] >= tamanho[b]) swap(a, b);

    //Adj[a].push(b);
    //Adj[b].push(a);
    pai[b] = a;
    tamanho[a] += tamanho[b];

}